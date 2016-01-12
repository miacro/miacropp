/**
 * @file   server.hpp
 * @author  fqguozhou@gmail.com
 * @date   Sat Jan  9 00:48:18 2016
 *
 * @brief
 *
 *
 */

#ifndef __SERVER_HPP__
#define __SERVER_HPP__
#include "connection_manager.hpp"
namespace miacropp
{
  namespace asio
  {
    class server
    {
     public:
      typedef boost::asio::io_service io_service;
      typedef boost::asio::ip::tcp::acceptor acceptor;

     public:
      server(io_service& ios)
          : io_service_(ios), acceptor_(io_service_), connection_manager_()
      {
      }

      ~server() {}
      server(const server&) = delete;
      server(server&&) = delete;
      server& operator=(const server&) = delete;
      server& operator=(server&&) = delete;

     public:
      void listen(uint16_t port);

     private:
      io_service& io_service_;
      acceptor acceptor_;
      connection_manager connection_manager_;
    };
  };
};
#endif  // __SERVER_HPP__
