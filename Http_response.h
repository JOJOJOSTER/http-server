#ifndef HTTP_RESPONDE
#define HTTP_RESPONDE

#include "Http_Enums.h"

/*
 *  HTTP Request}
 * --------------------------------
 * |  VERSION   Status Code       |
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

class HTTP_Response {

  // -----------------CONSTRUCTORS HTTP_Request---------------------
  /*
  HTTP_Request(HTTP_METHODS_ENUM, const std::string &target,
               HTTP_VERSION version,
               const std::map<HTTP_HEADERS_FIELD_ENUM, HTTP_Header_Field> &,
               const std::string &body);

  // Copy construcor = default
  HTTP_Request(const HTTP_Request &other) = default;
  //
  // Operator =
  HTTP_Request &operator=(const HTTP_Request &other) = default;
  */

  // ---------------END  CONSTRUCTORS HTTP_Request-----------------

  // -------------------------------
  // Class Methods
  // -------------------------------
public:
  // -------------
  // Responde Line
  // -------------

  /*
  HTTP_METHODS_ENUM GetMethod() const;

  const std::string &GetTarget() const;

  HTTP_VERSION GetVersion() const;
  */

  // --------
  // Headers
  // --------

  // If HTTP request doesn't have
  // header of this header_field_type
  // we return empty std::string
  //
  // Finding in m_headers a http_headers_field_type and return value

  /*
  const std::string &
  GetHeaderValue(HTTP_HEADERS_FIELD_ENUM http_header_field_type);
  */

  // -----
  // Body
  // -----

  /*
  const std::string &GetBody() const;
  */

  // ------------------------------
  // VARIABLES
  // ------------------------------
private:
  // -------------
  // Responde Line
  // -------------

  // Like HTTP/1.1
  HTTP_VERSION m_version;
  HTTP_STATUS_CODE m_status_code;

  // --------
  // Headers
  // --------

  // Like Server: Apache
  /*
  std::map<HTTP_HEADERS_FIELD_ENUM, HTTP_Header_Field> m_headers;
  */
  // std::vector<HTTP_Header_field> m_headers;

  // -----
  // Body
  // -----

  /*
  std::string m_body;
  */
};

} // namespace jojojoster::http

#endif // !HTTP_RESPONDE
