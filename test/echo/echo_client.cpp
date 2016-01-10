/**
 * @file   echo_client.cpp
 * @author  fqguozhou@gmail.com
 * @date   Sun Jan 10 22:32:14 2016
 *
 * @brief
 *
 *
 */

#include "lib/asio/client.hpp"
int
main(int, char**)
{
  std::string host("127.0.0.1");
  uint16_t port_num = 56000;
  boost::asio::io_service io_service;
  miacropp::asio::client client(io_service);
  client.connect(host, port_num);
  io_service.run();
  return 0;
}
