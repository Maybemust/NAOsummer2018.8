#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstdio>
using namespace cv;
using namespace std;
#define width 320
#define height 240
int main()
{
    // 512 x 512 零矩阵
    int counterror=0;

    //Mat img = Mat::zeros(height, width, CV_8UC3);
    cout<<counterror++<<endl;
    // 训练样本
    Mat original=imread("eight1.jpg");
    Mat goal =imread("eight_color1.jpg");
    cout<<counterror++<<endl;
    float train_data[width*height][3];
    for(int i=0;i<original.rows;i++)
    {
    	for(int j=0;j<original.cols;j++)
    	{
    		//int t=original.at<Vec3b>(i,j)[0];
    		train_data[i*width+j][0]=float(original.at<Vec3b>(i,j)[0]);
    		train_data[i*width+j][1]=float(original.at<Vec3b>(i,j)[1]);
    		train_data[i*width+j][2]=float(original.at<Vec3b>(i,j)[2]);
    	}
    }
    cout<<counterror++<<endl;
    float labels[width*height][3];
    for(int i=0;i<goal.rows;i++)
    {
    	for(int j=0;j<goal.cols;j++)
    	{
    		labels[i*width+j][0]=float(goal.at<Vec3b>(i,j)[0]);
    		labels[i*width+j][1]=float(goal.at<Vec3b>(i,j)[1]);
    		labels[i*width+j][2]=float(goal.at<Vec3b>(i,j)[2]);
    	}
    }
    cout<<counterror++<<endl;
    //float train_data[6][2] = { { 500, 60 },{ 245, 40 },{ 480, 250 },{ 160, 380 },{400, 25},{55, 400} };
     // 每个样本数据对应的输出
    Mat train_data_mat(width*height, 3, CV_32FC3, train_data);
    Mat labels_mat(width*height, 3, CV_32FC3, labels);
	cout<<counterror++<<endl;
    // BP 模型创建和参数设置
    Ptr<ml::ANN_MLP> bp = ml::ANN_MLP::create();
    cout<<counterror++<<endl;
    Mat layers_size = (Mat_<int>(1,4) << 3,6,9,3); // 2维点，1维输出
    bp->setLayerSizes(layers_size);
    cout<<counterror++<<endl;
    bp->setTrainMethod(ml::ANN_MLP::BACKPROP,0.1,0.1);
    bp->setActivationFunction(ml::ANN_MLP::SIGMOID_SYM);
    bp->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 10000, /*FLT_EPSILON*/1e-6));
    cout<<counterror++<<endl;
    // 保存训练好的神经网络参数
    bool trained = bp->train(train_data_mat,ml::ROW_SAMPLE,labels_mat);
    if (trained) {
        bp->save("bp_param");
    }
    cout<<counterror++<<endl;
    // 创建训练好的神经网络
    //Ptr<ml::ANN_MLP> 
    bp = ml::ANN_MLP::load("bp_param");
    cout<<counterror++<<endl;
    // 显示分类的结果
    // Vec3b green(0, 255, 0), blue(255, 0, 0);
    // for (int i=0; i<img.rows; ++i) {
    //     for (int j=0; j<img.cols; ++j) {
    //         Mat sample_mat = (Mat_<float>(1, 2) << j, i);
    //         Mat response_mat;
    //         bp->predict(sample_mat,response_mat);
    //         float response = response_mat.ptr<float>(0)[0];
    //         if (response > 0.5) {
    //             img.at<Vec3b>(i, j) = green;
    //         } else if (response < 0.5) {
    //             img.at<Vec3b>(i, j) = blue;
    //         }
    //     }
    // }

    // 画出训练样本数据
    // int thickness = -1;
    // int lineType = 8;
    // circle(img, Point(500, 60), 5, Scalar(255, 255, 255), thickness, lineType);
    // circle(img, Point(245, 40), 5, Scalar(255, 255, 255), thickness, lineType);
    // circle(img, Point(480, 250), 5, Scalar(255, 255, 255), thickness, lineType);
    // circle(img, Point(160, 380), 5, Scalar(0, 0, 255), thickness, lineType);
    // circle(img, Point(400, 25), 5, Scalar(255, 255, 255), thickness, lineType);
    // circle(img, Point(55, 400), 5, Scalar(0, 0, 255), thickness, lineType);

    // imwrite("result.png", img);        // 保存训练的结果
    // imshow("BP Simple Example", img);
    Mat predictimg=imread("01.jpg");
    imshow("original",predictimg);
    Mat result;
    bp->predict(predictimg,result);
    imshow("resultimage",result);
    // for(int i=0;i<goal.rows;i++)
    // {
    // 	for(int j=0;j<goal.cols;j++)
    // 	{
    // 		bp->predict()
    // 	}
    // }

    waitKey(0);
    return 0;
}