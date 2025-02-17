cmake_minimum_required(VERSION 3.24.0)

project(ftp-server-tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(${PROJECT_NAME} test1.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest_main)

add_test(NAME server-test-1 COMMAND ${PROJECT_NAME})
