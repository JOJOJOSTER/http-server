#ifndef HTTP_REQUEST_PARSE
#define HTTP_REQUEST_PARSE

#include "Http_Enums.h"
#include "Http_request.h"
#include <string>

namespace jojojoster::http {

class HTTP_Request_Parser_And_Converter {
public:
  //    //Request Line\\
  //
  // 1. Parse Method and convert to enum;
  //  1.1. Convert_String_Method_To_Enum()
  // 2. Parse Targer  (to std::string)
  // 3. Parse Version (to std::string)
  //
  // 4. If parse \n, parse Headers
  //
  //    //Headers\\
  // 1. Parse headers fields
  //  1.1. Convert_String_Header_Field_To_Enum_HTTP_Headers()
  //  1.2. Put Enums and String to HTTP_Request::HTTP_Header_field
  //
  //  . If parse \n\n of \r\n, parse Body
  //
  //    //Body\\
  // 1. Parse Body(to std::string)
  //
  //
  static HTTP_Request Parse_String_And_Convert_To_HTTP_Request(
      const std::string &http_request_string);
};

} // namespace jojojoster::http

#endif // !HTTP_REQUEST_PARSE
