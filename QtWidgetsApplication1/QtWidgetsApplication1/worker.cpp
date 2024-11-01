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
	String input_image_path = "D:\\pythoncode\\pythonProject2\\downloaded_data\\";//文件夹路径D:\pythoncode\pythonProject2\downloaded_data
	String output_image_path = "D:\\pythoncode\\pythonProject2\\after_data\\";
	String save_image_name;
	vector<String>src_test;
	glob(input_image_path, src_test);//将文件夹路径下的所有图片路径保存到src_test中
	qDebug() << "Number of images found:" << src_test.size();
	int length = 40;//每一个线程处理40张图片
	Mat image, img_gray;
	int j;
	if (i < 0 || i >= src_test.size()) {
		qDebug() << "Invalid starting index:" << i;
		emit workdone();
		return;
	}
	for (j = i; j < i + length; j++) {	//从第i张开始读取40张
		emit workpercent((j - i + 1.0) / (length)); //实时发送线程处理进度
		//qDebug() << "Trying to load image:"<< QString::fromStdString(src_test[j]);
		image = imread(src_test[j]);
		if (image.empty()) {
			qDebug() << "Failed to load image:" << QString::fromStdString(src_test[j]);
			continue; // 跳过这张图像
		}
		cvtColor(image, img_gray, COLOR_BGR2GRAY);
		save_image_name = output_image_path + to_string(j+1) + ".jpg";
		imwrite(save_image_name, img_gray);
	}
	emit workdone();
}