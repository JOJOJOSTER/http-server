#include "../googletest/googletest/include/gtest/gtest.h"
#include "../http_parser/Http_response.h"
#include "../http_parser/Http_response_converter.h"

using jojojoster::http::HTTP_Response;
using jojojoster::http::HTTP_Response_Converter;
using jojojoster::http::HTTP_RESPONSE_HEADERS_FIELD_ENUM;
using jojojoster::http::HTTP_STATUS_CODE;
using jojojoster::http::HTTP_VERSION;

class ConvertHTTPReponse_To_String : public ::testing::Test {
protected:
  virtual void SetUp() override {
    std::map<HTTP_RESPONSE_HEADERS_FIELD_ENUM, std::string> headers{
        std::pair(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Server, "ServerGoritBlin")};

    http_response = new HTTP_Response(
        HTTP_VERSION::HTTP_1_1, HTTP_STATUS_CODE::OK, headers, "Vse otlichno");
  }

  HTTP_Response *http_response;
};

//
// TO-DO
// Add test
//

TEST_F(ConvertHTTPReponse_To_String, Default_test) {
  std::string expected_answer =
      "HTTP/1.1 200 OK\r\nServer: ServerGoritBlin\r\n\r\nVse otlichno";

  EXPECT_EQ(
      HTTP_Response_Converter::Convert_HTTP_Reponse_To_String(*http_response),
      expected_answer);
}

TEST_F(ConvertHTTPReponse_To_String, Set_Version) {
  std::string expected_answer =
      "HTTP/2 200 OK\r\nServer: ServerGoritBlin\r\n\r\nVse otlichno";

  http_response->SetVersion(HTTP_VERSION::HTTP_2);

  EXPECT_EQ(
      HTTP_Response_Converter::Convert_HTTP_Reponse_To_String(*http_response),
      expected_answer);
}

TEST_F(ConvertHTTPReponse_To_String, Change_Status_Code) {
  std::string expected_answer = "HTTP/1.1 418 I'm A Teapot\r\nServer: "
                                "ServerGoritBlin\r\n\r\nVse otlichno";

  http_response->SetStatusCode(HTTP_STATUS_CODE::I_m_A_Teapot);

  EXPECT_EQ(
      HTTP_Response_Converter::Convert_HTTP_Reponse_To_String(*http_response),
      expected_answer);
}

TEST_F(ConvertHTTPReponse_To_String, Add_Header) {
  std::string expected_answer =
      "HTTP/1.1 200 OK\r\nLink: "
      "https://example.com\r\nServer: ServerGoritBlin\r\n\r\nVse otlichno";

  http_response->SetHeaderValue(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Link,
                                "https://example.com");

  EXPECT_EQ(
      HTTP_Response_Converter::Convert_HTTP_Reponse_To_String(*http_response),
      expected_answer);
}

TEST_F(ConvertHTTPReponse_To_String, Add_two_header) {
  std::string expected_answer =
      "HTTP/1.1 200 OK\r\nLink: "
      "https://example.com\r\nServer: ServerGoritBlin\r\nWarning: Opa opa o pa "
      "pa\r\n\r\nVse otlichno";

  http_response->SetHeaderValue(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Link,
                                "https://example.com");

  http_response->SetHeaderValue(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Warning,
                                "Opa opa o pa pa");

  EXPECT_EQ(
      HTTP_Response_Converter::Convert_HTTP_Reponse_To_String(*http_response),
      expected_answer);
}

int main() {
  ::testing::InitGoogleTest();
  return ::RUN_ALL_TESTS();
}
