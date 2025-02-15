cmake_minimum_required(VERSION 3.20.0)

project(ftp-common VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} stub.cpp)
