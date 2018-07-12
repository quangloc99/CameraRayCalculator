cmake_minimum_required(VERSION 2.8)
project(CameraRayCalculator)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_LIBS})

add_library(CameraRayCalculator CameraRayCalculator.cpp)
target_link_libraries(CameraRayCalculator ${OpenCV_LIBS})

add_executable(example example.cpp)
target_link_libraries(example ${OpenCV_LIBS} CameraRayCalculator)
