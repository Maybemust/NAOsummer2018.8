#include <boost/shared_ptr.hpp>
#include <alproxies/alvideodeviceproxy.h>
#include <alvision/alimage.h>
#include <alvision/alvisiondefinitions.h>
#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <alproxies/altexttospeechproxy.h>
#include <qi/os.hpp>
#include <qi/log.hpp>
#include <alcommon/alproxy.h>
#include <alcommon/albroker.h>

// Opencv includes.
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "objectFinder.h"
#include "avoidcollision.h"
#include "ycylib2.h"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;
using namespace AL;
#define PI 3.14159
int rightdown_x, rightdown_y, leftdown_x, leftdown_y, rightup_x, rightup_y, leftup_x, leftup_y;
cv::Mat imgHeader;

void find(int num,Mat image)
{
        Mat sample1,sample2,sample3,bimg;
	sample1 = imread("/home/liyang/worktree2018/avoidobstacle/imagered.jpg");
	sample2 = imread("/home/liyang/worktree2018/avoidobstacle/imageyellow.jpg");	
	sample3 = imread("/home/liyang/worktree2018/avoidobstacle/imageblue.jpg");

	if(num == 1)
		{
		/////hsv
		Mat result1_hsv=imgProcess(image,sample1,0.07f,1);		//threshold 0.05~0.09
		///rgb
		ColorHistogram h;
		sample1=h.colorReduce(sample1,200);				//reduce 100~200
		image=h.colorReduce(image,200);
		Mat result1_rgb=imgProcess(image,sample1,0.05f,0);
		Mat result1_j= result1_hsv & result1_rgb;
		Mat result1_b=result1_hsv |result1_rgb;			// "&"  "|"
		bimg=result1_j;
		//bimg=result1_rgb;
		imshow("result_hsv",result1_hsv);
		imshow("result_rgb",result1_rgb);
		imshow("result_&",result1_j);
		imshow("result_|",result1_b);
                waitKey(50);
		}
	if(num == 2)
                {
		///hsv
                Mat result2_hsv=imgProcess(image,sample2,0.05f,1);
		///rgb
		ColorHistogram h;
		sample2=h.colorReduce(sample2,150);
		image=h.colorReduce(image,150);
		Mat result2_rgb=imgProcess(image,sample2,0.05f,0);
		Mat result2_j= result2_hsv & result2_rgb;
		Mat result2_b=result2_hsv |result2_rgb;			// "&"  "|"
		bimg=result2_j;

		imshow("result_hsv",result2_hsv);
		imshow("result_rgb",result2_rgb);
		imshow("result_&",result2_j);
		imshow("result_|",result2_b);
                waitKey(50);
                }
         if(num == 3)
                {
		///hsv
                Mat result3_hsv=imgProcess(image,sample3,0.07f,1);
		///rgb
		ColorHistogram h;
		sample3=h.colorReduce(sample3,100);
		image=h.colorReduce(image,100);
		Mat result3_rgb= imgProcess(image,sample3,0.07f,0);
		Mat result3_j= result3_hsv & result3_rgb;
		Mat result3_b=result3_hsv |result3_rgb;			// "&"  "|"
		bimg=result3_rgb;

		imshow("result_hsv",result3_hsv);
		imshow("result_rgb",result3_rgb);
		//imshow("result_both",result3_both);
		imshow("result_&",result3_j);
		imshow("result_|",result3_b);
                waitKey(50);
                }
		
	/*ColorHistogram hc;
		image = hc.colorReduce(image, 240);                //减色
		sample = hc.colorReduce(sample, 240);

		MatND hist = hc.getHistogram(sample);             //把减色的样图的直方图给hist
		ObjectFinder finder;
		finder.setHistogram(hist);
		finder.setThreshold(0.05f);
		Mat bimg = finder.find(image);                    //用finder来找image
		//imshow("bimg",bimg);                              //bimg是找到的图像
		//waitKey(500);*/
		Mat element5(5, 5, CV_8U, Scalar(1));
		Mat closed;
		morphologyEx(bimg , closed, MORPH_CLOSE, element5);

		Mat opened;
		morphologyEx(closed, opened, MORPH_OPEN, element5);

		vector < std::vector<cv::Point> > contours;
		findContours(opened, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
		Mat contoursimg(opened.size(), CV_8U, Scalar(255));
		Mat conimg = contoursimg.clone();
              
		drawContours(conimg, contours, -1, Scalar(0), 2);
	int cmax;
	int s[1000], i = 1, position = 160;
		
	if (contours.size() > 0)
	{
		vector<std::vector<cv::Point> >::iterator itc = contours.begin();
		while (itc != contours.end())
		{
			s[i] = itc->size();
			//cout << s[i] << endl;
			++i;
			++itc;
		}
		for (int l = 2; l <= i - 1; l++)
			if (s[l - 1] > s[l])
				s[l] = s[l - 1];
		cmax = s[i - 1];
		itc = contours.begin();
		while (itc != contours.end())
		{
			if (itc->size() < cmax)
			{
				itc = contours.erase(itc);
			}
			else
				++itc;
		}
		drawContours(contoursimg, contours, -1, Scalar(0), 2);
		Mat result = contoursimg.clone();
		Rect r = boundingRect(Mat(contours[0]));
		rectangle(result, r, Scalar(0), 2);
		imshow("result",result);
               // waitKey(50);
			
		rightdown_x = r.x + r.width;
		rightdown_y = r.y + r.height;
        leftdown_x = r.x;
        leftdown_y = r.y+r.height;
        rightup_x = r.x + r.width;
        rightup_y = r.y ;
        leftup_x = r.x;
        leftup_y = r.y;
		
	}
	else
		return ;
}
AvoidCollision::AvoidCollision(boost::shared_ptr<ALBroker> pBroker,const std::string& pName) :
		ALModule(pBroker, pName), 
		camProxy(getParentBroker()),
		motionProxy(getParentBroker()), 
		postureProxy(getParentBroker()),
		clientName(" ")
	{
		setModuleDescription("");
		functionName("start", getName(), "");
		BIND_METHOD(AvoidCollision::start);
	}

void AvoidCollision::exit()
{
	AL::ALModule::exit();
}

void AvoidCollision::init()
{
	start();
}

AvoidCollision::~AvoidCollision()
{

}

void AvoidCollision::start()
{
	motionProxy.wakeUp();
	postureProxy.goToPosture("StandInit", 0.5);

	AL::ALValue config = AL::ALValue::array(AL::ALValue::array("LeftStepHeight", 0.04), AL::ALValue::array("RightStepHeight", 0.04), AL::ALValue::array("LeftMaxStepX", 0.08), AL::ALValue::array("RightMaxStepX", 0.08));

              camProxy.setActiveCamera(0);
	clientName = camProxy.subscribe("test", kQVGA, kBGRColorSpace, 5);
	imgHeader = cv::Mat(cv::Size(320, 240), CV_8UC3);
        
	AL::ALValue names1 = "HeadYaw";
	AL::ALValue angleLists = 0.0f;//10.2 * PI / 180;
	AL::ALValue timeLists = 1.0f;
	bool isAbsolute = true;
	motionProxy.angleInterpolation(names1, angleLists, timeLists, isAbsolute);

	int gqs_x  = 80;//guoqushang开始加速直走
	int gqs_y  = 100;
	int gqx_x  = 60;//guoquxia开始加速直走
	int gqx_y  = 230;
	int py_y    = 150;//pingyi，绕过前一个柱子开始拐弯 the distant away from the obstacle infront
	int ldy_x   = 80;//lidehenyuan，离得很远
	int ldj_x    = 80;//lidejin，离得近
	int ldj_y    = 180;
	int judgepass=240;

	int direction=0;//go right = -1  and go left = 1  and go straight = 0
	int leftboundry=80;//while going right, if the obstacle is left enough
	int rightboundry=240;//similar to above

	float speed=0.4f;//the speed of the robot

  	cout<<"*************************"<<"11111"<<"*********************"<<endl;
	while (true)
	{ 
		cout<<'1'<<endl;
		ALValue img = camProxy.getImageRemote(clientName);
		cout<<'2'<<endl;
		imgHeader.data = (uchar*) img[6].GetBinary();   
		cout<<'3'<<endl;  
		camProxy.releaseImage(clientName);
		cout<<'4'<<endl;
		Mat image = imgHeader.clone();  
		cout<<'5'<<endl;                  
	       	imshow("image",image);
	       	waitKey(50);
		find(1,image);
	             /*0-1，右前走*/
		// if(rightdown_x < ldy_x)
		// 	motionProxy.moveToward(0.1, -0.8, 0);
		// else
		// 	motionProxy.moveToward(0.1, 0.8, 0);
		// if(( rightup_x < gqs_x && rightup_y > gqs_y)||(rightdown_x < gqx_x && rightdown_y > gqx_y))
		// 	break;
		// if(rightdown_y > ldj_y && rightdown_x > ldj_x)
		// 	motionProxy.moveToward(0.1, -0.8, 0);
		float radio=1.0;
		if((leftup_x+rightup_x)/2>160)
		{
			//motionProxy.moveToward(speed, speed*(rightdown_x+240-rightdown_y+20)/(240-rightdown_y), 0);
			direction=1;
			radio=(rightdown_x+240-rightdown_y+20)/(240-rightdown_y);
		}
		else
		{
			//motionProxy.moveToward(speed, -1*speed*(rightdown_x+240-rightdown_y+20)/(240-rightdown_y), 0);
			direction=-1;
			radio=(160-leftdown_x+240-rightdown_y+20)/(240-rightdown_y);
		}

		if(speed*radio>0.8)
			radio=0.8/speed;
		motionProxy.moveToward(speed,direction*speed*radio,0);
		if((rightdown_x < leftboundry|| leftdown_x>rightboundry)&&(leftdown_y>judgepass))
			break;
	}
        /*1-2之间直走*/
	cout<<"*********************"<<" 1-----2"<<"**********************************"<<endl;
	while(true) 
	{
        	ALValue img = camProxy.getImageRemote(clientName);
	imgHeader.data = (uchar*) img[6].GetBinary();     
	camProxy.releaseImage(clientName);
	Mat image = imgHeader.clone();
	imshow("image",image);
	waitKey(50);
	find(2,image);
	motionProxy.moveToward(0.6, 0, 0, config);
	if(rightdown_y > py_y)  
		break;
	}
	cout <<"*******************************"<< 2222 <<"*****************************************"<<endl;
        /*绕过第二个柱子*/
	direction=-1*direction;
	while (true)
	{ 
    ALValue img = camProxy.getImageRemote(clientName);
	imgHeader.data = (uchar*) img[6].GetBinary();     
	camProxy.releaseImage(clientName);
	Mat image = imgHeader.clone();
	waitKey(50);
	find(3,image);
	// if(leftdown_x > (320 - ldy_x))
	// 	motionProxy.moveToward(0.8, 1, 0);
	// else
    //   		motionProxy.moveToward(0.6, 1, 0);
	// if((leftup_x > (320 - gqs_x) && leftup_y > (240 - gqs_y)) || (leftdown_x > (320 - gqx_x) && leftdown_y >  (240 - gqx_y)))
	// 	break;
	// if(leftdown_y > ldj_y && leftdown_x < ldj_x)
	// 	motionProxy.moveToward(0.4, 1, 0);
	// 
	float radio=1;
	if(direction==-1)
	{
		radio=(160-leftdown_x+240-rightdown_y+20)/(240-rightdown_y);
	}
	else{
		radio=(rightdown_x+240-rightdown_y+20)/(240-rightdown_y);
	}
	if(speed*radio>0.8)
			radio=0.8/speed;
	motionProxy.moveToward(speed,direction*speed*radio,0);

	if((direction==-1 && leftdown_x>rightboundry)&&(leftdown_y>judgepass))
	{
		break;
	}
	if((direction==1 && rightdown_x>leftboundry)&&(leftdown_y>judgepass))
	{
		break;
	}

	

	}
	direction=-1*direction;
        /*2-3之间直走*/
	cout<<"*********************"<<" 2-----3"<<"**********************************"<<endl;
	while(true) 
	{
              ALValue img = camProxy.getImageRemote(clientName);
	imgHeader.data = (uchar*) img[6].GetBinary();     
	camProxy.releaseImage(clientName);
	Mat image = imgHeader.clone();
      	imshow("image",image);
      	waitKey(50);
	find(3,image);
	motionProxy.moveToward(0.6, 0, 0, config);
	if(leftdown_y > py_y)
		break;
	}
	cout<<"*********************"<<33333<<"**********************************"<<endl;
	 //如果 机器人看不见下一个障碍物，那么需要机器人转头
	// double  maxx =  rightdown_x - leftdown_x;
	// double  maxy = rightdown_y - rightup_y;
	// while(maxx * maxy < 400)
	// {
	// AL::ALValue names2 = "HeadYaw";
	// motionProxy.angleInterpolation(names2, 30.2 * PI / 180, timeLists, isAbsolute);
	// motionProxy.angleInterpolation(names2, -30.2 * PI / 180, timeLists, isAbsolute);
	// motionProxy.angleInterpolation(names2, 0, timeLists, isAbsolute);
	// motionProxy.moveToward(0, 0,0.5) ;
	// ALValue img = camProxy.getImageRemote(clientName);
	// imgHeader.data = (uchar*) img[6].GetBinary(); 
 //       	camProxy.releaseImage(clientName);
	// Mat image = imgHeader.clone();
 //     	imshow("image",image);
 //        	waitKey(50);
	// find(3,image);
	// maxx =  rightdown_x - leftdown_x;
	// maxy = rightdown_y - rightup_y;
	// }
	
	while (true)
	{
    	ALValue img = camProxy.getImageRemote(clientName);
	imgHeader.data = (uchar*) img[6].GetBinary();     
       	camProxy.releaseImage(clientName);
	Mat image = imgHeader.clone();
     	imshow("image",image);
        	waitKey(50);
	find(1,image);
	
	// if(rightdown_x < ldy_x)
	// 	motionProxy.moveToward(0.8, -0.8, 0);
	// else
	// 	motionProxy.moveToward(0.6, -0.8, 0);
	// if((rightup_x < gqs_x && rightup_y > gqs_y)||(rightdown_x < gqx_x && rightdown_y > gqx_y))
	// 	break;
	// if(rightdown_y > ldj_y && rightdown_x > ldj_x)
	// 	motionProxy.moveToward(0.4, -0.8, 0);
	float radio=1;
	if(direction==-1)
	{
		radio=(160-leftdown_x+240-rightdown_y+20)/(240-rightdown_y);
	}
	else{
		radio=(rightdown_x+240-rightdown_y+20)/(240-rightdown_y);
	}
	if(speed*radio>0.8)
			radio=0.8/speed;
	motionProxy.moveToward(speed,direction*speed*radio,0);

	if((direction==-1 && leftdown_x>rightboundry)&&(leftdown_y>judgepass))
	{
		break;
	}
	if((direction==1 && rightdown_x>leftboundry)&&(leftdown_y>judgepass))
	{
		break;
	}

	}
	
	motionProxy.moveToward(0.6, 0, 0, config);                 //   能否准确到达 终点
	camProxy.unsubscribe(clientName);
}