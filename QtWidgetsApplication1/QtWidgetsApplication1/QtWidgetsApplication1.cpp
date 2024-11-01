#include "QtWidgetsApplication1.h"
#include "worker.h"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <vector>
#include <Qtimer.h>
#include <QDebug>//由于要用到qDebug()函数，故要添加库函数
using namespace cv;

//为了方便调试代码，声明了一个全局变量
Mat img = imread("D:\\桌面\\梁相儒\\生活照\\1.jpg", IMREAD_COLOR);

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
    //connect(控件, 触发方式, this, 触发的槽函数);
    connect(ui.ReadImg, &QPushButton::clicked, this, &QtWidgetsApplication1::on_action_Button_ReadImg_clicked);
    connect(ui.HistAna, &QPushButton::clicked, this, &QtWidgetsApplication1::on_action_Button_HistAna_clicked);
    connect(ui.Threshold, &QPushButton::clicked, this, &QtWidgetsApplication1::on_action_Button_Threshold_clicked);
    connect(ui.ThresholdValue, &QSlider::sliderMoved, this, &QtWidgetsApplication1::on_action_Slider_ThresholdValue_edited);
    connect(ui.Multiline, &QPushButton::clicked, this, &QtWidgetsApplication1::on_action_Button_Multiline_clicked);
    
    //设置多线程
    //定义5个work实例
    worker* work1 = new worker;
    worker* work2 = new worker;
    worker* work3 = new worker;
    worker* work4 = new worker;
    worker* work5 = new worker;
    //将启动信号的起始值传递给实例，并开始dowork
    connect(this, &QtWidgetsApplication1::operate1, work1, &worker::dowork);//operate信号发射后，启动读取
    //5个线程并行进行，故只需要显示一个线程的进度，且一个进程结束即代表整个过程结束
    connect(work1, &worker::workpercent, this, &QtWidgetsApplication1::updateProgressbar); // 显示读取进度 
    connect(work1, &worker::workdone, this, &QtWidgetsApplication1::Finished);    //过程结束
    connect(this, &QtWidgetsApplication1::operate2, work2, &worker::dowork);
    connect(this, &QtWidgetsApplication1::operate3, work3, &worker::dowork);
    connect(this, &QtWidgetsApplication1::operate4, work4, &worker::dowork);
    connect(this, &QtWidgetsApplication1::operate5, work5, &worker::dowork);

    //将实例移动到新的线程，实现多线程运行 
    work1->moveToThread(&workthread1);
    workthread1.start();
    work2->moveToThread(&workthread2);
    workthread2.start();
    work3->moveToThread(&workthread3);
    workthread3.start();
    work4->moveToThread(&workthread4);
    workthread4.start();
    work5->moveToThread(&workthread5);
    workthread5.start();

    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &QtWidgetsApplication1::showTime);//1000ms刷新一次
    connect(work1, &worker::workdone, timer, &QTimer::stop);//收到work1发出的处理结束信号就停止计时
}

QtWidgetsApplication1::~QtWidgetsApplication1()
{
    workthread1.quit();
    workthread1.wait();
    workthread2.quit();
    workthread2.wait();
    workthread3.quit();
    workthread3.wait();
    workthread4.quit();
    workthread4.wait();
    workthread5.quit();
    workthread5.wait();
}

void QtWidgetsApplication1::on_action_Button_ReadImg_clicked()
{
    Mat img1;
    //将imread得到的BRG Mat转换成RGB Mat
    cvtColor(img, img1, COLOR_BGR2RGB);
    //将RGB Mat格式转化为QImage格式
    QImage disImage = QImage((const unsigned char*)(img1.data), img1.cols, img1.rows, QImage::Format_RGB888);
    //用QPixmap获得QImage图像，用label显示QPixmap格式图像，并根据label的大小来缩放QImage的大小
    
    ui.lableImg->setPixmap(QPixmap::fromImage(disImage.scaled(ui.lableImg->size(), Qt::KeepAspectRatio)));
}//读取图片

Mat Hist(Mat src)//定义了一个Hist函数，输入图像，返回它的直方图，格式均为Mat类
{
    //! [Separate the image in 3 places ( B, G and R )]
    std::vector<Mat> bgr_planes;
    split(src, bgr_planes);
    //! [Establish the number of bins]
    int histSize = 256;
    //! [Set the ranges ( for B,G,R) )]
    float range[] = { 0, 256 }; //the upper boundary is exclusive
    const float* histRange = { range };
    //! [Set histogram param]
    bool uniform = true, accumulate = false;

    //! [Compute the histograms]
    Mat b_hist, g_hist, r_hist;
    calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);
    //! [Draw the histograms for B, G and R]
    int hist_w = 512, hist_h = 500;
    int bin_w = cvRound((double)hist_w / histSize);
    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
    //! [Normalize the result to ( 0, histImage.rows )]
    normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    //! [Draw for each channel]
    for (int i = 1; i < histSize; i++)
    {
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))),
            Scalar(255, 0, 0), 2, 8, 0);
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))),
            Scalar(0, 255, 0), 2, 8, 0);
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))),
            Scalar(0, 0, 255), 2, 8, 0);
    }
    return histImage;
}
void QtWidgetsApplication1::on_action_Button_HistAna_clicked()
{
    Mat histimg, img1;
    histimg = Hist(img);//img是全局变量
    cvtColor(histimg, img1, COLOR_BGR2RGB);
    QImage disImage = QImage((const unsigned char*)(img1.data), img1.cols, img1.rows, QImage::Format_RGB888);
    ui.lableImg->setPixmap(QPixmap::fromImage(disImage.scaled(ui.lableImg->size(), Qt::KeepAspectRatio)));
}//直方图分析

int threshold_value = 100;//二值化初始阈值
int threshold_type = 3;//二值化类型
int const max_value = 255;//二值化阈值可调的最大值
int const max_binary_value = 255;//threshold函数中的参数
Mat Threshold_Demo(Mat src_gray, int thresholdvalue)
{
    /*threshold_types:
     0: Binary
     1: Binary Inverted
     2: Threshold Truncated
     3: Threshold to Zero
     4: Threshold to Zero Inverted
    */
    Mat dst;
    threshold(src_gray, dst, thresholdvalue, max_binary_value, threshold_type);
    return dst;
}
void QtWidgetsApplication1::on_action_Button_Threshold_clicked()
{
    //设置二值化阈值初始值
    ui.ThresholdValue->setMinimum(0);
    ui.ThresholdValue->setMaximum(max_value);
    ui.ThresholdValue->setValue(threshold_value);//滑块初始位置为100
    ui.thresholdvalue->setText("100");//初始显示二值化阈值的数值为100
    Mat img_gray, dst;
    cvtColor(img, img_gray, COLOR_BGR2GRAY);//转为灰度图像
    dst = Threshold_Demo(img_gray, threshold_value);//得到二值化图像
    QImage disImage = QImage((const unsigned char*)(dst.data), dst.cols, dst.rows, QImage::Format_Grayscale8);
    ui.lableImg->setPixmap(QPixmap::fromImage(disImage.scaled(ui.lableImg->size(), Qt::KeepAspectRatio)));
}
void QtWidgetsApplication1::on_action_Slider_ThresholdValue_edited(int value)
{
    QString str = QString("%1").arg(value);
    ui.thresholdvalue->setText(str);//显示二值化阈值的数值
    Mat img_gray, dst;
    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    dst = Threshold_Demo(img_gray, value);
    QImage disImage = QImage((const unsigned char*)(dst.data), dst.cols, dst.rows, QImage::Format_Grayscale8);
    ui.lableImg->setPixmap(QPixmap::fromImage(disImage.scaled(ui.lableImg->size(), Qt::KeepAspectRatio)));
}//二值化处理的实现


void QtWidgetsApplication1::on_action_Button_Multiline_clicked()
{
    //计时器
    timer->start(1);//点击按钮就开始计时，刷新间隔为1ms
    qDebug() << "Process begin!---------------------------------";
    qDebug() << "Current thread ID:" << QThread::currentThreadId() << '\n';//显示开始使用多线程时的线程地址
    //点击按钮之后，发送各个线程的触发信号，并传递不同的起始值。
    emit operate1(0);
    emit operate2(40);
    emit operate3(80);
    emit operate4(120);
    emit operate5(160);
}
//进度显示
void QtWidgetsApplication1::updateProgressbar(double percent)
{
    ui.multilineprogess->setValue(percent * 100);
}
//处理过程结束
void QtWidgetsApplication1::Finished()
{
    qDebug() << "Process done---------------------------------";
    qDebug() << "Current thread ID:" << QThread::currentThreadId() << '\n';//显示结束时的线程地址
}

void QtWidgetsApplication1::showTime()
//将调用该函数的次数传递给ui.multilinetime控件显示出来，结合计时器，其实就是1s调用一次，返回总时长。
{
    static int i = 0;
    i++;
    ui.multilinetime->display(i);
}
