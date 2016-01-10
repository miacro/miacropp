/**
 * @file   client.cpp
 * @author  fqguozhou@gmail.com
 * @date   Sat Jan  9 00:49:05 2016
 *
 * @brief
 *
 *
 */

#include "client.hpp"
using namespace miacropp::asio;
void
client::connect(const std::string &host, uint16_t port)
{
  this->connection_.async_connect(host, port);
}
