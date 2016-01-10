/**
 * @file   connection_manager.cpp
 * @author  fqguozhou@gmail.com
 * @date   Mon Jan  4 21:39:32 2016
 *
 * @brief
 *
 *
 */

#include "connection_manager.hpp"
using namespace miacropp::asio;
using namespace boost::asio;

bool
connection_manager::add(connection_ptr peer)
{
  auto result = this->connections_.insert(peer);
  return result.second;
}
bool
connection_manager::remove(connection_ptr peer)
{
  if (this->connections_.erase(peer) == 0)
    return false;
  else
    return true;
}
