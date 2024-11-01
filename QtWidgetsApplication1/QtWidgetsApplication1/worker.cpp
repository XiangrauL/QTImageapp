#include "worker.h"
#include "opencv2/opencv.hpp"
#include <opencv2\highgui\highgui.hpp>
#include<QDebug>
#include<QThread>
using namespace cv;
using namespace std;
void worker::dowork(int i)
{
	qDebug() << "QThread: working---------------------------------";
	qDebug() << "Curren QThread ID:" << QThread::currentThreadId();
	String input_image_path = "D:\\pythoncode\\pythonProject2\\downloaded_data\\";//�ļ���·��D:\pythoncode\pythonProject2\downloaded_data
	String output_image_path = "D:\\pythoncode\\pythonProject2\\after_data\\";
	String save_image_name;
	vector<String>src_test;
	glob(input_image_path, src_test);//���ļ���·���µ�����ͼƬ·�����浽src_test��
	qDebug() << "Number of images found:" << src_test.size();
	int length = 40;//ÿһ���̴߳���40��ͼƬ
	Mat image, img_gray;
	int j;
	if (i < 0 || i >= src_test.size()) {
		qDebug() << "Invalid starting index:" << i;
		emit workdone();
		return;
	}
	for (j = i; j < i + length; j++) {	//�ӵ�i�ſ�ʼ��ȡ40��
		emit workpercent((j - i + 1.0) / (length)); //ʵʱ�����̴߳������
		//qDebug() << "Trying to load image:"<< QString::fromStdString(src_test[j]);
		image = imread(src_test[j]);
		if (image.empty()) {
			qDebug() << "Failed to load image:" << QString::fromStdString(src_test[j]);
			continue; // ��������ͼ��
		}
		cvtColor(image, img_gray, COLOR_BGR2GRAY);
		save_image_name = output_image_path + to_string(j+1) + ".jpg";
		imwrite(save_image_name, img_gray);
	}
	emit workdone();
}