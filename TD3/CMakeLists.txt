cmake_minimum_required(VERSION 3.2)
project(TP-Algo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES td3.c)
add_executable(Tp-Algo ${SOURCE_FILES})