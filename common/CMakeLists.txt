cmake_minimum_required(VERSION 3.24.0)

project(ftp-common LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

FetchContent_Declare(
    asio
    GIT_REPOSITORY git@github.com:chriskohlhoff/asio.git
    GIT_TAG asio-1-32-0
)
FetchContent_MakeAvailable(asio)

find_package(Threads REQUIRED)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/private/asio_broadcast.cpp
        src/private/asio_broadcast.h
        src/private/asio_client_connection.cpp
        src/private/asio_client_connection.h
        src/private/asio_server_connection.cpp
        src/private/asio_server_connection.h
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
    PRIVATE
        ${asio_SOURCE_DIR}/asio/include
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Threads::Threads # TODO: Get rid of 'asio' threading.
)
