#include "../googletest/googletest/include/gtest/gtest.h"
#include "../http_parser/Http_Enums.h"
#include "../http_parser/Http_Header_Field.h"
#include "../http_parser/Http_request.h"

using jojojoster::http::HTTP_METHODS_ENUM;
using jojojoster::http::HTTP_Request;
using jojojoster::http::HTTP_REQUEST_HEADERS_FIELD_ENUM;
using jojojoster::http::HTTP_VERSION;

class TestRequestClass : public ::testing::Test {
protected:
  virtual void SetUp() override {

    http_request_class = new HTTP_Request(
        HTTP_METHODS_ENUM::GET, "api/product", HTTP_VERSION::HTTP_1_1,
        std::map<HTTP_REQUEST_HEADERS_FIELD_ENUM, std::string>{
            std::pair(HTTP_REQUEST_HEADERS_FIELD_ENUM::Host, "BucketOS")},
        "Hello");
  }

  virtual void TearDown() override { delete http_request_class; }

  HTTP_Request *http_request_class;
};

TEST_F(TestRequestClass, GetterMethod) {

  EXPECT_EQ(http_request_class->GetMethod(), HTTP_METHODS_ENUM::GET);
}

TEST_F(TestRequestClass, SetterMethod) {
  http_request_class->SetMethod(HTTP_METHODS_ENUM::PUT);
  EXPECT_EQ(http_request_class->GetMethod(), HTTP_METHODS_ENUM::PUT);
}

TEST_F(TestRequestClass, GetterTarget) {

  EXPECT_EQ(http_request_class->GetTarget(), "api/product");
}

TEST_F(TestRequestClass, SetterTarget) {
  http_request_class->SetTarget("api/message");
  EXPECT_EQ(http_request_class->GetTarget(), "api/message");
}

TEST_F(TestRequestClass, GetterVersion) {
  EXPECT_EQ(http_request_class->GetVersion(), HTTP_VERSION::HTTP_1_1);
}

TEST_F(TestRequestClass, SetterVersion) {
  http_request_class->SetVersion(HTTP_VERSION::HTTP_2);
  EXPECT_EQ(http_request_class->GetVersion(), HTTP_VERSION::HTTP_2);
}

TEST_F(TestRequestClass, GetterHeaderValue_1) {
  EXPECT_EQ(
      http_request_class->GetHeaderValue(HTTP_REQUEST_HEADERS_FIELD_ENUM::Host),
      "BucketOS");
}

TEST_F(TestRequestClass, GetterHeaderValue_2_Not_Exist_Header) {
  EXPECT_EQ(http_request_class
                ->GetHeaderValue(HTTP_REQUEST_HEADERS_FIELD_ENUM::Accept)
                .size(),
            0);
}

TEST_F(TestRequestClass, SetterHeaderValue_Make_New_Header) {
  http_request_class->SetHeaderValue(HTTP_REQUEST_HEADERS_FIELD_ENUM::Cookie,
                                     "MY COOKIE!!!");

  EXPECT_EQ(http_request_class->GetHeaderValue(
                HTTP_REQUEST_HEADERS_FIELD_ENUM::Cookie),
            "MY COOKIE!!!");
}

// TO-DO:
//       Make test for GetHeaderValue
//       Make test for SetHeaderValue
//

TEST_F(TestRequestClass, GetterBody) {
  EXPECT_EQ(http_request_class->GetBody(), "Hello");
}

TEST_F(TestRequestClass, SetterBody) {
  http_request_class->SetBody("This is site");
  EXPECT_EQ(http_request_class->GetBody(), "This is site");
}

/*
TEST(CLASS_REQUEST, test_1_initializing) {
  using namespace jojojoster::http;

  HTTP_Request http_request(
      HTTP_METHODS_ENUM::GET, "api/product", HTTP_VERSION::HTTP_1_1,
      std::map<HTTP_REQUEST_HEADERS_FIELD_ENUM, std::string>{
          std::pair(HTTP_REQUEST_HEADERS_FIELD_ENUM::Host, "SERVER")},
      "Hello");

  EXPECT_EQ(http_request.GetMethod(), HTTP_METHODS_ENUM::GET);
}
*/

int main() {

  ::testing::InitGoogleTest();

  return RUN_ALL_TESTS();
}
