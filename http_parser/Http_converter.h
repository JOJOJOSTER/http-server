#include "Http_Enums.h"
#include <string>

namespace jojojoster::http {

class Converter {
public:
  static std::string ConvertStringToLowerCase(const std::string &str);

  // Methods, Version
  //
  static HTTP_METHODS_ENUM
  Convert_String_Method_To_Enum_HTTP_METHODS(const std::string &method);

  static HTTP_VERSION
  Convert_String_Version_To_Enum_HTTP_VERSION(const std::string &version);

  // HEADERS
  //

  static HTTP_REQUEST_HEADERS_FIELD_ENUM
  Convert_String_Header_Field_To_Enum_HTTP_Headers(
      const std::string &header_field);

  static std::string Convert_Enum_HTTP_Request_Headers_To_String(
      HTTP_REQUEST_HEADERS_FIELD_ENUM http_request_header_enum);
};

} // namespace jojojoster::http
