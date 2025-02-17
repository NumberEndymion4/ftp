cmake_minimum_required(VERSION 3.24.0)

project(ftp-server VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(${PROJECT_NAME} main.cpp)

# target_include_directories(${PROJECT_NAME} PRIVATE ftp-common)
target_link_libraries(${PROJECT_NAME} PRIVATE ftp-common)

add_subdirectory(tests)
