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
#include "boost/asio/spawn.hpp"
#include "boost/asio/write.hpp"
#include "boost/asio/read.hpp"
#include <string>
#include <iostream>
using namespace miacropp::asio;
using namespace boost::asio;

bool
connection::async_write(const char* data, size_t length)
{
  auto read_handler = [&](boost::asio::yield_context yield)
  {
    boost::system::error_code ec;
    auto write_size = boost::asio::async_write(
        this->socket_, boost::asio::buffer(data, length), yield[ec]);
    std::cout << "write " << write_size << " bytes." << std::endl;
  };
  boost::asio::spawn(this->read_strand_, read_handler);
  return true;
}

std::vector<char>
connection::async_read(size_t length)
{
  std::vector<char> buffer(length);
  auto read_handler = [&](boost::asio::yield_context yield)
  {
    boost::system::error_code ec;
    auto read_size = boost::asio::async_read(
        this->socket_, boost::asio::buffer(buffer), yield[ec]);
    std::cout << "read " << read_size << " bytes." << std::endl;
  };
  boost::asio::spawn(this->read_strand_, read_handler);
  return buffer;
}

bool
connection::async_connect(const std::string& host, uint16_t port)
{
  ip::tcp::endpoint endpoint(ip::address::from_string(host), port);
  static auto connect_handler = [this,
                                 endpoint](boost::asio::yield_context yield)
  {
    boost::system::error_code error_code;
    this->socket_.async_connect(endpoint, yield[error_code]);
    if (this->socket_.is_open() == false)
      return;
    if (!error_code)
    {
      std::printf("connect to remote\n");
    }
    else
    {
      std::cout << error_code.message() << std::endl;
      this->socket_.close();
    }
  };
  boost::asio::spawn(this->io_service_, connect_handler);
  return true;
}
