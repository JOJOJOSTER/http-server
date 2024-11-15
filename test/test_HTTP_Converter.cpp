#include "../googletest/googletest/include/gtest/gtest.h"
#include "../http_parser/Http_converter.h"
#include "../http_parser/Http_request_parse.h"
#include <string>

using namespace jojojoster::http;

class ConverterTest : public ::testing::Test {
protected:
  virtual void SetUp() override {}

  std::string method_get = "GET";
  std::string method_post = "POST";
  std::string method_put = "PUT";
  std::string method_delete = "DELETE";

  std::string version_0_9 = "HTTP/0.9";
  std::string version_1_0 = "HTTP/1.0";
  std::string version_1_1 = "HTTP/1.1";
  std::string version_2 = "HTTP/2";
  std::string version_3 = "HTTP/3";
};

TEST_F(ConverterTest, ConvertStringToLowerCase_Method_GET) {
  std::string method_get_lower_case =
      Converter::ConvertStringToLowerCase(method_get);
  EXPECT_EQ(method_get_lower_case, "get");
}

TEST_F(ConverterTest, ConvertStringToLowerCase_Method_POST) {
  std::string method_get_lower_case =
      Converter::ConvertStringToLowerCase(method_post);
  EXPECT_EQ(method_get_lower_case, "post");
}

TEST_F(ConverterTest, ConvertStringToLowerCase_CamelCase) {
  std::string camelCase_lower_case =
      Converter::ConvertStringToLowerCase("HeLlO wOrLd!");
  EXPECT_EQ(camelCase_lower_case, "hello world!");
}

//

TEST(ConverterStringToMethodEnum, method_GET) {
  EXPECT_EQ(Converter::Convert_String_Method_To_Enum_HTTP_METHODS("GET"),
            HTTP_METHODS_ENUM::GET);
}

TEST(ConverterStringToMethodEnum, method_POST) {
  HTTP_METHODS_ENUM http_method =
      Converter::Convert_String_Method_To_Enum_HTTP_METHODS("POST");
  EXPECT_EQ(http_method, HTTP_METHODS_ENUM::POST);
}

TEST(ConverterStringToMethodEnum, method_PUT) {
  HTTP_METHODS_ENUM http_method =
      Converter::Convert_String_Method_To_Enum_HTTP_METHODS("PUT");
  EXPECT_EQ(http_method, HTTP_METHODS_ENUM::PUT);
}

// TO-DO Maybe add tests for Convert_String_Method_To_Enum_HTTP_METHODS

TEST(ConverterStringToVersionEnum, version_0_9) {
  HTTP_VERSION http_version =
      Converter::Convert_String_Version_To_Enum_HTTP_VERSION("HTTP/0.9");
  EXPECT_EQ(http_version, HTTP_VERSION::HTTP_0_9);
}

TEST(ConverterStringToVersionEnum, version_1) {
  HTTP_VERSION http_version =
      Converter::Convert_String_Version_To_Enum_HTTP_VERSION("HTTP/1.0");
  EXPECT_EQ(http_version, HTTP_VERSION::HTTP_1);
}

TEST(ConverterStringToVersionEnum, version_1_1) {
  HTTP_VERSION http_version =
      Converter::Convert_String_Version_To_Enum_HTTP_VERSION("HTTP/1.1");
  EXPECT_EQ(http_version, HTTP_VERSION::HTTP_1_1);
}

TEST(ConverterStringToVersionEnum, version_2) {
  HTTP_VERSION http_version =
      Converter::Convert_String_Version_To_Enum_HTTP_VERSION("HTTP/2");
  EXPECT_EQ(http_version, HTTP_VERSION::HTTP_2);
}

TEST(ConverterStringToVersionEnum, version_3) {
  HTTP_VERSION http_version =
      Converter::Convert_String_Version_To_Enum_HTTP_VERSION("HTTP/3");
  EXPECT_EQ(http_version, HTTP_VERSION::HTTP_3);
}

//

TEST(ConverterStringToHeaderEnum, host) {
  HTTP_REQUEST_HEADERS_FIELD_ENUM http_request_header =
      Converter::Convert_String_Header_Field_To_Enum_HTTP_Headers("HOST");
  EXPECT_EQ(HTTP_REQUEST_HEADERS_FIELD_ENUM::Host, http_request_header);
}

TEST(ConverterStringToHeaderEnum, Proxy_Authorization) {
  HTTP_REQUEST_HEADERS_FIELD_ENUM http_request_header =
      Converter::Convert_String_Header_Field_To_Enum_HTTP_Headers(
          "Proxy-Authorization");
  EXPECT_EQ(HTTP_REQUEST_HEADERS_FIELD_ENUM::Proxy_Authorization,
            http_request_header);
}

// TO-DD Maybe add tests for Convert_String_Header_Field_To_Enum_HTTP_Headers

class ParserAndConvertToHTTP_Request_TEST : public ::testing::Test {
protected:
  virtual void SetUp() override {
    std::string http_request_string_1 =
        "GET /send-message.html HTTP/1.1\nHost: mail.example.com\nReferer: "
        "http://mail.example.com/send-message.html\nUser-Agent: "
        "BrowserForDummies/4.67b\nContent-Length: \nConnection: "
        "keep-alive\r\n\r\nHello";

    HTTP_Request temp_http_request = HTTP_Request_Parser_And_Converter::
        Parse_String_And_Convert_To_HTTP_Request(http_request_string_1);

    http_request_1 = new HTTP_Request(temp_http_request);

    std::string http_request_string_2 =
        "POST /api/v1/resource HTTP/2\r\n"
        "Host: example.com\r\n"
        "Content-Type: application/json\r\n"
        "Content-Length: 44\r\n"
        "Authorization: Bearer your_token_here\r\n"
        "User-Agent: MyHttpClient/1.0\r\n"
        "\r\n"
        "{\"key1\":\"value1\",\"key2\":\"value2\"}";
    HTTP_Request temp_http_request_2 = HTTP_Request_Parser_And_Converter::
        Parse_String_And_Convert_To_HTTP_Request(http_request_string_2);

    http_request_2 = new HTTP_Request(temp_http_request_2);
  }

  HTTP_Request *http_request_1;
  HTTP_Request *http_request_2;
};

TEST_F(ParserAndConvertToHTTP_Request_TEST, Method_GET) {
  EXPECT_EQ(http_request_1->GetMethod(), HTTP_METHODS_ENUM::GET);
}

TEST_F(ParserAndConvertToHTTP_Request_TEST, Method_POST) {
  EXPECT_EQ(http_request_2->GetMethod(), HTTP_METHODS_ENUM::POST);
}

TEST_F(ParserAndConvertToHTTP_Request_TEST, Target_1) {
  EXPECT_EQ(http_request_1->GetTarget(), "/send-message.html");
}

TEST_F(ParserAndConvertToHTTP_Request_TEST, Target_2) {
  EXPECT_EQ(http_request_2->GetTarget(), "/api/v1/resource");
}

TEST_F(ParserAndConvertToHTTP_Request_TEST, Version_1) {
  EXPECT_EQ(http_request_1->GetVersion(), HTTP_VERSION::HTTP_1_1);
}

TEST_F(ParserAndConvertToHTTP_Request_TEST, Version_2) {
  EXPECT_EQ(http_request_2->GetVersion(), HTTP_VERSION::HTTP_2);
}

//
// HEADERS
//

TEST_F(ParserAndConvertToHTTP_Request_TEST, Headers_1_1) {

  EXPECT_EQ(
      http_request_1->GetHeaderValue(HTTP_REQUEST_HEADERS_FIELD_ENUM::Host),
      "mail.example.com");
}

TEST_F(ParserAndConvertToHTTP_Request_TEST, Headers_2_1) {

  EXPECT_EQ(
      http_request_2->GetHeaderValue(HTTP_REQUEST_HEADERS_FIELD_ENUM::Host),
      "example.com");
}

TEST_F(ParserAndConvertToHTTP_Request_TEST, Headers_1_2) {

  EXPECT_EQ(
      http_request_1->GetHeaderValue(HTTP_REQUEST_HEADERS_FIELD_ENUM::Referer),
      "http://mail.example.com/send-message.html");
}

TEST_F(ParserAndConvertToHTTP_Request_TEST, Headers_2_2) {

  EXPECT_EQ(
      http_request_2->GetHeaderValue(HTTP_REQUEST_HEADERS_FIELD_ENUM::Referer),
      "");
}

//
// BODY
//

TEST_F(ParserAndConvertToHTTP_Request_TEST, Body_1_1) {

  EXPECT_EQ(http_request_1->GetBody(), "Hello");
}

TEST_F(ParserAndConvertToHTTP_Request_TEST, Body_2_1) {

  EXPECT_EQ(http_request_2->GetBody(),
            "{\"key1\":\"value1\",\"key2\":\"value2\"}");
}

//
// CONVERT ENUM TO STRING
//

TEST(ConverterEnumToString, HTTP_Request_Enum) {
  HTTP_REQUEST_HEADERS_FIELD_ENUM http_request_enum =
      HTTP_REQUEST_HEADERS_FIELD_ENUM::Accept;
  std::string http_request_string =
      Converter::Convert_Enum_HTTP_Request_Headers_To_String(http_request_enum);

  EXPECT_EQ(http_request_string, "Accept");
}

int main() {
  ::testing::InitGoogleTest();

  return ::RUN_ALL_TESTS();
}
