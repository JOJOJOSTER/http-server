#include "Http_request_parse.h"
#include "Http_Enums.h"
#include "Http_converter.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

namespace jojojoster::http {

HTTP_Request
HTTP_Request_Parser_And_Converter::Parse_String_And_Convert_To_HTTP_Request(
    const std::string &http_request_string) {

  //    //Request Line\\
  //
  // 1. Parse Method and convert to enum;
  //  1.1. Convert_String_Method_To_Enum()
  // 2. Parse Targer  (to std::string)
  // 3. Parse Version (to std::string)
  //
  // 4. If parse \n, parse Headers
  //
  //    //Headers\\
  // 1. Parse headers fields
  //  1.1. Convert_String_Header_Field_To_Enum_HTTP_Headers()
  //  1.2. Put Enums and String to HTTP_Request::HTTP_Header_field
  //
  //  . If parse \n\n of \r\n, parse Body
  //
  //    //Body\\
  // 1. Parse Body(to std::string)

  std::string method;

  int char_counter = 0;

  while (char_counter < http_request_string.size()) {
    if (http_request_string[char_counter] == ' ')
      break;

    method += http_request_string[char_counter];

    ++char_counter;
  }

  ++char_counter;

  std::string target;
  // std::cerr << "Here target" << std::endl;

  while (char_counter < http_request_string.size()) {
    if (http_request_string[char_counter] == ' ')
      break;

    target += http_request_string[char_counter];
    ++char_counter;
  }
  // Skip ' ' symbol
  ++char_counter;

  std::string version;

  while (char_counter < http_request_string.size()) {

    if (http_request_string[char_counter] == '\r') {

      // Skip '\r' symbol
      ++char_counter;
      continue;
    }

    if (http_request_string[char_counter] == '\n')
      break;

    version += http_request_string[char_counter];
    // Move to the next character
    ++char_counter;
  }

  ++char_counter;

  std::map<HTTP_REQUEST_HEADERS_FIELD_ENUM, std::string> headers;

  std::string temp_http_header_field = "";
  std::string temp_http_header_value = "";

  bool isHeaderField = true;

  while (char_counter < http_request_string.size()) {
    //
    // MAYBE OVERFLOW
    //
    if (http_request_string[char_counter] == '\n' &&
            http_request_string[char_counter + 1] == '\n' ||
        http_request_string[char_counter] == '\r' &&
            http_request_string[char_counter + 1] == '\n' &&
            http_request_string[char_counter + 2] == '\r' &&
            http_request_string[char_counter + 3] == '\n') {

      //
      // End the headers
      //

      // Convert to enum last header field
      HTTP_REQUEST_HEADERS_FIELD_ENUM temp_http_header_field_enum =
          Converter::Convert_String_Header_Field_To_Enum_HTTP_Headers(
              temp_http_header_field);

      // Add last header value to std::map headers
      headers.emplace(temp_http_header_field_enum, temp_http_header_value);

      /*
      std::cerr << "Header field: " << temp_http_header_field
                << "\nHeader value: " << temp_http_header_value << std::endl;
                */

      // Clear temp variables
      // (not necessary)
      temp_http_header_field = "";
      temp_http_header_value = "";

      // Skip 2 symbol
      ++char_counter;
      ++char_counter;

      // If symbols with '\r'
      // Skip 2 symbols again
      if (http_request_string[char_counter] == '\r' &&
          http_request_string[char_counter + 1] == '\n') {
        ++char_counter;
        ++char_counter;
      }

      // Header value parsed
      // Can parse next header field
      // (not necessary, bacause
      // headers ended)
      isHeaderField = true;

      break;
    }

    //
    // MAYBE OVERFLOW
    //
    else if (http_request_string[char_counter] == '\n' ||
             (http_request_string[char_counter] == '\r' &&
              http_request_string[char_counter + 1] == '\n')) {

      if (http_request_string[char_counter] == '\r' &&
          http_request_string[char_counter + 1] == '\n') {

        // Skip 2 symbols
        // ('\r' and '\n')
        ++char_counter;
        ++char_counter;
      } else {
        // Skip 1 symbol
        // ('\n')
        ++char_counter;
      }

      HTTP_REQUEST_HEADERS_FIELD_ENUM temp_http_header_field_enum =
          Converter::Convert_String_Header_Field_To_Enum_HTTP_Headers(
              temp_http_header_field);

      // Add header value to std::map headers
      headers.emplace(temp_http_header_field_enum, temp_http_header_value);

      /*
      std::cerr << "Header field: " << temp_http_header_field
                << "\nHeader value: " << temp_http_header_value << std::endl;

                */

      // Header value parsed
      // Can parse next header field
      isHeaderField = true;

      // Clear temp variables
      temp_http_header_field = "";
      temp_http_header_value = "";

      continue;
    }

    if (isHeaderField) {
      if (http_request_string[char_counter] == ':' &&
          http_request_string[char_counter + 1] == ' ') {
        // Header field ended
        // when find a characters
        // ':' and ' '
        isHeaderField = false;
        // Skip Symbols ':' and ' '
        ++char_counter;
        ++char_counter;
        continue;
      }
      // Header field
      temp_http_header_field += http_request_string[char_counter];
      // Move to the next symbol
      ++char_counter;
    } else {
      // Header value
      temp_http_header_value += http_request_string[char_counter];
      // Move to the next symbol
      ++char_counter;
    }
  }

  // TO-DO
  // Void symbol ?
  std::string body = "";

  while (char_counter < http_request_string.size()) {

    body += http_request_string[char_counter];
    ++char_counter;
  }

  // DEBUG

  /*
  std::cerr << "Method: \t\t" << method << std::endl;
  std::cerr << "Target: \t\t" << target << std::endl;
  std::cerr << "Version:\t\t" << version << std::endl;

  for (const auto &var : headers) {
    std::cerr << var.second << std::endl;
  }

  std::cerr << "Body:\t\t" << body << std::endl;

  std::cerr << "Request size: \t\t" << http_request_string.size() << std::endl;
  std::cerr << "Char was reacherd: \t" << char_counter << std::endl;

  */

  // Converting Strings to enum

  HTTP_METHODS_ENUM http_method_enum =
      Converter::Convert_String_Method_To_Enum_HTTP_METHODS(method);

  HTTP_VERSION http_version_enum =
      Converter::Convert_String_Version_To_Enum_HTTP_VERSION(version);

  // Return

  return HTTP_Request(http_method_enum, target, http_version_enum, headers,
                      body);
}

} // namespace jojojoster::http
