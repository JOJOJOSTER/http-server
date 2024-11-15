#include "../googletest/googletest/include/gtest/gtest.h"
#include "../http_parser/Http_Enums.h"
#include "../http_parser/Http_response.h"
#include <unistd.h>
#include <utility>

using jojojoster::http::HTTP_Response;
using jojojoster::http::HTTP_RESPONSE_HEADERS_FIELD_ENUM;
using jojojoster::http::HTTP_STATUS_CODE;
using jojojoster::http::HTTP_VERSION;

class HTTP_Request_TEST : public ::testing::Test {
protected:
  virtual void SetUp() override {

    std::map<HTTP_RESPONSE_HEADERS_FIELD_ENUM, std::string> headers{
        std::pair(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Server, "ServerGoritBlin")};

    http_response = new HTTP_Response(
        HTTP_VERSION::HTTP_1_1, HTTP_STATUS_CODE::OK, headers, "Vse otlichno");
  }

  HTTP_Response *http_response;
};

TEST_F(HTTP_Request_TEST, GetterVersion) {
  EXPECT_EQ(http_response->GetVersion(), HTTP_VERSION::HTTP_1_1);
}

TEST_F(HTTP_Request_TEST, SetterVersion) {
  http_response->SetVersion(HTTP_VERSION::HTTP_2);
  EXPECT_EQ(http_response->GetVersion(), HTTP_VERSION::HTTP_2);
}

TEST_F(HTTP_Request_TEST, GetterStatusCode) {
  EXPECT_EQ(http_response->GetStatusCode(), HTTP_STATUS_CODE::OK);
}

TEST_F(HTTP_Request_TEST, SetterStatusCode) {

  http_response->SetStatusCode(HTTP_STATUS_CODE::Not_Found);
  EXPECT_EQ(http_response->GetStatusCode(), HTTP_STATUS_CODE::Not_Found);
}

TEST_F(HTTP_Request_TEST, GetHeaderValue_1) {

  EXPECT_EQ(
      http_response->GetHeaderValue(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Server),
      "ServerGoritBlin");
}

TEST_F(HTTP_Request_TEST, GetHeaderValue_Not_Exist) {

  EXPECT_EQ(
      http_response->GetHeaderValue(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Warning),
      "");
}

TEST_F(HTTP_Request_TEST, SetHeaderValue_For_Existing) {

  http_response->SetHeaderValue(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Server,
                                "Vse-Normalno");

  EXPECT_EQ(
      http_response->GetHeaderValue(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Server),
      "Vse-Normalno");
}

TEST_F(HTTP_Request_TEST, SetHeaderValue_For_Not_Existing) {

  http_response->SetHeaderValue(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Date,
                                "TUE, 11 Sep 2001 08:46:38 GMT");

  EXPECT_EQ(
      http_response->GetHeaderValue(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Date),
      "TUE, 11 Sep 2001 08:46:38 GMT");
}

TEST_F(HTTP_Request_TEST, ResetHeadetValue_For_Existing) {

  http_response->ResetHeader(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Server);

  EXPECT_EQ(
      http_response->GetHeaderValue(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Server),
      "");
}

TEST_F(HTTP_Request_TEST, ResetHeadetValue_For_Not_Existing) {

  http_response->ResetHeader(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Link);

  EXPECT_EQ(
      http_response->GetHeaderValue(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Link),
      "");
}

TEST_F(HTTP_Request_TEST, GetterBody) {

  EXPECT_EQ(http_response->GetBody(), "Vse otlichno");
}

TEST_F(HTTP_Request_TEST, SetterBody) {
  http_response->SetBody("Sisadmin postroil is severov dom");
  EXPECT_EQ(http_response->GetBody(), "Sisadmin postroil is severov dom");
}

int main() {
  ::testing::InitGoogleTest();

  return ::RUN_ALL_TESTS();
}
