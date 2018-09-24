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
#include "dragcar.h"
#include <unistd.h>

#include "wxzSVM.h"

#include <iostream>
#include <string>

using namespace cv;
using namespace std;
using namespace AL;
#define PI 3.14159
int rightdown_x, rightdown_y, leftdown_x, leftdown_y, rightup_x, rightup_y, leftup_x, leftup_y;
cv::Mat imgHeader;


dragcar::dragcar(boost::shared_ptr<ALBroker> pBroker, const std::string& pName) :
	ALModule(pBroker, pName),
	camProxy(getParentBroker()),
	motionProxy(getParentBroker()),
	postureProxy(getParentBroker()),
	clientName(" ")
{
	setModuleDescription("");
	functionName("start", getName(), "");
	BIND_METHOD(dragcar::start);
}

void dragcar::exit()
{
	AL::ALModule::exit();
}

void dragcar::init()
{
	start();
}

dragcar::~dragcar()
{

}

void dragcar::start()
{
	motionProxy.wakeUp();
	postureProxy.goToPosture("StandInit", 0.5);

	AL::ALValue config = AL::ALValue::array(AL::ALValue::array("LeftStepHeight", 0.02), AL::ALValue::array("RightStepHeight", 0.02), AL::ALValue::array("LeftMaxStepX", 0.04), AL::ALValue::array("RightMaxStepX", 0.04));

	camProxy.setActiveCamera(0);
	camProxy.setParameter(0, 12, 0);
	clientName = camProxy.subscribe("test", kQVGA, kBGRColorSpace, 5);
	imgHeader = cv::Mat(cv::Size(320, 240), CV_8UC3);

	AL::ALValue names1 = "HeadYaw";
	AL::ALValue angleLists = -3.1415926/9.0;//10.2 * PI / 180;
	AL::ALValue timeLists = 1.0f;
	bool isAbsolute = true;
	//change the angle of the head and the angleLists need to low down
	motionProxy.angleInterpolation(names1, angleLists, timeLists, isAbsolute);

	int gqs_x  = 80;//guoqushang开始加速直走
	int gqs_y  = 100;
	int gqx_x  = 60;//guoquxia开始加速直走
	int gqx_y  = 230;
	int py_y    = 0;//pingyi，绕过前一个柱子开始拐弯 the distant away from the obstacle infront
	int ldy_x   = 200;//lidehenyuan，离得很远
	int ldj_x    = 80;//lidejin，离得近
	int ldj_y    = 180;
	int judgepass = 240;

	int direction = 0; //go right = -1  and go left = 1  and go straight = 0
	int leftboundry = 270; //while going right, if the obstacle is left enough
	int rightboundry = 50; //similar to above
	// waitKey(1000);
	wxzSVM svm;
	cout << "*************************" << "11111" << "*********************" << endl;
	int i=0;
	int sum=0;
	int total=0;
	//drag();
	while(i<4)
	{	
		i++;
		ALValue img = camProxy.getImageRemote(clientName);
		//cout<<'2'<<endl;
		imgHeader.data = (uchar*) img[6].GetBinary();
		//cout<<'3'<<endl;
		camProxy.releaseImage(clientName);
		//cout<<'4'<<endl;
		Mat image = imgHeader.clone();
		//cout<<'5'<<endl;
		imshow("image", image);
		waitKey(10);
		//cout<<'6'<<endl;
		svm.SVMFind(1, image);
		sum+=svm.center_x();
		
	}
	sum=sum/4.0;
	cout<<sum<<endl;
	if (sum > 160)
	{
			direction = 1;
			cout<<"left"<<endl;
	}
	else
	{
			direction = 1;
			cout<<"right"<<endl;
	}
	while (true)
	{
		ALValue img = camProxy.getImageRemote(clientName);
		imgHeader.data = (uchar*) img[6].GetBinary();
		camProxy.releaseImage(clientName);
		Mat image = imgHeader.clone();
		imshow("image", image);
		waitKey(15);
		svm.SVMFind(1, image);
		motionProxy.moveToward(0.8, 0, 0, config);
		cout<<svm.rightdown_x() - svm.leftdown_x()<<endl;
		if (svm.rightdown_x() - svm.leftdown_x() > 160)
			break;
		//in order to prevent robot from losing obstacle for too much time and that can be deleted
		// if(svm.area()==0) 
		// 	numout++;
		// if(svm.area()!=0)
		// 	numout=0;
		// if(numout==15)
		// 	break;
		total++;
	}
	cout<<"_________________stop__________________"<<endl;
	motionProxy.moveToward(0, 0, 0, config);	
	waitKey(500);
	while (true)
	{
		//cout<<'1'<<endl;
		ALValue img = camProxy.getImageRemote(clientName);
		//cout<<'2'<<endl;
		imgHeader.data = (uchar*) img[6].GetBinary();
		//cout<<'3'<<endl;
		camProxy.releaseImage(clientName);
		//cout<<'4'<<endl;
		Mat image = imgHeader.clone();
		//cout<<'5'<<endl;
		imshow("image", image);
		waitKey(10);
		//cout<<'6'<<endl;
		svm.SVMFind(1, image);
		total++;
		//cout<<'7'<<endl;
		/*0-1，右前走*/
		// if(rightdown_x < ldy_x)
		// 	motionProxy.moveToward(0.1, -0.8, 0);
		// else
		// 	motionProxy.moveToward(0.1, 0.8, 0);
		// if(( rightup_x < gqs_x && rightup_y > gqs_y)||(rightdown_x < gqx_x && rightdown_y > gqx_y))
		// 	break;
		// if(rightdown_y > ldj_y && rightdown_x > ldj_x)
		// 	motionProxy.moveToward(0.1, -0.8, 0);
		motionProxy.moveToward(0.2, direction * 0.5, 0);
		if ((direction == 1 && svm.leftdown_x() > leftboundry) || (direction == -1 && svm.rightdown_x() < rightboundry))
			break;
		cout<<svm.rightdown_x()<<" "<<svm.leftdown_x()<<endl;
	}

	direction=-1*direction;
	/*直走*/
	// while (true)
	// {
	// 	ALValue img = camProxy.getImageRemote(clientName);
	// 	imgHeader.data = (uchar*) img[6].GetBinary();
	// 	camProxy.releaseImage(clientName);
	// 	Mat image = imgHeader.clone();
	// 	imshow("image", image);
	// 	waitKey(15);
	// 	svm.SVMFind(1, image);
	// 	motionProxy.moveToward(0.6, 0, 0, config);
	// 	cout<<svm.rightdown_x() - svm.leftdown_x()<<endl;
	// 	//if (svm.rightdown_x() - svm.leftdown_x() > 110)
	// 	if(svm.area()==0)
	// 		break;
	// 	total++;
	// 	//in order to prevent robot from losing obstacle for too much time and that can be deleted
	// 	// if(svm.area()==0) 
	// 	// 	numout++;
	// 	// if(svm.area()!=0)
	// 	// 	numout=0;
	// 	// if(numout==15)
	// 	// 	break;
	// }
	// total=total+200;
	// while(total-->0){
	// 	cout<<total<<endl;
	// motionProxy.moveToward(0.6, 0.05*direction, 0, config);       
	// }          
	cout<<"222222222"<<endl;
	motionProxy.moveTo(0.5,0.0,0.0);
	motionProxy.angleInterpolation(names1, 3.1415926/9.0, timeLists, isAbsolute);
	motionProxy.moveTo(0.5,-0.6,0.0);
	motionProxy.moveTo(0.4,0.0,0.0);
	//motionProxy.moveTo(1.8,0.0,0.0);
	motionProxy.moveToward(0.0, 0.0, 0, config);   
	sleep(2);    
	camProxy.unsubscribe(clientName);
}


//drag car
void dragcar::drag()
{
// Choregraphe simplified export in c++.
// Add #include <alproxies/almotionproxy.h> at the beginning of this file.
std::vector<std::string> names;
AL::ALValue times, keys;
names.reserve(26);
times.arraySetSize(26);
keys.arraySetSize(26);

names.push_back("HeadPitch");
times[0].arraySetSize(3);
keys[0].arraySetSize(3);

times[0][0] = 0.52;
keys[0][0] = -0.0138481;
times[0][1] = 1.44;
keys[0][1] = -0.0138481;
times[0][2] = 5.28;
keys[0][2] = -0.01845;

names.push_back("HeadYaw");
times[1].arraySetSize(3);
keys[1].arraySetSize(3);

times[1][0] = 0.52;
keys[1][0] = -0.00617791;
times[1][1] = 1.44;
keys[1][1] = -0.00617791;
times[1][2] = 5.28;
keys[1][2] = -0.00617791;

names.push_back("LAnklePitch");
times[2].arraySetSize(3);
keys[2].arraySetSize(3);

times[2][0] = 0.52;
keys[2][0] = -0.357464;
times[2][1] = 1.44;
keys[2][1] = -0.346725;
times[2][2] = 5.28;
keys[2][2] = -0.352862;

names.push_back("LAnkleRoll");
times[3].arraySetSize(3);
keys[3].arraySetSize(3);

times[3][0] = 0.52;
keys[3][0] = -0.00455999;
times[3][1] = 1.44;
keys[3][1] = -0.00455999;
times[3][2] = 5.28;
keys[3][2] = -0.00916195;

names.push_back("LElbowRoll");
times[4].arraySetSize(3);
keys[4].arraySetSize(3);

times[4][0] = 0.52;
keys[4][0] = -0.984786;
times[4][1] = 1.44;
keys[4][1] = -0.289883;
times[4][2] = 5.28;
keys[4][2] = -0.245399;

names.push_back("LElbowYaw");
times[5].arraySetSize(3);
keys[5].arraySetSize(3);

times[5][0] = 0.52;
keys[5][0] = -1.36223;
times[5][1] = 1.44;
keys[5][1] = -1.38371;
times[5][2] = 5.28;
keys[5][2] = -1.38371;

names.push_back("LHand");
times[6].arraySetSize(3);
keys[6].arraySetSize(3);

times[6][0] = 0.52;
keys[6][0] = 0.2596;
times[6][1] = 1.44;
keys[6][1] = 0.974;
times[6][2] = 5.28;
keys[6][2] = 0.2776;

names.push_back("LHipPitch");
times[7].arraySetSize(3);
keys[7].arraySetSize(3);

times[7][0] = 0.52;
keys[7][0] = -0.452487;
times[7][1] = 1.44;
keys[7][1] = -0.452487;
times[7][2] = 5.28;
keys[7][2] = -0.450955;

names.push_back("LHipRoll");
times[8].arraySetSize(3);
keys[8].arraySetSize(3);

times[8][0] = 0.52;
keys[8][0] = -0.00762796;
times[8][1] = 1.44;
keys[8][1] = -0.00762796;
times[8][2] = 5.28;
keys[8][2] = -0.00455999;

names.push_back("LHipYawPitch");
times[9].arraySetSize(3);
keys[9].arraySetSize(3);

times[9][0] = 0.52;
keys[9][0] = 0.00464392;
times[9][1] = 1.44;
keys[9][1] = 0.00464392;
times[9][2] = 5.28;
keys[9][2] = 0.00464392;

names.push_back("LKneePitch");
times[10].arraySetSize(3);
keys[10].arraySetSize(3);

times[10][0] = 0.52;
keys[10][0] = 0.699462;
times[10][1] = 1.44;
keys[10][1] = 0.699462;
times[10][2] = 5.28;
keys[10][2] = 0.70253;

names.push_back("LShoulderPitch");
times[11].arraySetSize(3);
keys[11].arraySetSize(3);

times[11][0] = 0.52;
keys[11][0] = 1.44192;
times[11][1] = 1.44;
keys[11][1] = 1.68276;
times[11][2] = 5.28;
keys[11][2] = 1.626;

names.push_back("LShoulderRoll");
times[12].arraySetSize(3);
keys[12].arraySetSize(3);

times[12][0] = 0.52;
keys[12][0] = 0.27301;
times[12][1] = 1.44;
keys[12][1] = 0.243864;
times[12][2] = 5.28;
keys[12][2] = 0.200912;

names.push_back("LWristYaw");
times[13].arraySetSize(3);
keys[13].arraySetSize(3);

times[13][0] = 0.52;
keys[13][0] = 0.0137641;
times[13][1] = 1.44;
keys[13][1] = -0.247016;
times[13][2] = 5.28;
keys[13][2] = -0.0813439;

names.push_back("RAnklePitch");
times[14].arraySetSize(3);
keys[14].arraySetSize(3);

times[14][0] = 0.52;
keys[14][0] = -0.351244;
times[14][1] = 1.44;
keys[14][1] = -0.351244;
times[14][2] = 5.28;
keys[14][2] = -0.346642;

names.push_back("RAnkleRoll");
times[15].arraySetSize(3);
keys[15].arraySetSize(3);

times[15][0] = 0.52;
keys[15][0] = 0.00157595;
times[15][1] = 1.44;
keys[15][1] = 0.00157595;
times[15][2] = 5.28;
keys[15][2] = 4.19617e-05;

names.push_back("RElbowRoll");
times[16].arraySetSize(3);
keys[16].arraySetSize(3);

times[16][0] = 0.52;
keys[16][0] = 0.978734;
times[16][1] = 1.44;
keys[16][1] = 0.0706061;
times[16][2] = 5.28;
keys[16][2] = 0.105888;

names.push_back("RElbowYaw");
times[17].arraySetSize(3);
keys[17].arraySetSize(3);

times[17][0] = 0.52;
keys[17][0] = 1.36522;
times[17][1] = 1.44;
keys[17][1] = 1.56464;
times[17][2] = 5.28;
keys[17][2] = 1.59225;

names.push_back("RHand");
times[18].arraySetSize(3);
keys[18].arraySetSize(3);

times[18][0] = 0.52;
keys[18][0] = 0.2572;
times[18][1] = 1.44;
keys[18][1] = 0.9788;
times[18][2] = 5.28;
keys[18][2] = 0;

names.push_back("RHipPitch");
times[19].arraySetSize(3);
keys[19].arraySetSize(3);

times[19][0] = 0.52;
keys[19][0] = -0.454105;
times[19][1] = 1.44;
keys[19][1] = -0.443368;
times[19][2] = 5.28;
keys[19][2] = -0.446436;

names.push_back("RHipRoll");
times[20].arraySetSize(3);
keys[20].arraySetSize(3);

times[20][0] = 0.52;
keys[20][0] = 0.00617791;
times[20][1] = 1.44;
keys[20][1] = -0.00609397;
times[20][2] = 5.28;
keys[20][2] = 0.00310993;

names.push_back("RHipYawPitch");
times[21].arraySetSize(3);
keys[21].arraySetSize(3);

times[21][0] = 0.52;
keys[21][0] = 0.00464392;
times[21][1] = 1.44;
keys[21][1] = 0.00464392;
times[21][2] = 5.28;
keys[21][2] = 0.00464392;

names.push_back("RKneePitch");
times[22].arraySetSize(3);
keys[22].arraySetSize(3);

times[22][0] = 0.52;
keys[22][0] = 0.70108;
times[22][1] = 1.44;
keys[22][1] = 0.70108;
times[22][2] = 5.28;
keys[22][2] = 0.70108;

names.push_back("RShoulderPitch");
times[23].arraySetSize(3);
keys[23].arraySetSize(3);

times[23][0] = 0.52;
keys[23][0] = 1.4466;
times[23][1] = 1.44;
keys[23][1] = 1.67977;
times[23][2] = 5.28;
keys[23][2] = 1.60307;

names.push_back("RShoulderRoll");
times[24].arraySetSize(3);
keys[24].arraySetSize(3);

times[24][0] = 0.52;
keys[24][0] = -0.276162;
times[24][1] = 1.44;
keys[24][1] = -0.18719;
times[24][2] = 5.28;
keys[24][2] = -0.158044;

names.push_back("RWristYaw");
times[25].arraySetSize(3);
keys[25].arraySetSize(3);

times[25][0] = 0.52;
keys[25][0] = 0.0183661;
times[25][1] = 1.44;
keys[25][1] = 0.052114;
times[25][2] = 5.28;
keys[25][2] = 0.0981341;

try
{
  getParentBroker()->getMotionProxy()->angleInterpolation(names, keys, times, true);
}
catch(const std::exception&)
{

}


}

void dragcar::dropcar()
{
// Choregraphe simplified export in c++.
// Add #include <alproxies/almotionproxy.h> at the beginning of this file.
std::vector<std::string> names;
AL::ALValue times, keys;
names.reserve(26);
times.arraySetSize(26);
keys.arraySetSize(26);

names.push_back("HeadPitch");
times[0].arraySetSize(2);
keys[0].arraySetSize(2);

times[0][0] = 1.12;
keys[0][0] = -0.021518;
times[0][1] = 2.24;
keys[0][1] = -0.021518;

names.push_back("HeadYaw");
times[1].arraySetSize(2);
keys[1].arraySetSize(2);

times[1][0] = 1.12;
keys[1][0] = 0.00149202;
times[1][1] = 2.24;
keys[1][1] = 0.00149202;

names.push_back("LAnklePitch");
times[2].arraySetSize(2);
keys[2].arraySetSize(2);

times[2][0] = 1.12;
keys[2][0] = -0.351328;
times[2][1] = 2.24;
keys[2][1] = -0.351328;

names.push_back("LAnkleRoll");
times[3].arraySetSize(2);
keys[3].arraySetSize(2);

times[3][0] = 1.12;
keys[3][0] = -0.00455999;
times[3][1] = 2.24;
keys[3][1] = -0.00455999;

names.push_back("LElbowRoll");
times[4].arraySetSize(2);
keys[4].arraySetSize(2);

times[4][0] = 1.12;
keys[4][0] = -0.25767;
times[4][1] = 2.24;
keys[4][1] = -0.25767;

names.push_back("LElbowYaw");
times[5].arraySetSize(2);
keys[5].arraySetSize(2);

times[5][0] = 1.12;
keys[5][0] = -1.38524;
times[5][1] = 2.24;
keys[5][1] = -1.38524;

names.push_back("LHand");
times[6].arraySetSize(3);
keys[6].arraySetSize(3);

times[6][0] = 1.12;
keys[6][0] = 0.318;
times[6][1] = 2.24;
keys[6][1] = 0.9736;
times[6][2] = 3.12;
keys[6][2] = 0;

names.push_back("LHipPitch");
times[7].arraySetSize(2);
keys[7].arraySetSize(2);

times[7][0] = 1.12;
keys[7][0] = -0.455555;
times[7][1] = 2.24;
keys[7][1] = -0.455555;

names.push_back("LHipRoll");
times[8].arraySetSize(2);
keys[8].arraySetSize(2);

times[8][0] = 1.12;
keys[8][0] = -0.00149202;
times[8][1] = 2.24;
keys[8][1] = -0.00149202;

names.push_back("LHipYawPitch");
times[9].arraySetSize(2);
keys[9].arraySetSize(2);

times[9][0] = 1.12;
keys[9][0] = 0.00310993;
times[9][1] = 2.24;
keys[9][1] = 0.00310993;

names.push_back("LKneePitch");
times[10].arraySetSize(2);
keys[10].arraySetSize(2);

times[10][0] = 1.12;
keys[10][0] = 0.696393;
times[10][1] = 2.24;
keys[10][1] = 0.696393;

names.push_back("LShoulderPitch");
times[11].arraySetSize(2);
keys[11].arraySetSize(2);

times[11][0] = 1.12;
keys[11][0] = 1.6306;
times[11][1] = 2.24;
keys[11][1] = 1.6306;

names.push_back("LShoulderRoll");
times[12].arraySetSize(2);
keys[12].arraySetSize(2);

times[12][0] = 1.12;
keys[12][0] = 0.240796;
times[12][1] = 2.24;
keys[12][1] = 0.240796;

names.push_back("LWristYaw");
times[13].arraySetSize(2);
keys[13].arraySetSize(2);

times[13][0] = 1.12;
keys[13][0] = -0.159578;
times[13][1] = 2.24;
keys[13][1] = -0.122762;

names.push_back("RAnklePitch");
times[14].arraySetSize(2);
keys[14].arraySetSize(2);

times[14][0] = 1.12;
keys[14][0] = -0.34971;
times[14][1] = 2.24;
keys[14][1] = -0.34971;

names.push_back("RAnkleRoll");
times[15].arraySetSize(2);
keys[15].arraySetSize(2);

times[15][0] = 1.12;
keys[15][0] = 4.19617e-05;
times[15][1] = 2.24;
keys[15][1] = 4.19617e-05;

names.push_back("RElbowRoll");
times[16].arraySetSize(2);
keys[16].arraySetSize(2);

times[16][0] = 1.12;
keys[16][0] = 0.115092;
times[16][1] = 2.24;
keys[16][1] = 0.115092;

names.push_back("RElbowYaw");
times[17].arraySetSize(2);
keys[17].arraySetSize(2);

times[17][0] = 1.12;
keys[17][0] = 1.59992;
times[17][1] = 2.24;
keys[17][1] = 1.59992;

names.push_back("RHand");
times[18].arraySetSize(3);
keys[18].arraySetSize(3);

times[18][0] = 1.12;
keys[18][0] = 0.0348001;
times[18][1] = 2.24;
keys[18][1] = 0.9792;
times[18][2] = 3.12;
keys[18][2] = 0;

names.push_back("RHipPitch");
times[19].arraySetSize(2);
keys[19].arraySetSize(2);

times[19][0] = 1.12;
keys[19][0] = -0.452573;
times[19][1] = 2.24;
keys[19][1] = -0.452573;

names.push_back("RHipRoll");
times[20].arraySetSize(2);
keys[20].arraySetSize(2);

times[20][0] = 1.12;
keys[20][0] = -0.00762796;
times[20][1] = 2.24;
keys[20][1] = -0.00762796;

names.push_back("RHipYawPitch");
times[21].arraySetSize(2);
keys[21].arraySetSize(2);

times[21][0] = 1.12;
keys[21][0] = 0.00310993;
times[21][1] = 2.24;
keys[21][1] = 0.00310993;

names.push_back("RKneePitch");
times[22].arraySetSize(2);
keys[22].arraySetSize(2);

times[22][0] = 1.12;
keys[22][0] = 0.705682;
times[22][1] = 2.24;
keys[22][1] = 0.705682;

names.push_back("RShoulderPitch");
times[23].arraySetSize(2);
keys[23].arraySetSize(2);

times[23][0] = 1.12;
keys[23][0] = 1.58927;
times[23][1] = 2.24;
keys[23][1] = 1.58927;

names.push_back("RShoulderRoll");
times[24].arraySetSize(2);
keys[24].arraySetSize(2);

times[24][0] = 1.12;
keys[24][0] = -0.207132;
times[24][1] = 2.24;
keys[24][1] = -0.207132;

names.push_back("RWristYaw");
times[25].arraySetSize(2);
keys[25].arraySetSize(2);

times[25][0] = 1.12;
keys[25][0] = 0.151824;
times[25][1] = 2.24;
keys[25][1] = 0.151824;

try
{
  getParentBroker()->getMotionProxy()->angleInterpolation(names, keys, times, true);
}
catch(const std::exception&)
{

}


}