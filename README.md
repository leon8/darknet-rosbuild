![Darknet Logo](http://pjreddie.com/media/files/darknet-black-small.png)

#Darknet#
Darknet is an open source neural network framework written in C and CUDA. It is fast, easy to install, and supports CPU and GPU computation.

For more information see the [Darknet project website](http://pjreddie.com/darknet).

For questions or issues please use the [Google Group](https://groups.google.com/forum/#!forum/darknet).


IMPORTANT!:

option 1: unlinkable with ros
refer to c++ in c document online:
http://www.thegeekstuff.com/2013/01/mix-c-and-cpp/?utm_source=feedburner

run this command to obtain c++ .so file:
1. g++ -c -Wall -Werror -fPIC interface.cpp -DOPENCV -DGPU -I/usr/local/cuda/include/ -L/usr/local/cuda/lib64 -lcuda -lcudart -lcublas -lcurand

2.  g++ -shared -o libcppfile.so interface.o


OR

option 2: cmake

1. cd to build folder
2. cmake ..
3. make
4. export LD_LIBRARY_PATH=/home/hxhx/darknet-cmake/libfolder:$LD_LIBRARY_PATH


WORKING!

