#include "QtWidgetsApplication1.h"
#include "worker.h"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <vector>
#include <Qtimer.h>
#include <QDebug>//����Ҫ�õ�qDebug()��������Ҫ��ӿ⺯��
using namespace cv;

//Ϊ�˷�����Դ��룬������һ��ȫ�ֱ���
Mat img = imread("D:\\����\\������\\������\\1.jpg", IMREAD_COLOR);

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
    //connect(�ؼ�, ������ʽ, this, �����Ĳۺ���);
    connect(ui.ReadImg, &QPushButton::clicked, this, &QtWidgetsApplication1::on_action_Button_ReadImg_clicked);
    connect(ui.HistAna, &QPushButton::clicked, this, &QtWidgetsApplication1::on_action_Button_HistAna_clicked);
    connect(ui.Threshold, &QPushButton::clicked, this, &QtWidgetsApplication1::on_action_Button_Threshold_clicked);
    connect(ui.ThresholdValue, &QSlider::sliderMoved, this, &QtWidgetsApplication1::on_action_Slider_ThresholdValue_edited);
    connect(ui.Multiline, &QPushButton::clicked, this, &QtWidgetsApplication1::on_action_Button_Multiline_clicked);
    
    //���ö��߳�
    //����5��workʵ��
    worker* work1 = new worker;
    worker* work2 = new worker;
    worker* work3 = new worker;
    worker* work4 = new worker;
    worker* work5 = new worker;
    //�������źŵ���ʼֵ���ݸ�ʵ��������ʼdowork
    connect(this, &QtWidgetsApplication1::operate1, work1, &worker::dowork);//operate�źŷ����������ȡ
    //5���̲߳��н��У���ֻ��Ҫ��ʾһ���̵߳Ľ��ȣ���һ�����̽����������������̽���
    connect(work1, &worker::workpercent, this, &QtWidgetsApplication1::updateProgressbar); // ��ʾ��ȡ���� 
    connect(work1, &worker::workdone, this, &QtWidgetsApplication1::Finished);    //���̽���
    connect(this, &QtWidgetsApplication1::operate2, work2, &worker::dowork);
    connect(this, &QtWidgetsApplication1::operate3, work3, &worker::dowork);
    connect(this, &QtWidgetsApplication1::operate4, work4, &worker::dowork);
    connect(this, &QtWidgetsApplication1::operate5, work5, &worker::dowork);

    //��ʵ���ƶ����µ��̣߳�ʵ�ֶ��߳����� 
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
    connect(timer, &QTimer::timeout, this, &QtWidgetsApplication1::showTime);//1000msˢ��һ��
    connect(work1, &worker::workdone, timer, &QTimer::stop);//�յ�work1�����Ĵ�������źž�ֹͣ��ʱ
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
    //��imread�õ���BRG Matת����RGB Mat
    cvtColor(img, img1, COLOR_BGR2RGB);
    //��RGB Mat��ʽת��ΪQImage��ʽ
    QImage disImage = QImage((const unsigned char*)(img1.data), img1.cols, img1.rows, QImage::Format_RGB888);
    //��QPixmap���QImageͼ����label��ʾQPixmap��ʽͼ�񣬲�����label�Ĵ�С������QImage�Ĵ�С
    
    ui.lableImg->setPixmap(QPixmap::fromImage(disImage.scaled(ui.lableImg->size(), Qt::KeepAspectRatio)));
}//��ȡͼƬ

Mat Hist(Mat src)//������һ��Hist����������ͼ�񣬷�������ֱ��ͼ����ʽ��ΪMat��
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
    histimg = Hist(img);//img��ȫ�ֱ���
    cvtColor(histimg, img1, COLOR_BGR2RGB);
    QImage disImage = QImage((const unsigned char*)(img1.data), img1.cols, img1.rows, QImage::Format_RGB888);
    ui.lableImg->setPixmap(QPixmap::fromImage(disImage.scaled(ui.lableImg->size(), Qt::KeepAspectRatio)));
}//ֱ��ͼ����

int threshold_value = 100;//��ֵ����ʼ��ֵ
int threshold_type = 3;//��ֵ������
int const max_value = 255;//��ֵ����ֵ�ɵ������ֵ
int const max_binary_value = 255;//threshold�����еĲ���
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
    //���ö�ֵ����ֵ��ʼֵ
    ui.ThresholdValue->setMinimum(0);
    ui.ThresholdValue->setMaximum(max_value);
    ui.ThresholdValue->setValue(threshold_value);//�����ʼλ��Ϊ100
    ui.thresholdvalue->setText("100");//��ʼ��ʾ��ֵ����ֵ����ֵΪ100
    Mat img_gray, dst;
    cvtColor(img, img_gray, COLOR_BGR2GRAY);//תΪ�Ҷ�ͼ��
    dst = Threshold_Demo(img_gray, threshold_value);//�õ���ֵ��ͼ��
    QImage disImage = QImage((const unsigned char*)(dst.data), dst.cols, dst.rows, QImage::Format_Grayscale8);
    ui.lableImg->setPixmap(QPixmap::fromImage(disImage.scaled(ui.lableImg->size(), Qt::KeepAspectRatio)));
}
void QtWidgetsApplication1::on_action_Slider_ThresholdValue_edited(int value)
{
    QString str = QString("%1").arg(value);
    ui.thresholdvalue->setText(str);//��ʾ��ֵ����ֵ����ֵ
    Mat img_gray, dst;
    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    dst = Threshold_Demo(img_gray, value);
    QImage disImage = QImage((const unsigned char*)(dst.data), dst.cols, dst.rows, QImage::Format_Grayscale8);
    ui.lableImg->setPixmap(QPixmap::fromImage(disImage.scaled(ui.lableImg->size(), Qt::KeepAspectRatio)));
}//��ֵ�������ʵ��


void QtWidgetsApplication1::on_action_Button_Multiline_clicked()
{
    //��ʱ��
    timer->start(1);//�����ť�Ϳ�ʼ��ʱ��ˢ�¼��Ϊ1ms
    qDebug() << "Process begin!---------------------------------";
    qDebug() << "Current thread ID:" << QThread::currentThreadId() << '\n';//��ʾ��ʼʹ�ö��߳�ʱ���̵߳�ַ
    //�����ť֮�󣬷��͸����̵߳Ĵ����źţ������ݲ�ͬ����ʼֵ��
    emit operate1(0);
    emit operate2(40);
    emit operate3(80);
    emit operate4(120);
    emit operate5(160);
}
//������ʾ
void QtWidgetsApplication1::updateProgressbar(double percent)
{
    ui.multilineprogess->setValue(percent * 100);
}
//������̽���
void QtWidgetsApplication1::Finished()
{
    qDebug() << "Process done---------------------------------";
    qDebug() << "Current thread ID:" << QThread::currentThreadId() << '\n';//��ʾ����ʱ���̵߳�ַ
}

void QtWidgetsApplication1::showTime()
//�����øú����Ĵ������ݸ�ui.multilinetime�ؼ���ʾ��������ϼ�ʱ������ʵ����1s����һ�Σ�������ʱ����
{
    static int i = 0;
    i++;
    ui.multilinetime->display(i);
}
