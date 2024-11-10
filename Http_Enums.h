#ifndef HTTP_ENUMS
#define HTTP_ENUMS

#include <system_error>
namespace jojojoster::http {

// enum HTTP_METHODS
enum HTTP_METHODS_ENUM {
  GET,
  POST,
  PUT,
  DELETE,
  PATCH,
  HEAD,
  OPTIONAS,
  TRACE,
  CONNECT
};

// https://en.wikipedia.org/wiki/List_of_HTTP_header_fields
enum HTTP_HEADERS_FIELD_ENUM {
  A_IM,
  Accept,
  Accept_Charset,
  Accept_Datetime,
  Accept_Encoding,
  Accept_Language,
  Access_Control_Request_Method,
  Access_Control_Request_Headers,
  Authorization,
  Cache_Control,
  Connection,
  Content_Encoding,
  Content_Length,
  Content_MD5,
  Content_Type,
  Cookie,
  Date,
  Expect,
  Forwarded,
  From,
  Host,
  HTTP2_Settings,
  If_Match,
  If_Modified_Since,
  If_None_Match,
  If_Range,
  If_Unmodified_Since,
  Max_Forwards,
  Origin,
  Pragma,
  Prefer,
  Proxy_Authorization,
  Range,
  Referer,
  TE,
  Trailer,
  Transfer_Encoding,
  User_Agent,
  Upgrade,
  Via,
  Warning
};

} // namespace jojojoster::http

#endif // !HTTP_ENUMS
