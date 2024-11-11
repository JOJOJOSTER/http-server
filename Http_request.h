#ifndef HTTP_REQUEST
#define HTTP_REQUEST

#include "Http_Enums.h"
#include "Http_Header_Field.h"
#include <map>
#include <string>
#include <vector>

/*
 *  HTTP Request}
 * --------------------------------
 * |   Method   Target   VERSION  |
 * --------------------------------
 * |  Headers                     |
 * |                              |
 * |                              |
 * --------------------------------
 * |  Body                        |
 * |                              |
 * |                              |
 * --------------------------------
 *
 */

namespace jojojoster::http {

class HTTP_Request {

  // Construcors and struct/class
public:
  class HTTP_Header_field;

  // -----------------CONSTRUCTORS HTTP_Request---------------------

  HTTP_Request(
      HTTP_METHODS_ENUM, const std::string &target, HTTP_VERSION version,
      const std::map<HTTP_REQUEST_HEADERS_FIELD_ENUM, HTTP_Header_Field> &,
      const std::string &body);

  // Copy construcor = default
  HTTP_Request(const HTTP_Request &other) = default;
  //
  // Operator =
  HTTP_Request &operator=(const HTTP_Request &other) = default;

  // ---------------END  CONSTRUCTORS HTTP_Request-----------------

  // -------------------------------
  // Class Methods
  // -------------------------------
public:
  // -------------
  // Request Line
  // -------------

  HTTP_METHODS_ENUM GetMethod() const;

  const std::string &GetTarget() const;

  HTTP_VERSION GetVersion() const;

  // --------
  // Headers
  // --------

  // If HTTP request doesn't have
  // header of this header_field_type
  // we return empty std::string
  //
  // Finding in m_headers a http_headers_field_type and return value
  const std::string &
  GetHeaderValue(HTTP_REQUEST_HEADERS_FIELD_ENUM http_header_field_type);

  // -----
  // Body
  // -----

  const std::string &GetBody() const;

  // ------------------------------
  // VARIABLES
  // ------------------------------
private:
  // -------------
  // Request Line
  // -------------

  // Like Get, Post
  HTTP_METHODS_ENUM m_http_method;
  // Like * , /api/app
  std::string m_target;
  // Like HTTP/1.1
  HTTP_VERSION m_version;

  // --------
  // Headers
  // --------

  // Like Server: Apache
  // TO-DO Maybe change on std::vector
  std::map<HTTP_REQUEST_HEADERS_FIELD_ENUM, HTTP_Header_Field> m_headers;
  // std::vector<HTTP_Header_field> m_headers;

  // -----
  // Body
  // -----

  std::string m_body;
};

class HTTP_Response {};

} // namespace jojojoster::http

#endif // !HTTP_REQUEST
