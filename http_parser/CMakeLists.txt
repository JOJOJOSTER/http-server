add_library(http_parser_lib STATIC
  Http_Enums.h 
  Http_request.h 
  Http_request.cpp 
  Http_request_parse.h 
  Http_request_parse.cpp
  Http_response.h 
  Http_response.cpp
  Http_Header_Field.h
  Http_converter.h 
  Http_converter.cpp
  Http_response_converter.h
  Http_response_converter.cpp)


target_include_directories(http_parser_lib PUBLIC ${CMAKE_SOURCE_DIR}/http_parser)
