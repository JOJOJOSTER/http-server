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
  http_parser/Http_response.cpp
  http_parser/Http_Header_Field.h
  http_parser/Http_converter.h 
  http_parser/Http_converter.cpp
  http_parser/Http_response_converter.h
  http_parser/Http_response_converter.cpp)

add_executable(test_http_converter test/test_HTTP_Converter.cpp)
target_link_libraries(test_http_converter gtest gmock http_parser_lib)

add_test(test_http_converter "./test_http_converter")

add_executable(tests_http_request test/test_HTTP_Request.cpp)
target_link_libraries(tests_http_request gtest gmock http_parser_lib)

add_test(tests_http_request "./tests_http_request")

add_executable(tests_http_response test/test_HTTP_Response.cpp)
target_link_libraries(tests_http_response gtest gmock http_parser_lib)

add_test(tests_http_response "./tests_http_response")

add_executable(test_http_response_converter test/test_HTTP_Response_To_String.cpp)
target_link_libraries(test_http_response_converter gtest gmock http_parser_lib)

add_test(test_http_response_converter "./test_http_response_converter")
