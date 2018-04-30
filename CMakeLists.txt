cmake_minimum_required(VERSION 2.8)
project(opencv_train)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(cpp)
