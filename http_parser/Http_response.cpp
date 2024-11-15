#include "Http_response.h"
#include <string>
namespace jojojoster::http {

HTTP_Response::HTTP_Response(
    HTTP_VERSION version, HTTP_STATUS_CODE status_code,
    const std::map<HTTP_RESPONSE_HEADERS_FIELD_ENUM, std::string> &headers,
    const std::string &body)
    : m_version(version), m_status_code(status_code), m_headers(headers),
      m_body(body) {}

HTTP_VERSION HTTP_Response::GetVersion() const { return m_version; }

void HTTP_Response::SetVersion(HTTP_VERSION http_version_enum) {
  m_version = http_version_enum;
}

HTTP_STATUS_CODE HTTP_Response::GetStatusCode() const { return m_status_code; }

void HTTP_Response::SetStatusCode(HTTP_STATUS_CODE status_code_enum) {
  m_status_code = status_code_enum;
}

std::string HTTP_Response::GetHeaderValue(
    HTTP_RESPONSE_HEADERS_FIELD_ENUM http_response_header_enum) {

  auto it = m_headers.find(http_response_header_enum);

  if (it == m_headers.end()) {

    return "";
  }

  return it->second;
}

void HTTP_Response::SetHeaderValue(
    HTTP_RESPONSE_HEADERS_FIELD_ENUM http_response_header_enum,
    const std::string &http_header_value) {

  m_headers[http_response_header_enum] = http_header_value;
}

void HTTP_Response::ResetHeader(
    HTTP_RESPONSE_HEADERS_FIELD_ENUM http_response_header_enum) {

  m_headers.erase(http_response_header_enum);
}

const std::string &HTTP_Response::GetBody() const { return m_body; }

void HTTP_Response::SetBody(const std::string &body) { m_body = body; }

} // namespace jojojoster::http
