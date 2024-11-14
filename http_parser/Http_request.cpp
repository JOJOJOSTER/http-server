#include "Http_request.h"
#include "Http_Enums.h"
#include <iostream>

namespace jojojoster::http {

HTTP_Request::HTTP_Request(
    HTTP_METHODS_ENUM http_method, const std::string &target,
    HTTP_VERSION version,
    const std::map<HTTP_REQUEST_HEADERS_FIELD_ENUM, std::string> &headers,
    const std::string &body)
    : m_http_method(http_method), m_target(target), m_version(version),
      m_headers(headers), m_body(body)

{}

HTTP_Request::HTTP_Request() {}

//
// HTTP_METHODS
//

HTTP_METHODS_ENUM HTTP_Request::GetMethod() const { return m_http_method; }

void HTTP_Request::SetMethod(HTTP_METHODS_ENUM http_method) {
  m_http_method = http_method;
}

//
// TARGET
//

const std::string &HTTP_Request::GetTarget() const { return m_target; }

void HTTP_Request::SetTarget(const std::string &target) { m_target = target; }

//
// VERSION
//

HTTP_VERSION HTTP_Request::GetVersion() const { return m_version; }

void HTTP_Request::SetVersion(HTTP_VERSION http_version) {
  m_version = http_version;
}

//
// HEADERS
//

// I changed return type (reference -> just type).
// TO-DO Correct it.
const std::string HTTP_Request::GetHeaderValue(
    HTTP_REQUEST_HEADERS_FIELD_ENUM http_header_field_type) {

  auto it = m_headers.find(http_header_field_type);
  if (it == m_headers.end()) {

    return "";
  }

  return it->second;

  // TO-DO relieze this function
  //
}

void HTTP_Request::SetHeaderValue(
    HTTP_REQUEST_HEADERS_FIELD_ENUM http_request_enum,
    const std::string &header_value) {

  auto it = m_headers.find(http_request_enum);
  if (it != m_headers.end()) {
    m_headers[http_request_enum] = header_value;
    return;
  }

  m_headers.emplace(std::pair<HTTP_REQUEST_HEADERS_FIELD_ENUM, std::string>(
      http_request_enum, header_value));

  // TO-DO relieze this function
  //
}

//
// BODY
//

const std::string &HTTP_Request::GetBody() const { return m_body; }

void HTTP_Request::SetBody(const std::string &body) { m_body = body; }

} // namespace jojojoster::http
