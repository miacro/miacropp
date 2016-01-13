/**
 * @file   connection.cpp
 * @author  fqguozhou@gmail.com
 * @date   Mon Jan  4 00:35:18 2016
 *
 * @brief
 *
 *
 */

#include "connection.hpp"
#include <string>
#include <iostream>
using namespace miacropp::asio;
using namespace boost::asio;
using namespace boost::system;
typedef boost::asio::ip::tcp::endpoint endpoint;
typedef boost::asio::ip::address address;

void
connection::async_connect(const std::string& host, uint16_t port)
{
  auto connect_handler = [this, host, port](yield_context yield)
  {
    ip::tcp::endpoint endpoint(address::from_string(host), port);
    error_code error_code;
    this->socket_.async_connect(endpoint, yield[error_code]);
    this->socket_.set_option(boost::asio::socket_base::reuse_address(true));
    if (this->socket_.is_open() == false)
      return;
    if (!error_code)
    {
      //    std::printf("connect to remote\n");
    }
    else
    {
      std::cout << error_code.message() << std::endl;
      this->socket_.close();
    }
  };
  spawn(this->io_service_, std::move(connect_handler));
}

bool
connection::connect(const std::string& host, uint16_t port)
{
  ip::tcp::endpoint endpoint(address::from_string(host), port);
  error_code error_code;
  this->socket_.connect(endpoint, error_code);
  this->socket_.set_option(boost::asio::socket_base::reuse_address(true));
  if (this->socket_.is_open() == false)
    return false;
  if (!error_code)
  {
    //  std::printf("connect to remote\n");
    return true;
  }
  else
  {
    std::cout << error_code.message() << std::endl;
    this->socket_.close();
  }
  return false;
}

connection::socket&
connection::get_socket()
{
  return this->socket_;
}

connection::io_service&
connection::get_io_service()
{
  return this->io_service_;
}

void
connection::close()
{
  this->socket_.close();
}
