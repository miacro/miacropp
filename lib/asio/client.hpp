/**
 * @file   client.hpp
 * @author  fqguozhou@gmail.com
 * @date   Sat Jan  9 00:48:49 2016
 *
 * @brief
 *
 *
 */

#ifndef __CLIENT_HPP__
#define __CLIENT_HPP__
#include "connection.hpp"
namespace miacropp
{
  namespace asio
  {
    class client
    {
     public:
      client(boost::asio::io_service& ios) : connection_(ios) {}
      ~client() {}
      client(const client&) = delete;
      client(client&&) = delete;
      client& operator=(const client&) = delete;
      client& operator=(client&&) = delete;

     public:
      void connect(const std::string& host, uint16_t port);

     private:
      connection connection_;
    };
  };
};
#endif  // __CLIENT_HPP__
