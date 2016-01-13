/**
 * @file   echo_server.cpp
 * @author  fqguozhou@163.com
 * @date   Sun Jan 10 22:31:55 2016
 *
 * @brief
 *
 *
 */

#include "lib/asio/server.hpp"
int
main(int, char**)
{
  const uint16_t port_num = 56000;
  boost::asio::io_service io_service;
  miacropp::asio::echo_server server(io_service);
  server.listen(port_num);
  io_service.run();
  return 0;
}
