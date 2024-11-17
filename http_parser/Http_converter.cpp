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

std::string
Converter::Convert_Enum_HTTP_Version_To_String(HTTP_VERSION http_version_enum) {
  if (http_version_enum == HTTP_VERSION::HTTP_0_9)
    return "HTTP/0.9";
  else if (http_version_enum == HTTP_VERSION::HTTP_1)
    return "HTTP/1.0";
  else if (http_version_enum == HTTP_VERSION::HTTP_1_1)
    return "HTTP/1.1";
  else if (http_version_enum == HTTP_VERSION::HTTP_2)
    return "HTTP/2";
  else if (http_version_enum == HTTP_VERSION::HTTP_3)
    return "HTTP/3";
  else
    return "Unknown-Version";
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

std::string Converter::Convert_Enum_HTTP_Response_Headers_To_String(
    HTTP_RESPONSE_HEADERS_FIELD_ENUM http_response_header_enum) {
  if (http_response_header_enum == HTTP_RESPONSE_HEADERS_FIELD_ENUM::Accept_CH)
    return "Accept-CH";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Access_Control_Allow_Origin)
    return "Access-Control-Allow-Origin";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Access_Control_Allow_Credentials)
    return "Access-Control-Allow-Credentials";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Access_Control_Expose_Headers)
    return "Access-Control-Expose-Headers";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Access_Control_Max_Age)
    return "Access-Control-Max-Age";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Access_Control_Allow_Methods)
    return "Access-Control-Allow-Methods";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Access_Control_Allow_Headers)
    return "Access-Control-Allow-Headers";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Accept_Patch)
    return "Accept-Patch";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Accept_Ranges)
    return "Accept-Ranges";
  else if (http_response_header_enum == HTTP_RESPONSE_HEADERS_FIELD_ENUM::Age)
    return "Age";
  else if (http_response_header_enum == HTTP_RESPONSE_HEADERS_FIELD_ENUM::Allow)
    return "Allow";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Alt_Svc)
    return "Alt-Svc";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Cache_Control)
    return "Cache-Control";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Connection)
    return "Connection";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Content_Disposition)
    return "Content-Disposition";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Content_Encoding)
    return "Content-Encoding";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Content_Language)
    return "Content-Language";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Content_Length)
    return "Content-Length";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Content_Location)
    return "Content-Location";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Content_MD5)
    return "Content-MD5";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Content_Range)
    return "Content-Range";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Content_Type)
    return "Content-Type";
  else if (http_response_header_enum == HTTP_RESPONSE_HEADERS_FIELD_ENUM::Date)
    return "Date";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Delta_Base)
    return "Delta-Base";
  else if (http_response_header_enum == HTTP_RESPONSE_HEADERS_FIELD_ENUM::ETag)
    return "ETag";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Expires)
    return "Expires";
  else if (http_response_header_enum == HTTP_RESPONSE_HEADERS_FIELD_ENUM::IM)
    return "IM";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Last_Modified)
    return "Last-Modified";
  else if (http_response_header_enum == HTTP_RESPONSE_HEADERS_FIELD_ENUM::Link)
    return "Link";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Location)
    return "Location";
  else if (http_response_header_enum == HTTP_RESPONSE_HEADERS_FIELD_ENUM::P3P)
    return "P3P";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Pragma)
    return "Pragma";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Preference_Applied)
    return "Preference-Applied";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Proxy_Authenticate)
    return "Proxy-Authenticate";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Public_Key_Pins)
    return "Public-Key-Pins";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Retry_After)
    return "Retry-After";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Server)
    return "Server";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Set_Cookie)
    return "Set-Cookie";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Strict_Transport_Security)
    return "Strict-Transport-Security";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Trailer)
    return "Trailer";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Transfer_Encoding)
    return "Transfer-Encoding";
  else if (http_response_header_enum == HTTP_RESPONSE_HEADERS_FIELD_ENUM::Tk)
    return "Tk";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Upgrade)
    return "Upgrade";
  else if (http_response_header_enum == HTTP_RESPONSE_HEADERS_FIELD_ENUM::Vary)
    return "Vary";
  else if (http_response_header_enum == HTTP_RESPONSE_HEADERS_FIELD_ENUM::Via)
    return "Via";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::Warning)
    return "Warning";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::WWW_Authenticate)
    return "WWW-Authenticate";
  else if (http_response_header_enum ==
           HTTP_RESPONSE_HEADERS_FIELD_ENUM::X_Frame_Options)
    return "X-Frame-Options";
  else
    return "Unknown-Header";
}

std::string Converter::Convert_Enum_HTTP_Status_Code_To_String_With_Number(
    HTTP_STATUS_CODE http_status_code_enum) {

  if (http_status_code_enum == HTTP_STATUS_CODE::Continue)
    return "100 Continue";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Switching_Protocols)
    return "101 Switching Protocols";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Processing)
    return "102 Processing";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Early_Hints)
    return "103 Early Hints";

  // 2xx success
  else if (http_status_code_enum == HTTP_STATUS_CODE::OK)
    return "200 OK";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Created)
    return "201 Created";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Accepted)
    return "202 Accepted";
  else if (http_status_code_enum ==
           HTTP_STATUS_CODE::Non_Authoritative_Information)
    return "203 Non-Authoritative Information";
  else if (http_status_code_enum == HTTP_STATUS_CODE::No_Content)
    return "204 No Content";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Reset_Content)
    return "205 Reset Content";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Partial_Content)
    return "206 Partial Content";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Multi_Status)
    return "207 Multi-Status";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Already_Reported)
    return "208 Already Reported";
  else if (http_status_code_enum == HTTP_STATUS_CODE::IM_Used)
    return "209 IM Used";

  // 3xx redirection
  else if (http_status_code_enum == HTTP_STATUS_CODE::Multiple_Choices)
    return "300 Multiple Choices";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Moved_Permanently)
    return "301 Moved Permanently";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Found)
    return "302 Found";
  else if (http_status_code_enum == HTTP_STATUS_CODE::See_Other)
    return "303 See Other";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Not_Modified)
    return "304 Not Modified";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Use_Proxy)
    return "305 Use Proxy";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Switch_Proxy)
    return "306 Switch Proxy";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Temporary_Redirect)
    return "307 Temporary Redirect";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Permanent_Redirect)
    return "308 Permanent Redirect";

  // 4xx client errors
  else if (http_status_code_enum == HTTP_STATUS_CODE::Bad_Request)
    return "400 Bad Request";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Unauthorized)
    return "401 Unauthorized";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Payment_Required)
    return "402 Payment Required";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Forbidden)
    return "403 Forbidden";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Not_Found)
    return "404 Not Found";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Method_Not_Allowed)
    return "405 Method Not Allowed";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Not_Acceptable)
    return "406 Not Acceptable";
  else if (http_status_code_enum ==
           HTTP_STATUS_CODE::Proxy_Authentication_Required)
    return "407 Proxy Authentication Required";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Request_Timeout)
    return "408 Request Timeout";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Conflict)
    return "409 Conflict";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Gone)
    return "410 Gone";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Length_Required)
    return "411 Length Required";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Precondition_Failed)
    return "412 Precondition Failed";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Payload_Too_Large)
    return "413 Payload Too Large";
  else if (http_status_code_enum == HTTP_STATUS_CODE::URI_Too_Long)
    return "414 URI Too Long";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Unsupported_Media_Type)
    return "415 Unsupported Media Type";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Range_Not_Satisfiable)
    return "416 Range Not Satisfiable";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Expectation_Failed)
    return "417 Expectation Failed";
  else if (http_status_code_enum == HTTP_STATUS_CODE::I_m_A_Teapot)
    return "418 I'm A Teapot"; // RFC 2324
  else if (http_status_code_enum == HTTP_STATUS_CODE::Misdirected_Request)
    return "421 Misdirected Request";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Unprocessable_Entity)
    return "422 Unprocessable Entity";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Locked)
    return "423 Locked";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Failed_Dependency)
    return "424 Failed Dependency";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Too_Early)
    return "425 Too Early";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Upgrade_Required)
    return "426 Upgrade Required";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Precondition_Required)
    return "428 Precondition Required";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Too_Many_Requests)
    return "429 Too Many Requests";
  else if (http_status_code_enum ==
           HTTP_STATUS_CODE::Request_Header_Fields_Too_Large)
    return "431 Request Header Fields Too Large";
  else if (http_status_code_enum ==
           HTTP_STATUS_CODE::Unavailable_For_Legal_Reasons)
    return "451 Unavailable For Legal Reasons";

  // 5xx server errors
  else if (http_status_code_enum == HTTP_STATUS_CODE::Internal_Server_Error)
    return "500 Internal Server Error";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Not_Implemented)
    return "501 Not Implemented";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Bad_Gateway)
    return "502 Bad Gateway";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Service_Unavailable)
    return "503 Service Unavailable";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Gateway_Timeout)
    return "504 Gateway Timeout";
  else if (http_status_code_enum ==
           HTTP_STATUS_CODE::HTTP_Version_Not_Supported)
    return "505 HTTP Version Not Supported";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Variant_Also_Negotiates)
    return "506 Variant Also Negotiates";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Insufficient_Storage)
    return "507 Insufficient Storage";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Loop_Detected)
    return "508 Loop Detected";
  else if (http_status_code_enum == HTTP_STATUS_CODE::Not_Extended)
    return "510 Not Extended";
  else if (http_status_code_enum ==
           HTTP_STATUS_CODE::Network_Authentication_Required)
    return "511 Network Authentication Required";
  else
    return "588 Unknow status code";
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
