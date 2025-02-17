cmake_minimum_required(VERSION 3.24.0)

project(ftp)

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.16.0
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(common)
add_subdirectory(server)
add_subdirectory(client)
