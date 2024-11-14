#ifndef HTTP_RESPONDE
#define HTTP_RESPONDE

#include "Http_Enums.h"
#include "Http_Header_Field.h"
#include <map>
#include <string>

/*
 *  HTTP Response
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
  HTTP_Response(
      HTTP_VERSION version, HTTP_STATUS_CODE status_code,
      const std::map<HTTP_RESPONSE_HEADERS_FIELD_ENUM,
                     HTTP_Header_Field<HTTP_RESPONSE_HEADERS_FIELD_ENUM>>
          &m_headers,
      const std::string &body);

  HTTP_Response(const HTTP_Response &other) = default;

  HTTP_Response &operator=(const HTTP_Response &other) = default;

  // ---------------END  CONSTRUCTORS HTTP_Request-----------------

  // -------------------------------
  // Class Methods
  // -------------------------------
public:
  // -------------
  // Responde Line
  // -------------

  HTTP_VERSION GetVersion() const;

  void SetVersion(const std::string &version);

  HTTP_STATUS_CODE GetStatusCode() const;

  void SetStatusCode(HTTP_STATUS_CODE status_code);

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
    GetHeaderValue(HTTP_RESPONSE_HEADERS_FIELD_ENUM http_header_field_type);
  */

  void
  SetHeader(HTTP_Header_Field<HTTP_RESPONSE_HEADERS_FIELD_ENUM> http_header);

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
  // Response Line
  // -------------

  // Like HTTP/1.1
  HTTP_VERSION m_version;
  HTTP_STATUS_CODE m_status_code;

  // --------
  // Headers
  // --------

  // Like Server: Apache

  // TO-DO maybe change on std::vector
  std::map<HTTP_RESPONSE_HEADERS_FIELD_ENUM,
           HTTP_Header_Field<HTTP_RESPONSE_HEADERS_FIELD_ENUM>>
      m_headers;

  // -----
  // Body
  // -----

  std::string m_body;
};

} // namespace jojojoster::http

#endif // !HTTP_RESPONDE
