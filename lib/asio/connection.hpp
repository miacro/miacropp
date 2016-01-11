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
#include "boost/asio/steady_timer.hpp"
#include "boost/asio/ip/tcp.hpp"
#include "boost/asio/spawn.hpp"
#include "boost/asio/write.hpp"
#include <memory>
namespace miacropp
{
  namespace asio
  {
    class connection
    {
     public:
      explicit connection(boost::asio::ip::tcp::socket&& socket)
          : io_service_(socket.get_io_service()),
            socket_(std::move(socket)),
            timer_(socket_.get_io_service()),
            write_strand_(socket_.get_io_service()),
            read_strand_(socket_.get_io_service())
      {
      }
      explicit connection(boost::asio::io_service& ios)
          : io_service_(ios),
            socket_(io_service_),
            timer_(io_service_),
            write_strand_(io_service_),
            read_strand_(io_service_)
      {
      }
      explicit connection(const connection&) = delete;
      explicit connection(connection&& other) = delete;
      connection& operator=(const connection&) = delete;
      connection& operator=(connection&&) = delete;
      ~connection() {}

     public:
      void async_write(const char* data, size_t length);
      void async_read(size_t length);
      void async_connect(const std::string& host, uint16_t port);

     protected:
      boost::asio::io_service& io_service_;
      boost::asio::ip::tcp::socket socket_;
      boost::asio::steady_timer timer_;
      boost::asio::io_service::strand write_strand_;
      boost::asio::io_service::strand read_strand_;
    };
    typedef std::shared_ptr<connection> connection_ptr;
    typedef connection_ptr connection_id;
  };
};

#endif  // __CONNECTION_HPP__
