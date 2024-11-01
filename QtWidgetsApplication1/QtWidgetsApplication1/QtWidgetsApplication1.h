#ifndef QTWIDGETSAPPLICATION1_H  
#define QTWIDGETSAPPLICATION1_H  
//防止头文件被重复包含的预处理指令
 

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"
#include <QThread>//要定义线程，所以需要添加QThread库

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = nullptr);//构造函数
    ~QtWidgetsApplication1();//析构函数

private slots://槽函数私有
    //函数名的命名方式：on_控件类名_触发方式()
    
    //声明读取图片函数
    void on_action_Button_ReadImg_clicked();

    //声明直方图分析函数
    void on_action_Button_HistAna_clicked();

    //声明二值化处理函数
    void on_action_Button_Threshold_clicked();
    //声明二值化阈值设定函数
    void on_action_Slider_ThresholdValue_edited(int value);

    //声明多线程处理函数
    void on_action_Button_Multiline_clicked();
    //声明线程结束输出函数
    void Finished();
    //处理线程的进度显示
    void updateProgressbar(double percent);
    //处理线程的时间显示
    void showTime();

private:
    Ui::QtWidgetsApplication1Class ui;

    QThread workthread1;//定义需要使用的线程
    QThread workthread2;
    QThread workthread3;
    QThread workthread4;
    QThread workthread5;
    QTimer* timer;

signals:
    // 用于触发线程的信号，由于使用了5个线程，每个线程处理图片的起始值不同，
    //故要有5个信号携带不同的起始值来分别触发，比如线程1处理1-200，线程2处理201-400，以此类推
    void operate1(const int);
    void operate2(const int);
    void operate3(const int);
    void operate4(const int);
    void operate5(const int);
};

#endif // QTWIDGETSAPPLICATION1_H
//防止头文件被重复包含的预处理指令
