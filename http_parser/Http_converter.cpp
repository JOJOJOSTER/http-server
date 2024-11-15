#include "Http_converter.h"
#include "Http_Enums.h"
#include <iostream>

namespace jojojoster::http {

HTTP_METHODS_ENUM
Converter::Convert_String_Method_To_Enum_HTTP_METHODS(
    const std::string &method) {

  std::string method_lower_char = ConvertStringToLowerCase(method);

  if (method_lower_char == "get") {
    return HTTP_METHODS_ENUM::GET;
  } else if (method_lower_char == "post") {
    return HTTP_METHODS_ENUM::POST;
  } else if (method_lower_char == "put") {
    return HTTP_METHODS_ENUM::PUT;
  } else if (method_lower_char == "delete") {
    return HTTP_METHODS_ENUM::DELETE;
  } else if (method_lower_char == "patch") {
    return HTTP_METHODS_ENUM::PATCH;
  } else if (method_lower_char == "head") {
    return HTTP_METHODS_ENUM::HEAD;
  } else if (method_lower_char == "options") {
    return HTTP_METHODS_ENUM::OPTIONS;
  } else if (method_lower_char == "trace") {
    return HTTP_METHODS_ENUM::TRACE;
  } else if (method_lower_char == "connect") {
    return HTTP_METHODS_ENUM::CONNECT;
  }

  std::cerr << "Error Convert string to HTTP_METHODS_ENUM" << std::endl;
  return HTTP_METHODS_ENUM::GET;
}

HTTP_VERSION
Converter::Convert_String_Version_To_Enum_HTTP_VERSION(
    const std::string &version) {

  std::string version_lower_letter_case = ConvertStringToLowerCase(version);

  /*
  std::cerr << "Version lower case: " << version_lower_letter_case << std::endl;
  std::cerr << "String size: \t" << version_lower_letter_case.size()
            << std::endl;
  */

  if (version_lower_letter_case == "http/0.9")
    return HTTP_VERSION::HTTP_0_9;
  else if (version_lower_letter_case == "http/1.0")
    return HTTP_VERSION::HTTP_1;
  else if (version_lower_letter_case == "http/1.1")
    return HTTP_VERSION::HTTP_1_1;
  else if (version_lower_letter_case == "http/2")
    return HTTP_VERSION::HTTP_2;
  else if (version_lower_letter_case == "http/3")
    return HTTP_VERSION::HTTP_3;

  // std::cerr << "string to version enum : ERROR" << std::endl;

  // Here maybe bug
  return HTTP_VERSION::HTTP_1_1;
}

HTTP_REQUEST_HEADERS_FIELD_ENUM
Converter::Convert_String_Header_Field_To_Enum_HTTP_Headers(
    const std::string &header_field) {

  std::string header_field_lower_cases = ConvertStringToLowerCase(header_field);

  // std::cerr << header_field_lower_cases << std::endl;

  if (header_field_lower_cases == "a-im")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::A_IM;
  else if (header_field_lower_cases == "accept")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Accept;
  else if (header_field_lower_cases == "accept-charset")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Accept_Charset;
  else if (header_field_lower_cases == "accept-datetime")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Accept_Datetime;
  else if (header_field_lower_cases == "accept-encoding")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Accept_Encoding;
  else if (header_field_lower_cases == "accept-language")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Accept_Language;
  else if (header_field_lower_cases == "accept-control-request-method")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Access_Control_Request_Method;

  else if (header_field_lower_cases == "access-control-request-headers")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Access_Control_Request_Headers;
  else if (header_field_lower_cases == "authorization")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Authorization;
  else if (header_field_lower_cases == "cache-control")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Cache_Control;
  else if (header_field_lower_cases == "connection")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Connection;
  else if (header_field_lower_cases == "content-encoding")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Content_Encoding;
  else if (header_field_lower_cases == "content-length")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Content_Length;
  else if (header_field_lower_cases == "content-md5")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Content_MD5;
  else if (header_field_lower_cases == "content-type")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Content_Type;
  else if (header_field_lower_cases == "cookie")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Cookie;
  else if (header_field_lower_cases == "date")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Date;
  else if (header_field_lower_cases == "expect")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Expect;
  else if (header_field_lower_cases == "forwarded")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Forwarded;
  else if (header_field_lower_cases == "from")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::From;
  else if (header_field_lower_cases == "host")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Host;
  else if (header_field_lower_cases == "http2-settings")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::HTTP2_Settings;
  else if (header_field_lower_cases == "if-match")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::If_Match;
  else if (header_field_lower_cases == "if-modified-since")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::If_Modified_Since;
  else if (header_field_lower_cases == "if-none-match")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::If_None_Match;
  else if (header_field_lower_cases == "if-range")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::If_Range;
  else if (header_field_lower_cases == "if-unmodified-since")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::If_Unmodified_Since;
  else if (header_field_lower_cases == "max-forwards")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Max_Forwards;
  else if (header_field_lower_cases == "origin")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Origin;
  else if (header_field_lower_cases == "pragma")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Pragma;
  else if (header_field_lower_cases == "prefer")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Prefer;
  else if (header_field_lower_cases == "proxy-authorization")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Proxy_Authorization;
  else if (header_field_lower_cases == "range")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Range;
  else if (header_field_lower_cases == "referer")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Referer;
  else if (header_field_lower_cases == "te")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::TE;
  else if (header_field_lower_cases == "trailer")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Trailer;
  else if (header_field_lower_cases == "transfer-encoding")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Transfer_Encoding;
  else if (header_field_lower_cases == "user-agent")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::User_Agent;
  else if (header_field_lower_cases == "upgrade")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Upgrade;
  else if (header_field_lower_cases == "via")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Via;
  else if (header_field_lower_cases == "warning")
    return HTTP_REQUEST_HEADERS_FIELD_ENUM::Warning;

  std::cerr << "Error Convert String to Header Enum" << std::endl;
  return HTTP_REQUEST_HEADERS_FIELD_ENUM::Host;
}

std::string Converter::Convert_Enum_HTTP_Request_Headers_To_String(
    HTTP_REQUEST_HEADERS_FIELD_ENUM http_request_header_enum) {

  if (http_request_header_enum == HTTP_REQUEST_HEADERS_FIELD_ENUM::A_IM)
    return "A-IM";
  else if (http_request_header_enum == HTTP_REQUEST_HEADERS_FIELD_ENUM::Accept)
    return "Accept";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::Accept_Charset)
    return "Accept-Charset";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::Accept_Datetime)
    return "Accept-Datetime";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::Accept_Encoding)
    return "Accept-Encoding";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::Accept_Language)
    return "Accept-Language";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::Access_Control_Request_Method)
    return "Access-Control-Request-Method";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::Access_Control_Request_Headers)
    return "Access-Control-Request-Headers";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::Authorization)
    return "Authorization";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::Cache_Control)
    return "Cache-Control";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::Connection)
    return "Connection";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::Content_Encoding)
    return "Content-Encoding";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::Content_Length)
    return "Content-Length";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::Content_MD5)
    return "Content-MD5";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::Content_Type)
    return "Content-Type";
  else if (http_request_header_enum == HTTP_REQUEST_HEADERS_FIELD_ENUM::Cookie)
    return "Cookie";
  else if (http_request_header_enum == HTTP_REQUEST_HEADERS_FIELD_ENUM::Date)
    return "Date";
  else if (http_request_header_enum == HTTP_REQUEST_HEADERS_FIELD_ENUM::Expect)
    return "Expect";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::Forwarded)
    return "Forwarded";
  else if (http_request_header_enum == HTTP_REQUEST_HEADERS_FIELD_ENUM::From)
    return "From";
  else if (http_request_header_enum == HTTP_REQUEST_HEADERS_FIELD_ENUM::Host)
    return "Host";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::HTTP2_Settings)
    return "HTTP2-Settings";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::If_Match)
    return "If-Match";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::If_Modified_Since)
    return "If-Modified-Since";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::If_None_Match)
    return "If-None-Match";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::If_Range)
    return "If-Range";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::If_Unmodified_Since)
    return "If-Unmodified-Since";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::Max_Forwards)
    return "Max-Forwards";
  else if (http_request_header_enum == HTTP_REQUEST_HEADERS_FIELD_ENUM::Origin)
    return "Origin";
  else if (http_request_header_enum == HTTP_REQUEST_HEADERS_FIELD_ENUM::Pragma)
    return "Pragma";
  else if (http_request_header_enum == HTTP_REQUEST_HEADERS_FIELD_ENUM::Prefer)
    return "Prefer";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::Proxy_Authorization)
    return "Proxy-Authorization";
  else if (http_request_header_enum == HTTP_REQUEST_HEADERS_FIELD_ENUM::Range)
    return "Range";
  else if (http_request_header_enum == HTTP_REQUEST_HEADERS_FIELD_ENUM::Referer)
    return "Referer";
  else if (http_request_header_enum == HTTP_REQUEST_HEADERS_FIELD_ENUM::TE)
    return "TE";
  else if (http_request_header_enum == HTTP_REQUEST_HEADERS_FIELD_ENUM::Trailer)
    return "Trailer";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::Transfer_Encoding)
    return "Transfer-Encoding";
  else if (http_request_header_enum ==
           HTTP_REQUEST_HEADERS_FIELD_ENUM::User_Agent)
    return "User-Agent";
  else if (http_request_header_enum == HTTP_REQUEST_HEADERS_FIELD_ENUM::Upgrade)
    return "Upgrade";
  else if (http_request_header_enum == HTTP_REQUEST_HEADERS_FIELD_ENUM::Via)
    return "Via";
  else if (http_request_header_enum == HTTP_REQUEST_HEADERS_FIELD_ENUM::Warning)
    return "Warning";
  else
    return "Unknown-Header";
}

std::string Converter::ConvertStringToLowerCase(const std::string &str) {

  std::string temp = str;

  for (char &c : temp) {
    // here was bug
    // when c equal A,
    // C don't Convert
    // to lower case
    // When('A' < c)
    // c < 'Z' =>  c <= 'Z'
    if ('A' <= c && c <= 'Z') {
      c += 32;
    }
  }

  return temp;
}

} // namespace jojojoster::http
