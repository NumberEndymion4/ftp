cmake_minimum_required(VERSION 3.24.0)

project(ftp-common LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(${PROJECT_NAME} stub.cpp)
