#include<opencv2/opencv.hpp>
#include<iostream>



#define New_Window "效果图"

using namespace std;
using namespace cv;

//定义全局变量
int a, b;//表示亮度和对比度
Mat c, d;//原图像和目标图像




void Feed_Back(int, void*) {
	for (int i = 0; i < c.rows; i++) {
		for (int j = 0; j < c.cols; j++) {
			for (int k = 0; k < 3; k++) {
				d.at<Vec3b>(i, j)[k] =
					saturate_cast<uchar>((a*0.01)*c.at<Vec3b>(i, j)[k] + b);
			}
		}
	}


	imshow(New_Window, d);
	//imwrite("F:\\效果图.jpg", d);
}

int main() {

	namedWindow("原图", CV_WINDOW_NORMAL);
	namedWindow(New_Window, CV_WINDOW_NORMAL);
	
	try {
		c = imread("cool.jpg", 4);
	}
	catch (Exception& e)
	{
		const char* err_msg = e.what();
		cout << "exception caught: " << err_msg << endl;
	}
	imshow("原图", c);

	d = Mat::zeros(c.size(), c.type());

	//定义亮度和色彩的初始值
	a = 80;
	b = 80;

	createTrackbar("对比度:", New_Window, &a, 300, Feed_Back);
	createTrackbar("亮度:", New_Window, &b, 200, Feed_Back);
	//创建两个滑动条

	Feed_Back(a, 0);
	Feed_Back(b, 0);//调用回调函数

	waitKey(0);
	return 0;

}
