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
#include <memory>
namespace miacropp
{
  namespace asio
  {
    class echo_handler : public std::enable_shared_from_this<echo_handler>
    {
     public:
      typedef connection::io_service io_service;
      typedef boost::asio::strand strand;
      typedef std::enable_shared_from_this<echo_handler> inherited_type;

     public:
      explicit echo_handler(connection_ptr connection)
          : inherited_type(), connection_(connection)
      {
      }
      virtual ~echo_handler() {}
      explicit echo_handler(const echo_handler& other) = delete;
      explicit echo_handler(echo_handler&& other) = delete;
      echo_handler& operator=(const echo_handler& other) = delete;
      echo_handler& operator=(echo_handler&& other) = delete;

     public:
      void handle();

     private:
      connection_ptr connection_;
    };
  };
};
#endif  // _ECHO_HANDLER__HPP__
