#include "Http_Enums.h"
#include "Http_response.h"
#include <string>

namespace jojojoster::http {

class Converter {

  Converter() = delete;
  Converter(const Converter *other) = delete;

public:
  // ----------------String to enum

  static std::string ConvertStringToLowerCase(const std::string &str);

  // Methods
  //
  static HTTP_METHODS_ENUM
  Convert_String_Method_To_Enum_HTTP_METHODS(const std::string &method);

  // Version
  //

  static HTTP_VERSION
  Convert_String_Version_To_Enum_HTTP_VERSION(const std::string &version);

  // HEADERS
  //

  static HTTP_REQUEST_HEADERS_FIELD_ENUM
  Convert_String_Header_Field_To_Enum_HTTP_Headers(
      const std::string &header_field);

  // ----------------Enum to string

  // Version
  static std::string
  Convert_Enum_HTTP_Version_To_String(HTTP_VERSION http_version_enum);

  // Headers (Request, Response)
  static std::string Convert_Enum_HTTP_Request_Headers_To_String(
      HTTP_REQUEST_HEADERS_FIELD_ENUM http_request_header_enum);

  static std::string Convert_Enum_HTTP_Response_Headers_To_String(
      HTTP_RESPONSE_HEADERS_FIELD_ENUM http_response_header_enum);

  // STATUS CODE
  static std::string Convert_Enum_HTTP_Status_Code_To_String_With_Number(
      HTTP_STATUS_CODE http_status_code_enum);

  // HTTP_response to std::String
  //
  // 1. Version           to                  std::string
  // 2. Status code       to                  std::string
  //
  // 3. Headers           to                  std::string
  //  while()
  //    3.1 HTTP_RESPONSE_HEADERS_FIELD_ENUM to std::string
  // 4. Body

  // ---------------HTTP_Reponse to std::string

  static std::string
  Convert_HTTP_Reponse_To_String(const HTTP_Response &Http_response);
};

} // namespace jojojoster::http
