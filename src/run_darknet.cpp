#include <iostream>
#include <string>
#include <vector>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include "opencv2/cudabgsegm.hpp"
#include "opencv2/cudalegacy.hpp"
#include "opencv2/cudaoptflow.hpp"
#include "opencv2/cudaarithm.hpp"
#include "opencv2/cudaobjdetect.hpp"

#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

extern "C" {
#include "darknet.h"
}

using namespace std;
using namespace cv;

//live stream from yolo darknet
Mat img_cpp;
struct detectedBox
{
    Point topLeft;
    Point bottomRight;
    string name;

};

std::vector<detectedBox> detectedobjects;

extern "C" void label_func(int tl_x, int tl_y, int br_x, int br_y, char *names){

   string str(names);
   Scalar color;

   if(str == "car"){
     color = Scalar(80, 127, 255);  //coral color
   }else if (str == "bus"){
     color = Scalar(0, 69, 255);     //orange color
   }else if (str == "person"){
     color = Scalar(0,215,255);      //gold color
   }else if (str == "motorbike"){
     color = Scalar(0,140,255);      //dark orange
   }else if (str == "bicycle"){
     color = Scalar(60,20,220);      //crimson
   }else if (str == "train"){
     color = Scalar(0,128,0);        //dark green
   }


   detectedBox tempstorage;

   tempstorage.topLeft = Point(tl_x,tl_y);
   tempstorage.bottomRight = Point(br_x,br_y);
   tempstorage.name = str;

  // detectedobjects.push_back(tempstorage);

   //std::cout << "Name: " << str << std::endl;
   putText(img_cpp, str, Point(tl_x,tl_y-10), FONT_HERSHEY_PLAIN, 2.0, color, 1.5);
   rectangle(img_cpp, Point(tl_x,tl_y), Point(br_x,br_y), color, 2, CV_AA);

}


extern "C" void load_frame(IplImage* copy){

    img_cpp = cv::cvarrToMat(copy);

    imshow("image",img_cpp);


    waitKey(5);
}


int main(int argc, char **argv){
  
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Rate loop_rate(10);

  
  load_darknet(0);


  while (ros::ok()){
     
     
     load_darknet(1);
     
     
     ros::spinOnce();
     loop_rate.sleep();
  }
  return 0;
}
