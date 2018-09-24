/*
 * Copyright (c) 2012-2018 SoftBank Robotics. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the COPYING file.
 */
#include <iostream>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main()
{
  int hight=240,width=320;
  int sraw=120,scol=160;
  Mat original=imread("binarySample13.jpg");
  imshow("original",original);
  float train_data[(width-scol)*(hight-sraw)];
  //cout<<"*######################*"<<endl;
  int cnt=0;
  cout<<original.rows<<"  "<<original.cols<<endl;
  Mat res= Mat::zeros(120, 160, CV_8UC1);
  for(int i=sraw;i<original.rows;i++)
  {
    for(int j=scol;j<original.cols;j++)
    {
      // train_data[(i-sraw)*(width-scol)+j-scol][0]=original.at<Vec3b>(i,j)[0];
      // train_data[(i-sraw)*(width-scol)+j-scol][1]=original.at<Vec3b>(i,j)[1];
      // train_data[(i-sraw)*(width-scol)+j-scol][2]=original.at<Vec3b>(i,j)[2];
      //cout<<(i-sraw)*(width-scol)+j-scol<<" "<<endl;
      //cout<<(i-sraw)<<" "<<j-scol<<endl;
      res.at<Vec3b>(i-sraw,j-scol)=original.at<Vec3b>(i,j)[0];
      //res.at<Vec3b>(i-sraw,j-scol)[1]=original.at<Vec3b>(i,j)[1];
      //res.at<Vec3b>(i-sraw,j-scol)[2]=original.at<Vec3b>(i,j)[2];

    }
  }
  cout<<"*######################*111111111"<<endl;//hight-sraw
  //Mat res(hight-sraw, width-scol, CV_32F, train_data);
  //res.converTo(res,)
  //CV_RBGTOGRAY
  imshow("1",res);
  imwrite("binarySample1.jpg",res);
  return 0;
}
