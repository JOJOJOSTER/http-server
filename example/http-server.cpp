#include "../http_parser/Http_Enums.h"
#include "../http_parser/Http_converter.h"
#include "../http_parser/Http_request.h"
#include "../http_parser/Http_request_parse.h"
#include "../http_parser/Http_response.h"
#include "../http_parser/Http_response_converter.h"
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <stdexcept>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

using jojojoster::http::HTTP_METHODS_ENUM;
using jojojoster::http::HTTP_Request;
using jojojoster::http::HTTP_Request_Parser_And_Converter;
using jojojoster::http::HTTP_Response;
using jojojoster::http::HTTP_Response_Converter;
using jojojoster::http::HTTP_RESPONSE_HEADERS_FIELD_ENUM;
using jojojoster::http::HTTP_STATUS_CODE;
using jojojoster::http::HTTP_VERSION;

/*

GET /api/products — получение списка продуктов.
GET /api/products/{id} — получение продукта по идентификатору.
POST /api/products — добавление нового продукта.
PUT /api/products/{id} — обновление продукта.
DELETE /api/products/{id} — удаление продукта.

*/

class Product {

public:
  //
public:
  Product() {}

  Product(long id, const std::string &name, long price)
      : m_id(id), m_name(name), m_price(price) {}

  long GetId() const { return m_id; }
  void SetId(long id) { m_id = id; }

  const std::string &GetName() const { return m_name; }
  void SetName(const std::string &name) { m_name = name; }

  long GetPrice() const { return m_price; }
  void SetPrice(long price) { m_price = price; }

  std::string GetProductString() const {
    std::string temp;
    temp += std::to_string(m_id);
    temp += " ";
    temp += m_name;
    temp += " ";
    temp += std::to_string(m_price);
    return temp;
  }

private:
  long m_id;
  std::string m_name;
  long m_price;
};

class ProductDataBase {
public:
  ProductDataBase() : m_products{} {}

  // Get Product - {id}  arg({id})              ret ({id}, name, price)
  Product &GetProduct(long id) {
    // TO-DO
    // I can add Exeption

    auto it = m_products.find(id);
    if (it != m_products.end()) {
      return it->second;
    }

    // TO-DO throw Exeption
    throw std::out_of_range("The product doesn't exist");
  }
  // Set Product - {id}  arf({id}, name, price)
  void SetOrAddProduct(long id, const std::string &name, long price) {

    auto it = m_products.find(id);

    if (it != m_products.end()) {

      it->second = Product(id, name, price);
      return;
    }

    m_products.emplace(std::pair<long, Product>(id, Product(id, name, price)));
  }
  // GetProductString
  std::string GetProductString(long id) {
    auto it = m_products.find(id);
    if (it != m_products.end()) {

      return m_products[id].GetProductString();
    }

    throw std::out_of_range("The product doesn't exist");
  }
  // GetProductsString
  std::string GetProductsString() {
    std::string answer;
    answer.reserve(1000);

    for (auto it = m_products.begin(); it != m_products.end(); ++it) {
      answer += it->second.GetProductString();
      answer += '\n';
    }

    return answer;
  }

private:
  std::map<long, Product> m_products;
};

HTTP_Response http_handler(const HTTP_Request &http_request,
                           ProductDataBase &product_database) {

  if (http_request.GetMethod() == HTTP_METHODS_ENUM::GET &&
      http_request.GetTarget() == "/api/products") {

    HTTP_Response http_response_return(HTTP_VERSION::HTTP_1_1,
                                       HTTP_STATUS_CODE::OK);

    http_response_return.SetHeaderValue(
        HTTP_RESPONSE_HEADERS_FIELD_ENUM::Server, "Bucket OS");

    std::string message;
    message.reserve(1000);

    message = product_database.GetProductsString();

    http_response_return.SetHeaderValue(
        HTTP_RESPONSE_HEADERS_FIELD_ENUM::Content_Length,
        std::to_string(message.size()));
    http_response_return.SetBody(message);

    return http_response_return;
  }

  if (http_request.GetMethod() == HTTP_METHODS_ENUM::GET &&
      http_request.GetTarget().substr(0, 14) == "/api/products/") {

    long product_id;
    bool idIsHas = true;

    try {

      product_id = std::stol(http_request.GetTarget().substr(
          14, http_request.GetTarget().size() - 1));

    } catch (const std::invalid_argument &ia) {

      std::cerr << "Invalid argument: " << ia.what() << std::endl;
      idIsHas = false;
    } catch (const std::out_of_range &oor) {

      std::cerr << "Out of range: Very larger id\n\n";
      idIsHas = false;
    }

    if (idIsHas) {

      std::cerr << "/API/PRODUCTS/{id}" << std::endl;

      HTTP_Response http_response_return(HTTP_VERSION::HTTP_1_1,
                                         HTTP_STATUS_CODE::OK);

      http_response_return.SetHeaderValue(
          HTTP_RESPONSE_HEADERS_FIELD_ENUM::Server, "Bucket OS");

      std::string message = "Product id" + std::to_string(product_id) + '\n';

      http_response_return.SetBody(message);

      http_response_return.SetHeaderValue(
          HTTP_RESPONSE_HEADERS_FIELD_ENUM::Content_Length,
          std::to_string(message.size()));

      http_response_return.SetHeaderValue(
          HTTP_RESPONSE_HEADERS_FIELD_ENUM::Connection, "Once");

      std::cerr << "/API/PRODUCTS/{" << std::to_string(product_id) << "}"
                << std::endl;

      return http_response_return;
    }
  }

  HTTP_Response http_error_return(HTTP_VERSION::HTTP_1_1,
                                  HTTP_STATUS_CODE::Not_Found, {},
                                  "404\nNot Found");
  http_error_return.SetHeaderValue(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Server,
                                   "Sosedneii otdel OS");
  http_error_return.SetHeaderValue(
      HTTP_RESPONSE_HEADERS_FIELD_ENUM::Content_Length, "13");

  return http_error_return;
}

int main() {

  // ---------------

  int listen_socket = socket(AF_INET, SOCK_STREAM, 0);

  if (listen_socket < 0) {
    std::cerr << "[SERVER] [ERROR]> Init socket" << std::endl;
    return -1;
  }

  sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(54001);

  int bind_ret =
      bind(listen_socket, (sockaddr *)&server_address, sizeof(server_address));

  if (bind_ret < 0) {
    std::cerr << "[SERVER] [ERROR]> Socket bind" << std::endl;
    close(listen_socket);
    return -2;
  }

  int ret_listen = listen(listen_socket, 5);

  if (listen_socket < 0) {
    std::cerr << "[SERVER] [ERROR]> Listen" << std::endl;
    close(listen_socket);
    return -3;
  }

  // ---------------

  while (true) {

    sockaddr_in client_address;
    socklen_t client_size = sizeof(client_size);

    int client_socket =
        accept(listen_socket, (sockaddr *)&client_address, &client_size);

    if (client_socket < 0) {
      std::cerr << "[SERVER] [CONNECTION]> Error" << std::endl;
      continue;
    }

    char buf[4096];

    memset(buf, 0, 4096);

    // GET DATA FROM CLIENT
    int recv_bytes = recv(client_socket, buf, 4096, 0);

    std::cerr << "Bytes recieved: " << recv_bytes << std::endl;

    if (recv_bytes <= 0) {
      std::cerr << "[SERVER]> Client off" << std::endl;
    } else {

      std::cerr << "Client: \n" << buf << std::endl;

      // PARSE HTTP REQUEST
      HTTP_Request http_request = HTTP_Request_Parser_And_Converter::
          Parse_String_And_Convert_To_HTTP_Request(buf);

      ProductDataBase product_database;
      product_database.SetOrAddProduct(1, "Apple", 123);
      product_database.SetOrAddProduct(2, "Banana", 645);
      product_database.SetOrAddProduct(0, "Human", 8921);

      HTTP_Response http_response =
          http_handler(http_request, product_database);

      // CONVERT HTTP RESPONSE TO STRINNG
      std::string answer =
          HTTP_Response_Converter::Convert_HTTP_Reponse_To_String(
              http_response);

      // SEND REPONSE STRING TO CLIENT
      int ret_send = send(client_socket, answer.c_str(), answer.size() + 1, 0);

      if (ret_send < 0) {
        std::cerr << "[SERVER] [ERROR]> Send" << std::endl;
      } else {
        std::cerr << "[SERVER] [CONNECTION]> Send http response" << std::endl;
      }
    }

    close(client_socket);
  }

  close(listen_socket);
}
