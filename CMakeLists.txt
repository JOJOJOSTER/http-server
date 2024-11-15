cmake_minimum_required(VERSION 3.15)
project(http-server)

enable_testing()
add_subdirectory(googletest)

add_library(http_parser_lib SHARED
  http_parser/Http_Enums.h 
  http_parser/Http_request.h 
  http_parser/Http_request.cpp 
  http_parser/Http_request_parse.h 
  http_parser/Http_request_parse.cpp
  http_parser/Http_response.h 
  http_parser/Http_Header_Field.h
  http_parser/Http_converter.h 
  http_parser/Http_converter.cpp)

add_executable(test_converter test/test_HTTP_Converter.cpp)
target_link_libraries(test_converter gtest gmock http_parser_lib)

add_executable(tests test/test_HTTP_Request.cpp)
target_link_libraries(tests gtest gmock http_parser_lib)
