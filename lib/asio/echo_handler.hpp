/**
 * @file   echo_handler.hpp
 * @author  fqguozhou@163.com
 * @date   Tue Jan 12 23:26:53 2016
 *
 * @brief
 *
 *
 */

#ifndef _ECHO_HANDLER__HPP__
#define _ECHO_HANDLER__HPP__
#include "connection.hpp"
namespace miacropp
{
  namespace asio
  {
    class echo_handler
    {
     public:
      typedef connection::io_service io_service;
      typedef boost::asio::strand strand;

     public:
      explicit echo_handler(connection_ptr connection) : connection_(connection)
      {
      }
      virtual ~echo_handler() {}
      explicit echo_handler(const echo_handler& other)
          : connection_(other.connection_)
      {
      }
      explicit echo_handler(echo_handler&& other)
          : connection_(std::move(other).connection_)
      {
      }
      echo_handler& operator=(const echo_handler& other)
      {
        this->connection_ = other.connection_;
        return *this;
      }
      echo_handler& operator=(echo_handler&& other)
      {
        this->connection_ = std::move(other).connection_;
        return *this;
      }

     public:
      void handle();

     private:
      connection_ptr connection_;
    };
  };
};
#endif  // _ECHO_HANDLER__HPP__
