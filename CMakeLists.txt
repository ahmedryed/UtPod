cmake_minimum_required(VERSION 3.12)
project(UtPod)

set(CMAKE_CXX_STANDARD 14)

add_executable(UtPod utPod_driver.cpp UtPod.h song.h song.cpp UtPod.cpp)