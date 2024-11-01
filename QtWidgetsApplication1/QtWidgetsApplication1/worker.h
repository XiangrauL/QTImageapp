#pragma once
#include <QObject>
class worker : public QObject
{
    Q_OBJECT
public:
    worker(QObject* parent = nullptr) {}
public slots:
    void dowork(int i); // dowork定义了线程要执行的操作
signals:
    void workpercent(double percent);// 线程的进度
    void workdone();       // 线程完成工作时发送的信号
};
