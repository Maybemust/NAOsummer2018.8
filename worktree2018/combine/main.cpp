/*
 * Copyright (c) 2012-2018 SoftBank Robotics. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the COPYING file.
 */
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstdio>
using namespace cv;
using namespace std;
#define filenum 3
int main()
{
  cout<<"111"<<endl;
  Mat finalimage(240,filenum*320, CV_8UC3);
  Mat image1=imread("/home/liyang/Pictures/pu1.png");
  Mat image2=imread("/home/liyang/Pictures/pu2.png");
  Mat image3=imread("/home/liyang/Pictures/pu3.png");
  //Mat image4=imread("/home/liyang/Pictures/pu4.png");
  //Mat image5=imread("/home/liyang/Pictures/pu5.png");
  // Mat image6=imread("/home/liyang/Pictures/red5.png");
  // Mat image7=imread("/home/liyang/Pictures/red6.png");
  // Mat image8=imread("/home/liyang/Pictures/red7.png");
  // Mat image9=imread("/home/liyang/Pictures/red8.png");
  // Mat image10=imread("/home/liyang/Pictures/red9.png");

  cout<<"222"<<endl;
  int num=0;
  num++;
  for(int j=0;j<240;j++)
  {
  	for(int i=(num-1)*320;i<num*320;i++)
  	{
  		cout<<"***"<<i<<"&&&"<<j<<endl;
  		finalimage.at<Vec3b>(j,i)[0]=image1.at<Vec3b>(j,i%320)[0];
  		finalimage.at<Vec3b>(j,i)[1]=image1.at<Vec3b>(j,i%320)[1];
  		finalimage.at<Vec3b>(j,i)[2]=image1.at<Vec3b>(j,i%320)[2];
  	}
  }
  cout<<"333"<<endl;
  num++;
  for(int j=0;j<240;j++)
  {
  	for(int i=(num-1)*320;i<num*320;i++)
  	{
  		finalimage.at<Vec3b>(j,i)[0]=image2.at<Vec3b>(j,i%320)[0];
  		finalimage.at<Vec3b>(j,i)[1]=image2.at<Vec3b>(j,i%320)[1];
  		finalimage.at<Vec3b>(j,i)[2]=image2.at<Vec3b>(j,i%320)[2];
  	}
  }
  num++;
  for(int j=0;j<240;j++)
  {
  	for(int i=(num-1)*320;i<num*320;i++)
  	{
  		finalimage.at<Vec3b>(j,i)[0]=image3.at<Vec3b>(j,i%320)[0];
  		finalimage.at<Vec3b>(j,i)[1]=image3.at<Vec3b>(j,i%320)[1];
  		finalimage.at<Vec3b>(j,i)[2]=image3.at<Vec3b>(j,i%320)[2];
  	}
  }
  // num++;
  // for(int j=0;j<240;j++)
  // {
  // 	for(int i=(num-1)*320;i<num*320;i++)
  // 	{
  // 		finalimage.at<Vec3b>(j,i)[0]=image4.at<Vec3b>(j,i%320)[0];
  // 		finalimage.at<Vec3b>(j,i)[1]=image4.at<Vec3b>(j,i%320)[1];
  // 		finalimage.at<Vec3b>(j,i)[2]=image4.at<Vec3b>(j,i%320)[2];
  // 	}
  // }
  // num++;
  // for(int j=0;j<240;j++)
  // {
  // 	for(int i=(num-1)*320;i<num*320;i++)
  // 	{
  // 		finalimage.at<Vec3b>(j,i)[0]=image5.at<Vec3b>(j,i%320)[0];
  // 		finalimage.at<Vec3b>(j,i)[1]=image5.at<Vec3b>(j,i%320)[1];
  // 		finalimage.at<Vec3b>(j,i)[2]=image5.at<Vec3b>(j,i%320)[2];
  // 	}
  // }
  // num++;
  // for(int j=0;j<240;j++)
  // {
  // 	for(int i=(num-1)*320;i<num*320;i++)
  // 	{
  // 		finalimage.at<Vec3b>(j,i)[0]=image6.at<Vec3b>(j,i%320)[0];
  // 		finalimage.at<Vec3b>(j,i)[1]=image6.at<Vec3b>(j,i%320)[1];
  // 		finalimage.at<Vec3b>(j,i)[2]=image6.at<Vec3b>(j,i%320)[2];
  // 	}
  // }
  // num++;
  // for(int j=0;j<240;j++)
  // {
  // 	for(int i=(num-1)*320;i<num*320;i++)
  // 	{
  // 		finalimage.at<Vec3b>(j,i)[0]=image7.at<Vec3b>(j,i%320)[0];
  // 		finalimage.at<Vec3b>(j,i)[1]=image7.at<Vec3b>(j,i%320)[1];
  // 		finalimage.at<Vec3b>(j,i)[2]=image7.at<Vec3b>(j,i%320)[2];
  // 	}
  // }
  // num++;
  // for(int j=0;j<240;j++)
  // {
  // 	for(int i=(num-1)*320;i<num*320;i++)
  // 	{
  // 		finalimage.at<Vec3b>(j,i)[0]=image7.at<Vec3b>(j,i%320)[0];
  // 		finalimage.at<Vec3b>(j,i)[1]=image7.at<Vec3b>(j,i%320)[1];
  // 		finalimage.at<Vec3b>(j,i)[2]=image7.at<Vec3b>(j,i%320)[2];
  // 	}
  // }
  // num++;
  // for(int j=0;j<240;j++)
  // {
  // 	for(int i=(num-1)*320;i<num*320;i++)
  // 	{
  // 		finalimage.at<Vec3b>(j,i)[0]=image7.at<Vec3b>(j,i%320)[0];
  // 		finalimage.at<Vec3b>(j,i)[1]=image7.at<Vec3b>(j,i%320)[1];
  // 		finalimage.at<Vec3b>(j,i)[2]=image7.at<Vec3b>(j,i%320)[2];
  // 	}
  // }
  // num++;
  // for(int j=0;j<240;j++)
  // {
  // 	for(int i=(num-1)*320;i<num*320;i++)
  // 	{
  // 		finalimage.at<Vec3b>(j,i)[0]=image7.at<Vec3b>(j,i%320)[0];
  // 		finalimage.at<Vec3b>(j,i)[1]=image7.at<Vec3b>(j,i%320)[1];
  // 		finalimage.at<Vec3b>(j,i)[2]=image7.at<Vec3b>(j,i%320)[2];
  // 	}
  // }
  cout<<"444"<<endl;
  imshow("final",finalimage);
  waitKey();
  imwrite("finalimage.png",finalimage);
  return 0;
}
