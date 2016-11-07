cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

rosbuild_init()

find_package(CUDA REQUIRED)
find_package(OpenCV REQUIRED)

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

INCLUDE(FindCUDA)

INCLUDE_DIRECTORIES(/usr/local/cuda/include)

set(
    CUDA_NVCC_FLAGS
    ${CUDA_NVCC_FLAGS};
    -O3 -gencode arch=compute_52,code=sm_52
    )

add_definitions(-DGPU -DOPENCV)



#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.c" "src/*.cu" "src/*.h")

#Generate the static library from the sources
#cuda_add_library(cppfile SHARED ${SOURCES} OPTIONS -arch sm_20)


cuda_add_library(darknetlib ${SOURCES} OPTIONS -arch sm_20)
TARGET_LINK_LIBRARIES(darknetlib m pthread stdc++ cublas curand ${OpenCV_LIBS})

rosbuild_add_executable(test2 src/run_darknet.cpp)

TARGET_LINK_LIBRARIES(test2 m pthread stdc++ cublas curand ${OpenCV_LIBS} darknetlib)

#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
#install(TARGETS cppfile DESTINATION /home/hxhx/darknet-cmake/obj)
