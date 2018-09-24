#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/ml/ml.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <cstdio>
using namespace cv;
using namespace std;

int main()
{
    // // 512 x 512 零矩阵
    int width = 320/2, height = 240/2;
    Mat img = Mat::zeros(height*2, width*2, CV_8UC3);

    // 训练样本
    // float train_data[6][2] = { { 500, 60 },{ 245, 40 },{ 480, 250 },{ 160, 380 },{400, 25},{55, 400} };
    // float labels[6] = {0,0,0,1,0,1};  // 每个样本数据对应的输出
    // Mat train_data_mat(6, 2, CV_32FC1, train_data);
    // Mat labels_mat(6, 1, CV_32FC1, labels);
    Mat train_data_mat1=imread("sample13.jpg");
    Mat labels_mat1=imread("binarySample13.jpg");
    cout<<"step1"<<endl;
    float train_data[width*height][3];
    float labels[width*height];

    for(int i=train_data_mat1.rows/2;i<train_data_mat1.rows;i++)
    {
    	for(int j=train_data_mat1.cols/2;j<train_data_mat1.cols;j++)
    	{
    		int ii=i-(train_data_mat1.rows/2);
    		int jj=j-(train_data_mat1.cols/2);
    		//train_data[i*train_data_mat1.rows/2+j][0]=train_data_mat1.at<Vec3b>(i,j)[0];
    		//train_data[i*train_data_mat1.rows/2+j][1]=train_data_mat1.at<Vec3b>(i,j)[1];
    		//train_data[i*train_data_mat1.rows/2+j][2]=train_data_mat1.at<Vec3b>(i,j)[2];
    		train_data[ii*(train_data_mat1.rows/2)+jj][0]=train_data_mat1.at<Vec3b>(i,j)[0];
    		train_data[ii*(train_data_mat1.rows/2)+jj][1]=train_data_mat1.at<Vec3b>(i,j)[1];
    		train_data[ii*(train_data_mat1.rows/2)+jj][2]=train_data_mat1.at<Vec3b>(i,j)[2];
    	}
    }

    for(int i=labels_mat1.rows/2;i<labels_mat1.rows;i++)
    {
    	for(int j=labels_mat1.cols/2;j<labels_mat1.cols;j++)
    	{
    		int ii=i-labels_mat1.rows/2;
    		int jj=j-labels_mat1.cols/2;
    		labels[ii*(labels_mat1.rows/2)+jj]=labels_mat1.at<Vec3b>(i,j)[0];
    		//train_data[i*labels_mat1.rows+j][1]=labels_mat1.at<Vec3b>(i,j)[1];
    		//train_data[i*labels_mat1.rows+j][2]=labels_mat1.at<Vec3b>(i,j)[2];
    	}
    }
    cout<<"step2"<<endl;
    Mat train_data_mat(width*height, 3, CV_32FC1, train_data);
    Mat labels_mat(width*height, 1, CV_32FC1, labels);
    cout<<"step3"<<endl;
    // imwrite("train_data_mat.jpg",train_data_mat);
    // imshow("train_data_mat",train_data_mat);
    // imwrite("labels_mat.jpg",labels_mat);
    // imshow("labels_mat",labels_mat);

    // train_data_mat.convertTo(train_data_mat, CV_32FC1);
    // labels_mat.convertTo( labels_mat, CV_32FC1);

    // BP 模型创建和参数设置
    cout<<"step4"<<endl;
    Ptr<ml::ANN_MLP> bp = ml::ANN_MLP::create();
    cout<<"step5"<<endl;
    Mat layers_size = (Mat_<int>(1,4) << 3,6,6,1); // 2维点，1维输出
    bp->setLayerSizes(layers_size);
    cout<<"step6"<<endl;
    bp->setTrainMethod(ml::ANN_MLP::BACKPROP,0.1,0.1);
    bp->setActivationFunction(ml::ANN_MLP::SIGMOID_SYM);
    bp->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 10000, /*FLT_EPSILON*/1e-6));
    cout<<"step7"<<endl;
    // 保存训练好的神经网络参数
    cout<<"step8"<<endl;
    bool trained = bp->train(train_data_mat,ml::ROW_SAMPLE,labels_mat);
    if (trained) {
        bp->save("bp_param");
    }

    // 创建训练好的神经网络
    //Ptr<ml::ANN_MLP>  
    bp = ml::ANN_MLP::load("bp_param");

    // 显示分类的结果
    cout<<"step9"<<endl;
    Vec3b black(0, 0, 0), white(255, 255, 255);
    Mat res=imread("sample8.jpg");
    imshow("BP Simple Example1", img);
    for (int i=0; i<img.rows; ++i) {
        for (int j=0; j<img.cols; ++j) {
            Mat sample_mat = (Mat_<float>(1, 3) << res.at<Vec3b>(i,j)[0], res.at<Vec3b>(i,j)[1],res.at<Vec3b>(i,j)[2]);
            Mat response_mat;
            bp->predict(sample_mat,response_mat);
            float response = response_mat.ptr<float>(0)[0];
            if (response > 0.5) {
                img.at<Vec3b>(i, j) = white;
            } else if (response < 0.5) {
                img.at<Vec3b>(i, j) = black;
            }
        }
    }
    cout<<"step10"<<endl;
    // 画出训练样本数据
    // int thickness = -1;
    // int lineType = 8;
    // circle(img, Point(500, 60), 5, Scalar(255, 255, 255), thickness, lineType);
    // circle(img, Point(245, 40), 5, Scalar(255, 255, 255), thickness, lineType);
    // circle(img, Point(480, 250), 5, Scalar(255, 255, 255), thickness, lineType);
    // circle(img, Point(160, 380), 5, Scalar(0, 0, 255), thickness, lineType);
    // circle(img, Point(400, 25), 5, Scalar(255, 255, 255), thickness, lineType);
    // circle(img, Point(55, 400), 5, Scalar(0, 0, 255), thickness, lineType);

    imwrite("result.png", img);        // 保存训练的结果
    imshow("BP Simple Example2", img);
   

    waitKey(0);
}