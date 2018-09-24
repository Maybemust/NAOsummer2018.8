/*
 * Copyright (c) 2012-2018 SoftBank Robotics. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the COPYING file.
 */
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
void colorReduce(Mat& image,int t)
{
	for(int i=0;i<image.rows;i++)
	{
		for(int j=0;j<image.cols;j++)
		{
			image.at<Vec3b>(i,j)[0]=i;
			image.at<Vec3b>(i,j)[1]=j;
			image.at<Vec3b>(i,j)[2]=t;
		}
	}
}
int main()
{
  Mat imgres(180,256,CV_8UC3);
  //Mat imgres;
  cvtColor(imgres,imgres,CV_BGR2HSV);
  for(int i=0;i<=255;i=i+16)
  {
  colorReduce(imgres,i);
  char str[10]="result";
  str[6]=i;
  imshow(str,imgres);
  waitKey();
  }
  waitKey();
  return 0;
}
