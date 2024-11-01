#ifndef QTWIDGETSAPPLICATION1_H  
#define QTWIDGETSAPPLICATION1_H  
//��ֹͷ�ļ����ظ�������Ԥ����ָ��
 

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"
#include <QThread>//Ҫ�����̣߳�������Ҫ���QThread��

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = nullptr);//���캯��
    ~QtWidgetsApplication1();//��������

private slots://�ۺ���˽��
    //��������������ʽ��on_�ؼ�����_������ʽ()
    
    //������ȡͼƬ����
    void on_action_Button_ReadImg_clicked();

    //����ֱ��ͼ��������
    void on_action_Button_HistAna_clicked();

    //������ֵ��������
    void on_action_Button_Threshold_clicked();
    //������ֵ����ֵ�趨����
    void on_action_Slider_ThresholdValue_edited(int value);

    //�������̴߳�����
    void on_action_Button_Multiline_clicked();
    //�����߳̽����������
    void Finished();
    //�����̵߳Ľ�����ʾ
    void updateProgressbar(double percent);
    //�����̵߳�ʱ����ʾ
    void showTime();

private:
    Ui::QtWidgetsApplication1Class ui;

    QThread workthread1;//������Ҫʹ�õ��߳�
    QThread workthread2;
    QThread workthread3;
    QThread workthread4;
    QThread workthread5;
    QTimer* timer;

signals:
    // ���ڴ����̵߳��źţ�����ʹ����5���̣߳�ÿ���̴߳���ͼƬ����ʼֵ��ͬ��
    //��Ҫ��5���ź�Я����ͬ����ʼֵ���ֱ𴥷��������߳�1����1-200���߳�2����201-400���Դ�����
    void operate1(const int);
    void operate2(const int);
    void operate3(const int);
    void operate4(const int);
    void operate5(const int);
};

#endif // QTWIDGETSAPPLICATION1_H
//��ֹͷ�ļ����ظ�������Ԥ����ָ��
