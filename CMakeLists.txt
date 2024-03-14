cmake_minimum_required(VERSION 3.28)
project(httplib_test)

set(CMAKE_CXX_STANDARD 17)

find_package(httplib REQUIRED)

add_executable(httplib_test main.cpp)

target_link_libraries(httplib_test httplib::httplib)


