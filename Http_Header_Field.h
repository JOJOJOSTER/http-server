#ifndef HTTP_HEADRER_FIELD
#define HTTP_HEADRER_FIELD

#include "Http_Enums.h"
#include <string>
#include <type_traits>

namespace jojojoster::http {

// ------------CLASS HTTP_Header_field------------------------

// TO-DO Make a template (HTTP_REQUEST_HEADERS_FIELD_ENUM and
// HTTP_REQUEST_HEADERS_FIELD_ENUM)
// Learn a SFINAL
class HTTP_Header_Field {

  // https://ru.stackoverflow.com/questions/494672/Шаблоны-в-c-Ограничение-типа
  /*
  static const bool is_HTTP_REQUEST_of_HTTP_RESPONSE =
      std::is_same<T, HTTP_REQUEST_HEADERS_FIELD_ENUM>::value ||
      std::is_same<T, HTTP_RESPONSE_HEADERS_FIELD_ENUM>::value;

  static_assert(is_HTTP_REQUEST_of_HTTP_RESPONSE, "" );
*/

public:
  explicit HTTP_Header_Field(HTTP_REQUEST_HEADERS_FIELD_ENUM header,
                             const std::string &header_name);

  explicit HTTP_Header_Field(const HTTP_Header_Field &other) = default;

  HTTP_Header_Field &operator=(const HTTP_Header_Field &other);

public:
  //
  // Get Set m_header_field_type;
  //
  HTTP_REQUEST_HEADERS_FIELD_ENUM GetHeaderFieldEnum() const;

  HTTP_REQUEST_HEADERS_FIELD_ENUM
  SetHeaderFieldEnum(HTTP_REQUEST_HEADERS_FIELD_ENUM header_field_type);

  //
  // Get Set m_header_field_name;
  //
  std::string GetHeaderValue() const;

  std::string SetHeaderValue(const std::string &header_field_name);

  // --------------
  // STATIC FUNC
  // --------------
public:
  static std::string Convert_Enum_Request_Headers_Field_Type_To_String(
      HTTP_REQUEST_HEADERS_FIELD_ENUM http_headers_field_type);

private:
  HTTP_REQUEST_HEADERS_FIELD_ENUM m_header_field_type;
  std::string m_header_field_name;
};

// --------end CLASS HTTP_Header_field -----------------------

} // namespace jojojoster::http

#endif // !HTTP_HEADRER_FIELD
