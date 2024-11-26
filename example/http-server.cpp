#include "../http_parser/http.h"
#include <cstddef>
#include <cstring>
#include <iostream>
#include <json/json.h>
#include <json/reader.h>
#include <json/value.h>
#include <json/writer.h>
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

    if (id < m_products.size())
      return m_products[id];

    // TO-DO
    // maybe replace expection
    throw std::out_of_range("The product doesn't exist");
  }

  const Product &GetProduct(long id) const {
    if (id < m_products.size())
      return m_products[id];

    // TO-DO
    // maybe replace expection
    throw std::out_of_range("The product doesn't exist");
  }

  /*
  void SetProduct(long id, int& error_code)
{
    if(id > s_id)
  {
      error_code = -1;
      return;
    }
  }
  */

  // Set Product - {id}  arf({id}, name, price)
  void AddProduct(const std::string &name, long price) {
    m_products.push_back(Product(m_total_id++, name, price));
  }

  // GetProductString
  std::string GetProductJSONString(long id) const {

    Json::Value root;
    root["name"] = m_products[id].GetName();
    root["price"] = m_products[id].GetPrice();

    Json::StreamWriterBuilder builder;
    return Json::writeString(builder, root);
  }
  // GetProductsString
  std::string GetProductsJsonString() const {

    Json::Value root;
    Json::Value product;

    for (long id_counter = 0; id_counter < m_total_id; ++id_counter) {
      //
      // TO-DO
      // Remove id from Product class.
      // Move JsonString function
      // to ProductDataBase class
      //
      product["id"] = id_counter;
      product["name"] = m_products[id_counter].GetName();
      product["price"] = m_products[id_counter].GetPrice();

      root.insert(root.size(), product);
    }

    Json::StreamWriterBuilder builder;

    return Json::writeString(builder, root);
  }

  void DeleteProduct(long id, int &error_code) {
    // TO-DO
    // Maybe add error_code
    if (id > m_total_id) {

      error_code = -1;
      return;
    }

    error_code = 0;

    m_products.erase(m_products.begin() + id);

    --m_total_id;
  }

  long GetProductSize() const { return m_total_id; }

private:
  std::vector<Product> m_products;

  long m_total_id = 0;
};

//
// TO-DO
// Maybe change std::string on char*
// for optimization
int Convert_String_To_Number(const std::string &str, int &error_code) {
  int answer = 0;

  if (str.size() == 0) {
    error_code = -1;
    return answer;
  }

  for (size_t iii = 0; iii < str.size(); ++iii) {

    if ('0' <= str[iii] && str[iii] <= '9') {

      answer = (answer * 10) + (static_cast<int>(str[iii]) - 48);

      // Not correct symbol
    } else {
      error_code = -2;
      return -2;
    }
  }

  error_code = 0;
  return answer;
}

/*

// TO-DO

GET    /api/products — get list of products.     OK
GET    /api/products/{id} — get product with id. OK
POST   /api/products — add new product.          OK
DELETE /api/products/{id} — delete product.      OK  (TO-DO in ProductDataBase)
PUT    /api/products/{id} — update product.      OK  (JSON)

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

HTTP_Response HTTP_SUACESS(const std::string &message,
                           const std::string &http_connection_type) {

  HTTP_Response http_error_return(HTTP_VERSION::HTTP_1_1, HTTP_STATUS_CODE::OK,
                                  {}, message);
  http_error_return.SetHeaderValue(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Server,
                                   "OOO Uspeh");
  http_error_return.SetHeaderValue(
      HTTP_RESPONSE_HEADERS_FIELD_ENUM::Content_Length,
      std::to_string(message.size()));

  http_error_return.SetHeaderValue(HTTP_RESPONSE_HEADERS_FIELD_ENUM::Connection,
                                   http_connection_type);

  return http_error_return;
}

// -------------
// HTTP HANDLER
// -------------

HTTP_Response http_handler(const HTTP_Request &http_request,
                           ProductDataBase &product_database) {

  // -------------------------------------------------------
  // Target: /API/PRODUCTS
  // Method: GET
  // -------------------------------------------------------
  if (http_request.GetMethod() == HTTP_METHODS_ENUM::GET &&
      http_request.GetTarget() == "/api/products") {

    /*

    http_response_return.SetHeaderValue(
        HTTP_RESPONSE_HEADERS_FIELD_ENUM::Server, "Bucket OS");
    http_response_return.SetHeaderValue(
        HTTP_RESPONSE_HEADERS_FIELD_ENUM::Content_Type, "text/plain");
    */

    std::string message = product_database.GetProductsJsonString();

    return HTTP_SUACESS(message, "Once");
  }
  //
  // -------------------------------------------------------
  // Target: /api/products/{id}
  // Method: GET, DELETE, PUT  3 METHODS
  // -------------------------------------------------------
  //
  else if ((http_request.GetMethod() == HTTP_METHODS_ENUM::GET ||
            http_request.GetMethod() == HTTP_METHODS_ENUM::DELETE ||
            http_request.GetMethod() == HTTP_METHODS_ENUM::PUT) &&
           http_request.GetTarget().substr(0, 14) == "/api/products/") {

    //
    // Parse id from target (endpoint) ---------------
    //

    long parsed_from_target_product_id;
    bool idIsHas = true;

    int error_code = -1;
    parsed_from_target_product_id =
        Convert_String_To_Number(http_request.GetTarget().substr(
                                     14, http_request.GetTarget().size() - 1),
                                 error_code);

    // std::cerr << "Error code: " << error_code << std::endl;
    // std::cerr << "Product Id: " << product_id << std::endl;

    if (error_code < 0) {
      // std::cerr << "Invalid argument: " << std::endl;
      idIsHas = false;
      return HTTP_ERROR("404\nNot Found\n");
    }

    // The id of products should not be more quanity of product
    if (parsed_from_target_product_id >= product_database.GetProductSize()) {
      return HTTP_ERROR("404\nId not found.\nId not exist");
    }

    //
    // End Parse id from target (endpoint) -----------
    //

    //
    // %------------------------------------------------------
    // Target: /api/products/{ID}
    // Method: GET
    // Return Product Json
    // %------------------------------------------------------
    //
    if (http_request.GetMethod() == HTTP_METHODS_ENUM::GET) {

      // std::cerr << "/API/PRODUCTS/{" << product_id << "}" << std::endl;

      std::string message =
          product_database.GetProductJSONString(parsed_from_target_product_id);

      // std::cerr << "/API/PRODUCTS/{" << std::to_string(product_id) << "}"
      //          << std::endl;

      return HTTP_SUACESS(message, "Once");

      //
      // %------------------------------------------------------
      // Target: /api/products/{ID}
      // Method: Delete
      // Return Product Json
      // %------------------------------------------------------
      //
    } else if (http_request.GetMethod() == HTTP_METHODS_ENUM::DELETE) {

      int error_code;
      product_database.DeleteProduct(parsed_from_target_product_id, error_code);

      if (error_code < 0) {
        return HTTP_ERROR("Product not exist");
      }

      std::cerr << "/API/PRODUCTS/{"
                << std::to_string(parsed_from_target_product_id) << "}"
                << std::endl;

      return HTTP_SUACESS("Product was deleted", "Once");
      //
      // %------------------------------------------------------
      // Target: /api/products/{ID}
      // Method: PUT
      // Json
      // %------------------------------------------------------
      //
    } else if (http_request.GetMethod() == HTTP_METHODS_ENUM::PUT) {

      Json::Value root;
      Json::Reader reader;

      if (!reader.parse(http_request.GetBody(), root)) {
        return HTTP_ERROR("JSON ERROR");
      }

      if (!root.isMember("price") || !root.isMember("name")) {
        return HTTP_ERROR("JSON Members ERROR");
      }

      std::string name = root["name"].asString();
      long price = root["price"].asInt();

      product_database.GetProduct(parsed_from_target_product_id).SetName(name);
      product_database.GetProduct(parsed_from_target_product_id)
          .SetPrice(price);

      return HTTP_SUACESS("Product updated", "Once");
    }

    //
    // %------------------------------------------------------
    // Target: /api/products
    // Method: POST
    // JSON
    // %------------------------------------------------------
    //

  } else if (http_request.GetMethod() == HTTP_METHODS_ENUM::POST &&
             http_request.GetTarget() == "/api/products") {
    Json::Value root;
    Json::Reader reader;

    if (!reader.parse(http_request.GetBody(), root)) {
      return HTTP_ERROR("JSON ERROR");
    }

    if (!root.isMember("price") || !root.isMember("name")) {
      return HTTP_ERROR("JSON Members ERROR");
    }

    std::string name = root["name"].asString();
    long price = root["price"].asInt();

    product_database.AddProduct(name, price);

    return HTTP_SUACESS("Product added into the database", "Once");
  }

  return HTTP_ERROR("404\nNot Found.");
} // end http_parser

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

  ProductDataBase product_database;
  product_database.AddProduct("Apple", 123);
  product_database.AddProduct("Banana", 645);
  product_database.AddProduct("Rabbit", 8921);

  Server(listen_socket, product_database);

  close(listen_socket);
}
