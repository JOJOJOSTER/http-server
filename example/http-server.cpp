#include "../http_parser/Http_Enums.h"
#include "../http_parser/Http_converter.h"
#include "../http_parser/Http_request.h"
#include "../http_parser/Http_request_parse.h"
#include "../http_parser/Http_response.h"
#include "../http_parser/Http_response_converter.h"
#include <cstring>
#include <iostream>
#include <json/json.h>
#include <json/reader.h>
#include <json/value.h>
#include <netinet/in.h>
#include <stdexcept>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

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

    if (id < m_products.size())
      return m_products[id];

    // TO-DO throw Exeption
    throw std::out_of_range("The product doesn't exist");
  }
  // Set Product - {id}  arf({id}, name, price)
  void AddProduct(const std::string &name, long price) {
    m_products.push_back(Product(s_id++, name, price));
  }

  // GetProductString
  std::string GetProductString(long id) {

    return m_products[id].GetProductString();
  }
  // GetProductsString
  std::string GetProductsString() {
    std::string answer;
    answer.reserve(1000);

    for (long iii = 0; iii < s_id; ++iii) {
      answer += m_products[iii].GetProductString();
      answer += '\n';
    }

    return answer;
  }

  long GetProductSize() const { return s_id; }

private:
  std::vector<Product> m_products;

  long s_id = 0;
};

/*

// TO-DO

GET /api/products — get list of products.     OK
GET /api/products/{id} — get product with id. 50% (Add json return)
POST /api/products — add new product.         OK
PUT /api/products/{id} — update product.      NO  (JSON)
DELETE /api/products/{id} — delete product.   NO

*/

HTTP_Response HTTP_ERROR(const std::string &message) {
  HTTP_Response http_error_return(HTTP_VERSION::HTTP_1_1,
                                  HTTP_STATUS_CODE::Not_Found, {}, message);
  http_error_return.SetHeaderValue(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Server,
                                   "Sosedneii otdel OS");
  http_error_return.SetHeaderValue(
      HTTP_RESPONSE_HEADERS_FIELD_ENUM::Content_Length,
      std::to_string(message.size()));

  return http_error_return;
}

HTTP_Response HTTP_SUACESS(const std::string &message) {
  HTTP_Response http_error_return(HTTP_VERSION::HTTP_1_1, HTTP_STATUS_CODE::OK,
                                  {}, message);
  http_error_return.SetHeaderValue(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Server,
                                   "OOO Uspeh");
  http_error_return.SetHeaderValue(
      HTTP_RESPONSE_HEADERS_FIELD_ENUM::Content_Length,
      std::to_string(message.size()));

  return http_error_return;
}

HTTP_Response http_handler(const HTTP_Request &http_request,
                           ProductDataBase &product_database) {

  //
  // Target: /API/PRODUCTS
  // Method: GET
  //
  if (http_request.GetMethod() == HTTP_METHODS_ENUM::GET &&
      http_request.GetTarget() == "/api/products") {

    HTTP_Response http_response_return(HTTP_VERSION::HTTP_1_1,
                                       HTTP_STATUS_CODE::OK);

    http_response_return.SetHeaderValue(
        HTTP_RESPONSE_HEADERS_FIELD_ENUM::Server, "Bucket OS");
    http_response_return.SetHeaderValue(
        HTTP_RESPONSE_HEADERS_FIELD_ENUM::Content_Type, "text/plain");

    std::string message;
    message.reserve(1000);

    message = product_database.GetProductsString();

    http_response_return.SetHeaderValue(
        HTTP_RESPONSE_HEADERS_FIELD_ENUM::Content_Length,
        std::to_string(message.size()));
    http_response_return.SetBody(message);

    return http_response_return;
  }
  //
  // Target: /api/products/ or /api/products/{id}
  // Method: GET
  //
  else if (http_request.GetMethod() == HTTP_METHODS_ENUM::GET &&
           http_request.GetTarget().substr(0, 14) == "/api/products/") {

    long product_id;
    bool idIsHas = true;

    try {
      // TO-DO
      // Make similar function
      // without expection
      // (For optimization).
      //
      product_id = std::stol(http_request.GetTarget().substr(
          14, http_request.GetTarget().size() - 1));

    } catch (const std::invalid_argument &ia) {

      std::cerr << "Invalid argument: " << ia.what() << std::endl;
      idIsHas = false;
    } catch (const std::out_of_range &oor) {

      std::cerr << "Out of range: Very larger id\n\n";
      idIsHas = false;
    }
    //
    // Targer: /api/products/{ID}
    // Method: GET
    // Return Product
    //
    if (idIsHas) {

      std::cerr << "/API/PRODUCTS/{id}" << std::endl;

      HTTP_Response http_response_return(HTTP_VERSION::HTTP_1_1,
                                         HTTP_STATUS_CODE::OK);

      http_response_return.SetHeaderValue(
          HTTP_RESPONSE_HEADERS_FIELD_ENUM::Server, "Bucket OS");

      if (product_id >= product_database.GetProductSize()) {
        return HTTP_ERROR("404\nId not found");
      }

      std::string message = "Product id";
      message += product_database.GetProductString(product_id);
      message += '\n';

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

    //
    // Target: /api/products
    // Method: POST
    // JSON
    //
  } else if (http_request.GetMethod() == HTTP_METHODS_ENUM::POST &&
             http_request.GetTarget() == "/api/products") {
    Json::Value root;
    Json::Reader reader;

    if (reader.parse(http_request.GetBody(), root)) {
      product_database.AddProduct(root["name"].asString(),
                                  root["price"].asInt64());

      return HTTP_SUACESS("Product added into the database");
    } else {
      return HTTP_ERROR("Json error");
    }
  }

  return HTTP_ERROR("404\nNot Found.");
}

void Server(int listen_socket, ProductDataBase &product_database) {
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

      HTTP_Response http_response =
          http_handler(http_request, product_database);

      // CONVERT HTTP RESPONSE TO STRINNG
      std::string answer =
          HTTP_Response_Converter::Convert_HTTP_Reponse_To_String(
              http_response);

      std::cerr << "Sended: \n\n" << answer << "\n\n";

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

  std::string message = R"({"name": "Example Product", "price": 19.99})";

  Json::Value root;
  Json::Reader reader;

  reader.parse(message, root, false);

  std::cout << "Name: \t" << root["name"].asString() << std::endl;
  std::cout << "Price: \t" << root["price"].asInt() << std::endl;

  ProductDataBase product_database;
  product_database.AddProduct("Apple", 123);
  product_database.AddProduct("Banana", 645);
  product_database.AddProduct("Human", 8921);

  Server(listen_socket, product_database);

  close(listen_socket);
}
