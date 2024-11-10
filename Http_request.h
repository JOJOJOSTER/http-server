#ifndef HTTP_REQUEST
#define HTTP_REQUEST

#include "Http_Enums.h"
#include <string>
#include <vector>

namespace jojojoster::http {

class HTTP_Request {

  // Construcors and struct/class
public:
  class HTTP_Header_field;

  HTTP_Request(HTTP_METHODS_ENUM, const std::string &target,
               const std::string &version,
               const std::vector<HTTP_Header_field> &, const std::string &body);

  // Copy construcor = default
  HTTP_Request(const HTTP_Request &other) = default;
  //
  // Operator =
  HTTP_Request &operator=(const HTTP_Request &other) = default;

  class HTTP_Header_field {
  public:
    HTTP_Header_field(HTTP_HEADERS_FIELD_ENUM header,
                      const std::string &header_name);

    // Get Set m_header_field_type;
    HTTP_HEADERS_FIELD_ENUM GetHeaderField() const;

    HTTP_HEADERS_FIELD_ENUM
    SetHeaderField(HTTP_HEADERS_FIELD_ENUM header_field_type);
    //
    // Get Set m_header_field_name;
    std::string GetHeaderName() const;

    std::string SetHeaderName(const std::string &header_field_name);

  private:
    HTTP_HEADERS_FIELD_ENUM m_header_field_type;
    std::string m_header_field_name;
  };

  //
  // Class Methods
  //
public:
  // -------------
  // Request Line
  // -------------

  std::string GetTarget() const;

  std::string GetVersion() const;

  // --------
  // Headers
  // --------

  HTTP_Header_field GetHeaderField(const std::string &header_field_name);

  // -----
  // Body
  // -----

  const std::string &GetBody() const;

  //
  // VARIABLES
  //
private:
  // -------------
  // Request Line
  // -------------

  // Like Get, Post
  HTTP_METHODS_ENUM m_http_method;
  // Like * , /api/app
  std::string m_target;
  // Like HTTP/1.1
  std::string m_version;

  // --------
  // Headers
  // --------

  // Convert HTTP_Headers to std::string
  //

  // Like Server: Apache
  // std::map<std::string, std::string> m_headers;
  std::vector<HTTP_Header_field> m_headers;

  // -----
  // Body
  // -----

  std::string m_body;
};

class HTTP_Response {};

} // namespace jojojoster::http

#endif // !HTTP_REQUEST
