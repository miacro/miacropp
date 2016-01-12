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
      explicit echo_handler() = delete;
      virtual ~echo_handler() {}
      explicit echo_handler(const echo_handler&) = delete;
      explicit echo_handler(echo_handler&&) = delete;
      echo_handler& operator=(const echo_handler&) = delete;
      echo_handler& operator=(echo_handler&&) = delete;

     public:
      static void handle(connection_ptr);
    };
  };
};
#endif  // _ECHO_HANDLER__HPP__
