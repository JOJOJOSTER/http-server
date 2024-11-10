#ifndef HTTP_HEADRER_FIELD
#define HTTP_HEADRER_FIELD

#include "Http_Enums.h"
#include <string>

namespace jojojoster::http {

// ------------CLASS HTTP_Header_field------------------------

class HTTP_Header_field {
public:
  HTTP_Header_field(HTTP_HEADERS_FIELD_ENUM header,
                    const std::string &header_name);

  //
  // Get Set m_header_field_type;
  //
  HTTP_HEADERS_FIELD_ENUM GetHeaderFieldEnum() const;

  HTTP_HEADERS_FIELD_ENUM
  SetHeaderFieldEnum(HTTP_HEADERS_FIELD_ENUM header_field_type);

  //
  // Get Set m_header_field_name;
  //
  std::string GetHeaderValue() const;

  std::string SetHeaderValue(const std::string &header_field_name);

  // --------------
  // STATIC FUNC
  // --------------
public:
  static std::string Convert_Enum_Headers_Field_Type_To_String(
      HTTP_HEADERS_FIELD_ENUM http_headers_field_type);

private:
  HTTP_HEADERS_FIELD_ENUM m_header_field_type;
  std::string m_header_field_name;
};

// --------end CLASS HTTP_Header_field -----------------------

} // namespace jojojoster::http

#endif // !HTTP_HEADRER_FIELD
