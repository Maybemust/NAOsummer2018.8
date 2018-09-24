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
#include <opencv2/opencv.hpp>
#include "avoidcollision.h"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;
using namespace AL;
#define PI 3.14159
//int rightdown_x, rightdown_y, leftdown_x, leftdown_y, rightup_x, rightup_y, leftup_x, leftup_y;
cv::Mat imgHeader;


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
        
	AL::ALValue names1 = "HeadPitch";
	AL::ALValue angleLists = 10.2 * PI / 180;
	AL::ALValue timeLists = 1.0f;
	bool isAbsolute = true;
	motionProxy.angleInterpolation(names1, angleLists, timeLists, isAbsolute);

  	cout<<"*************************"<<"11111"<<"*********************"<<endl;
	while (true)
	{ 
		ALValue img = camProxy.getImageRemote(clientName);
		imgHeader.data = (uchar*) img[6].GetBinary();     
		camProxy.releaseImage(clientName);
		Mat image = imgHeader.clone();                    
	    imshow("image",image);
	    Mat g_srcImage,dstImage;
    	vector<Mat> g_vChannels;

    	g_srcImage=image;
    //imshow("原图",g_srcImage);
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
	       	waitKey(50);
	}
}