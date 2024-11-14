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

  HTTP_Request();

  HTTP_Request(
      HTTP_METHODS_ENUM http_method, const std::string &target,
      HTTP_VERSION version,
      const std::map<HTTP_REQUEST_HEADERS_FIELD_ENUM, std::string> &headers,
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

  // Method

  HTTP_METHODS_ENUM GetMethod() const;

  void SetMethod(HTTP_METHODS_ENUM http_method);

  // Target

  const std::string &GetTarget() const;

  void SetTarget(const std::string &target);

  // Version

  HTTP_VERSION GetVersion() const;

  void SetVersion(HTTP_VERSION http_version);

  // --------
  // Headers
  // --------

  // If HTTP request doesn't have
  // header of this header_field_type
  // we return empty std::string
  //
  // Finding in m_headers a http_headers_field_type and return value
  // --------------------------------------------------------------
  // // I changed return type (reference -> just type).
  // TO-DO Correct it.
  const std::string
  GetHeaderValue(HTTP_REQUEST_HEADERS_FIELD_ENUM http_header_field_type);

  void SetHeaderValue(HTTP_REQUEST_HEADERS_FIELD_ENUM http_request_enum,
                      const std::string &header_value);

  // const HTTP_Header_Field<HTTP_REQUEST_HEADERS_FIELD_ENUM> GetHeader() const;

  // -----
  // Body
  // -----

  const std::string &GetBody() const;

  void SetBody(const std::string &body);

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
  std::map<HTTP_REQUEST_HEADERS_FIELD_ENUM, std::string> m_headers;
  // std::vector<HTTP_Header_field> m_headers;

  // -----
  // Body
  // -----

  std::string m_body;
};

} // namespace jojojoster::http

#endif // !HTTP_REQUEST
