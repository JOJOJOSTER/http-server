#ifndef HTTP_RESPONSE_CONVERTER
#define HTTP_RESPONSE_CONVERTER

#include "Http_response.h"
#include <string>

namespace jojojoster::http {

class HTTP_Response_Converter {

  HTTP_Response_Converter() = delete;
  HTTP_Response_Converter(const HTTP_Response_Converter &other) = delete;

public:
  // HTTP_response to std::String
  //
  // 1. Version           to                  std::string
  // 2. Status code       to                  std::string
  //
  // 3. Headers           to                  std::string
  //  while()
  //    3.1 HTTP_RESPONSE_HEADERS_FIELD_ENUM to std::string
  // 4. Body
  //

  static std::string
  Convert_HTTP_Reponse_To_String(const HTTP_Response &Http_response);
};

} // namespace jojojoster::http

#endif // !HTTP_RESPONSE_CONVERTER
