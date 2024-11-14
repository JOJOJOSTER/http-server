cmake_minimum_required(VERSION 3.15)
project(http-server)

enable_testing()
add_subdirectory(googletest)

add_executable(tests tests.cpp Http_request.h Http_request.cpp Http_Enums.h)
target_link_libraries(tests gtest gmock)
