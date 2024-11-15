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
  OPTIONS,
  TRACE,
  CONNECT
};

// https://en.wikipedia.org/wiki/List_of_HTTP_header_fields
enum class HTTP_REQUEST_HEADERS_FIELD_ENUM {
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

// https://en.wikipedia.org/wiki/HTTP
enum HTTP_VERSION { HTTP_0_9, HTTP_1, HTTP_1_1, HTTP_2, HTTP_3 };

enum HTTP_STATUS_CODE {

  // 1xx informational response
  Continue = 100,
  Switching_Protocols = 101,
  Processing = 102,
  Early_Hints = 103,
  // 2xx success
  OK = 200,
  Created = 201,
  Accepted = 202,
  Non_Authoritative_Information = 203,
  No_Content = 204,
  Reset_Content = 205,
  Partial_Content = 206,
  Multi_Status = 207,
  Already_Reported = 208,
  IM_Used = 209,
  // 3xx redirection
  Multiple_Choices = 300,
  Moved_Permanently = 301,
  Found = 302,
  See_Other = 303,
  Not_Modified = 304,
  Use_Proxy = 305,
  Switch_Proxy = 306,
  Temporary_Redirect = 307,
  Permanent_Redirect = 308,
  // 4xx client errors
  Bad_Request = 400,
  Unauthorized = 401,
  Payment_Required = 402,
  Forbidden = 403,
  Not_Found = 404,
  Method_Not_Allowed = 405,
  Not_Acceptable = 406,
  Proxy_Authentication_Required = 407,
  // TO_DO Add 4xx status code

  // 5xx server errors

};

// TO_DO:
// change this enum class to enum
// and put it to namespace
enum class HTTP_RESPONSE_HEADERS_FIELD_ENUM {

  Accept_CH,
  Access_Control_Allow_Methods,
  Access_Control_Allow_Headers,
  Age,
  Allow,
  Alt_Svc,
  Cache_Control,
  Connection,
  Content_Disposition,
  Content_Encoding,
  Content_Language,
  Content_Length,
  Content_Location,
  Content_MD5,
  Content_Range,
  Content_Type,
  Date,
  Delta_Base,
  ETag,
  Expires,
  IM,
  Last_Modified,
  Link,
  Location,
  P3P,
  Pragma,
  Preference_Applied,
  Proxy_Authenticate,
  Public_Key_Pins,
  Retry_After,
  Server,
  Set_Cookie,
  Strict_Transport_Security,
  Trailer,
  Transfer_Encoding,
  Tk,
  Upgrade,
  Vary,
  Via,
  Warning,
  WWW_Authenticate,
  X_Frame_Options,
  Accept_Patch,
  Accept_Ranges,
  Access_Control_Allow_Origin,
  Access_Control_Allow_Credentials,
  Access_Control_Expose_Headers,
  Access_Control_Max_Age,
  /*
  Access_Control_Allow_Methods,
  Access_Control_Allow_Headers,
  Age,
  Allow,
  Alt_Svc,
  Cache_Control,
  Connection,
  Content_Disposition,
  Content_Encoding,
  Content_Language,
  Content_Length,
  Content_Location,
  Content_MD5,
  Content_Range,
  Content_Type,
  Date,
  Delta_Base,
  ETag,
  Expires,
  IM,
  Last_Modified,
  Link,
  Location,
  P3P,
  Pragma,
  Preference_Applied,
  Proxy_Authenticate,
  Public_Key_Pins,
  Retry_After,
  Server,
  Set_Cookie,
  Strict_Transport_Security,
  Trailer,
  Transfer_Encoding,
  Tk,
  Upgrade,
  Vary,
  Via,
  Warning,
  WWW_Authenticate,
  X_Frame_Options
  */

};

} // namespace jojojoster::http

#endif // !HTTP_ENUMS
