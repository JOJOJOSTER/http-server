cmake_minimum_required(VERSION 3.15)
project(http-server)

set(CMAKE_CXX_STANDARD 17)

# Add http_parser_lib
add_subdirectory(http_parser)

# Add jsoncpp_lib
add_subdirectory(jsoncpp)

add_executable(http_server example/http-server.cpp )
target_link_libraries(http_server http_parser_lib jsoncpp_lib )

message("SOURCE DIR : ${CMAKE_SOURCE_DIR}")

# TESTS 

message( STATUS "Compiling tests")

enable_testing()
add_subdirectory(googletest)

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
