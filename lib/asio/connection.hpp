/**
 * @file   connection.hpp
 * @author  fqguozhou@gmail.com
 * @date   Mon Jan  4 00:35:48 2016
 *
 * @brief
 *
 *
 */

#ifndef __CONNECTION_HPP__
#define __CONNECTION_HPP__
#include "boost/asio/io_service.hpp"
#include "boost/asio/ip/tcp.hpp"
#include "boost/asio/spawn.hpp"
#include "boost/asio/write.hpp"
#include "boost/asio/read.hpp"
#include "boost/asio/buffer.hpp"
#include <memory>
namespace miacropp
{
  namespace asio
  {
    class connection
    {
     public:
      typedef boost::asio::ip::tcp::socket socket;
      typedef boost::asio::io_service io_service;

     public:
      explicit connection(socket&& socket)
          : io_service_(socket.get_io_service()), socket_(std::move(socket))
      {
      }
      explicit connection(io_service& ios)
          : io_service_(ios), socket_(io_service_)
      {
      }
      explicit connection(const connection&) = delete;
      explicit connection(connection&& other) = delete;
      connection& operator=(const connection&) = delete;
      connection& operator=(connection&&) = delete;
      ~connection() {}

     public:
      socket& get_socket();
      io_service& get_io_service();
      void close();

     public:
      void async_connect(const std::string& host, uint16_t port);
      bool connect(const std::string& host, uint16_t port);

     protected:
      io_service& io_service_;
      socket socket_;
    };
    typedef std::shared_ptr<connection> connection_ptr;
    typedef connection_ptr connection_id;
  };
};

#endif  // __CONNECTION_HPP__
