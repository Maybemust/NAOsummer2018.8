#include <opencv2/opencv.hpp>

//version 1
// #include <vector>

// using namespace std;
// using namespace cv;

// int main()
// {
// 	VideoCapture cap(1);
// 	while(1)
// 	{
// 	Mat imageSource;// = imread("01.jpg");
// 	cap>>imageSource;
// 	imshow("original", imageSource);
// 	waitKey(10);
// 	vector<Mat> imageRGB;

// 	split(imageSource, imageRGB);

// 	double R, G, B;
// 	B = mean(imageRGB[0])[0];
// 	G = mean(imageRGB[1])[0];
// 	R = mean(imageRGB[2])[0];

// 	double KR, KG, KB;
// 	KB = (R + G + B) / (3 * B);
// 	KG = (R + G + B) / (3 * G);
// 	KR = (R + G + B) / (3 * R);

// 	imageRGB[0] = imageRGB[0] * KB;
// 	imageRGB[1] = imageRGB[1] * KG;
// 	imageRGB[2] = imageRGB[2] * KR;

// 	merge(imageRGB, imageSource);
// 	imshow("deal", imageSource);
// 	}
// 	waitKey();
// 	return 0;
// }



//version 2
// #include<iostream>
// using namespace cv;
// using namespace std;
// void myBGR2YUV(const Mat image,Mat &result)
// {
//     Mat_<Vec3b>::const_iterator it=image.begin<Vec3b>();
//     Mat_<Vec3f>::iterator rit=result.begin<Vec3f>();
//     Mat_<Vec3b>::const_iterator itend=image.end<Vec3b>();
// //遍历所有像素 并转为YUV，注意在opencv中每个彩色像素是按BGR顺序存储的
//     for(;it!=itend;++it,++rit)
//     {
//         (*rit)[0]=0.114*(*it)[0]+0.587*(*it)[1]+0.299*(*it)[2];//Y
//         (*rit)[1]=0.5*(*it)[0]-0.331264*(*it)[1]-0.168736*(*it)[2];//Cb 
//         (*rit)[2]=-0.081312*(*it)[0]-0.418688*(*it)[1]+0.5*(*it)[2];//Cr
//     }

// }


// //估计图像result的色温为Temperature，阈值phi默认为180
// void CountTemperature(const Mat result,Mat &Temperature ,const short phi=180)
// {
//     Mat_<Vec3f>::const_iterator rit=result.begin<Vec3f>();
//     Mat_<Vec3f>::const_iterator ritend=result.end<Vec3f>();
//     //遍历所有像素 估计色温
//     float Y=0,Cb=0,Cr=0,n=0,Z=0,Y1=0,Cb1=0,Cr1=0;
//     //const int phi=180;
//     for(;rit!=ritend;++rit,++n)
//     {
//         Y1=(*rit)[0];
//         Cb1=(*rit)[1];
//         Cr1=(*rit)[2];
//         Z=Y1-abs(Cb1)-abs(Cr1);
//         if (Z>phi)
//             {Y+=Y1;
//              Cb+=Cb1;
//              Cr+=Cr1;
//             }
//     }
//     //所有像素处理完了
//     Temperature.at<Vec3f>(0,0)[0]=Y/n;
//     Temperature.at<Vec3f>(0,0)[1]=Cb/n;
//     Temperature.at<Vec3f>(0,0)[2]=Cr/n;
// }
// //增益计算
// void gain(Mat Temperature,float &u,float&v,float lamda=0.05)
// {
//     float Y_T=Temperature.at<Vec3f>(0,0)[0];
//     float Cb_T=Temperature.at<Vec3f>(0,0)[1];
//     float Cr_T=Temperature.at<Vec3f>(0,0)[2];
//     //增益计算
// //  float u=1,lamda=0.05,v=1;//u是B通道增益，v是R通道增益
//     if(abs(Cb_T)>abs(Cr_T))
//         if(Cb_T>0)
//             u-=lamda;
//         else
//            u+=lamda;
//     else
//         if(Cr_T>0)
//             v-=lamda;
//         else
//            v+=lamda;

// }
// //色温校正

// void correctionImage(const Mat image,Mat &result,const float u ,const float v)
// {
//     Mat_<Vec3b>::const_iterator it=image.begin<Vec3b>();
//     Mat_<Vec3b>::const_iterator itend=image.end<Vec3b>();

//     Mat_<Vec3b>::iterator rit=result.begin<Vec3b>();
//     Mat_<Vec3b>::iterator ritend=result.end<Vec3b>();
//     //遍历所有像素 改变B和R通道的值
//     for(;it!=itend;++it,++rit)
//     {
//         (*rit)[0]=saturate_cast<uchar>(u*(*it)[0]);//B
//         (*rit)[1]=saturate_cast<uchar>((*it)[1]);//G
//         (*rit)[2]=saturate_cast<uchar>(v*(*it)[2]);//R

//     }


// }
// int main()
// {

// 	VideoCapture cap(1);
// 	while(1){
//     Mat image;//=imread("F:\\opencv\\exercise\\example_images\\building.jpg"); 
//     cap>>image;
//     namedWindow("OriginalImage");
//     imshow("OriginalImage",image);
//     if(!image.data)
//     {   
//     cout<<"图像加载失败"<<endl;
//     return -1;
//     }   
//     Mat result;//YUV格式
//     result.create(image.rows,image.cols,CV_32FC3);
//     Mat final;//白平衡后的BGR图像
//     final.create(image.rows,image.cols,image.type());

//     Mat Temperature(1,1, CV_32FC3,Scalar(100));//初始化色温为100
//     //BGR转为YUV
//     myBGR2YUV(image,result);
//      //估计色温
//     CountTemperature(result,Temperature);
//     float Cb_T=Temperature.at<Vec3f>(0,0)[1];
//     float Cr_T=Temperature.at<Vec3f>(0,0)[2];
//     float C=sqrt(Cb_T*Cb_T+Cr_T*Cr_T);
//     float u=1,lamda=0.05,v=1;//u是B通道增益，v是R通道增益

//     int index=0;//迭代次数
//     while (C>0.1&&index<80)
//     {

//         //增益计算 u,v
//         if (index>25)//
//             lamda=0.02;
//         if (index>40)//
//             lamda=0.005;
//             if (index>55)//
//             lamda=0.001;
//         gain(Temperature,u,v,lamda);

//         //色温校正后图像为final
//         correctionImage(image,final,u ,v);

//         //BGR转为YUV
//         myBGR2YUV(final,result);
//         //估计色温  
//         CountTemperature(result,Temperature);
//         //cb,cr是否足够小
//         Cb_T=Temperature.at<Vec3f>(0,0)[1];
//         Cr_T=Temperature.at<Vec3f>(0,0)[2];
//         C=sqrt(Cb_T*Cb_T+Cr_T*Cr_T);
//         ++index;
//         //cout<<"index="<<index<<" u="<<u<<"   v="<<v<<endl;

//     }
//     if(!index) image.copyTo(final);//拷贝
//     //cout<<"C="<<C<<"   Cb="<<Cb_T<<"   Cr="<<Cr_T<<endl;

//     //cout<<"图像加载成功"<<result.type()<<endl;
    
//     namedWindow("WhiteBalance");
//     imshow("WhiteBalance",final);
//     waitKey(5);
// 	}
//     waitKey();

//     return 0;
// }


//version 3
//该代码实现白平衡算法中的灰度世界法，能有效改善图像发红发蓝发绿的现象；

#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
using namespace std;
int main()
{
    Mat g_srcImage,dstImage;
    vector<Mat> g_vChannels;
    VideoCapture cap(1);
    while(1){
    //g_srcImage = imread("C:/Users/Administrator/Desktop/区分高架定位/01.jpg");
    	cap>>g_srcImage;
    imshow("原图",g_srcImage);
    //waitKey(0);

    //分离通道
    split(g_srcImage,g_vChannels);
    Mat imageBlueChannel = g_vChannels.at(0);
    Mat imageGreenChannel = g_vChannels.at(1);
    Mat imageRedChannel = g_vChannels.at(2);

    double imageBlueChannelAvg=0;
    double imageGreenChannelAvg=0;
    double imageRedChannelAvg=0;

    //求各通道的平均值
    imageBlueChannelAvg = mean(imageBlueChannel)[0];
    imageGreenChannelAvg = mean(imageGreenChannel)[0];
    imageRedChannelAvg = mean(imageRedChannel)[0];

    //求出个通道所占增益
    double K = (imageRedChannelAvg+imageGreenChannelAvg+imageRedChannelAvg)/3;
    double Kb = K/imageBlueChannelAvg;
    double Kg = K/imageGreenChannelAvg;
    double Kr = K/imageRedChannelAvg;

    //更新白平衡后的各通道BGR值
    addWeighted(imageBlueChannel,Kb,0,0,0,imageBlueChannel);
    addWeighted(imageGreenChannel,Kg,0,0,0,imageGreenChannel);
    addWeighted(imageRedChannel,Kr,0,0,0,imageRedChannel);

    merge(g_vChannels,dstImage);//图像各通道合并
    imshow("白平衡后图",dstImage);
    waitKey(5);
	}
    
    return 0;
}