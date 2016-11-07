#Darknet#
For more information see the [Darknet project website](http://pjreddie.com/darknet).

For questions or issues please use the [Google Group](https://groups.google.com/forum/#!forum/darknet).


IMPORTANT!:

This is a variation of the darknet yolo fast rcnn project. This version integrates with ROS and tested with the following specs:

14.04 Ubuntu LTS
GTX 970
Cuda 7.5
OpenCV 3.1
ROS indigo

This version however may or may not work with cv_bridge. Depends on your system. 

There are a couple of file been modified:

darknet.c
darknet.h
yolo.c
run_darknet.cpp

These are the only files you need to modify to run yolo.weights and do a evalution.

To compile, shift this folder into somewhere you know and type "rosmake"

If you fail to compile, please rmb to run this:
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:'pwd'


