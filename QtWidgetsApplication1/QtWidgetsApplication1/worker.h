#pragma once
#include <QObject>
class worker : public QObject
{
    Q_OBJECT
public:
    worker(QObject* parent = nullptr) {}
public slots:
    void dowork(int i); // dowork�������߳�Ҫִ�еĲ���
signals:
    void workpercent(double percent);// �̵߳Ľ���
    void workdone();       // �߳���ɹ���ʱ���͵��ź�
};
