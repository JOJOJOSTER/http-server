#include "Http_response_converter.h"
#include "Http_converter.h"

namespace jojojoster::http {

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

// TO-DO
// CRUTCH
// Class of this function friend for HTTP_Reponse class

std::string HTTP_Response_Converter::Convert_HTTP_Reponse_To_String(
    const HTTP_Response &Http_response) {

  std::string response_string;

  response_string = Converter::Convert_Enum_HTTP_Version_To_String(
      Http_response.GetVersion());
  response_string += ' ';
  response_string +=
      Converter::Convert_Enum_HTTP_Status_Code_To_String_With_Number(
          Http_response.GetStatusCode());
  response_string += "\r\n";

  for (const auto &header : Http_response.m_headers) {
    response_string +=
        Converter::Convert_Enum_HTTP_Response_Headers_To_String(header.first);
    response_string += ": ";
    response_string += header.second;
    response_string += "\r\n";
  }
  response_string += "\r\n";

  response_string += Http_response.GetBody();

  return response_string;
}

} // namespace jojojoster::http
