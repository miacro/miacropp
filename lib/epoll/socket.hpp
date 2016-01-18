/**
 * @file   socket.hpp
 * @author  fqguozhou@163.com
 * @date   Mon Jan 18 12:10:46 2016
 *
 * @brief
 *
 *
 */

#ifndef __SOCKET_HPP__
#define __SOCKET_HPP__
#include <sys/types.h>
#include <sys/socket.h>
namespace miacropp
{
  namespace epoll
  {
    enum class domain : int
    {
      af_unix = AF_UNIX,
      af_inet = AF_INET
    };
    class socket
    {
    };
  };
};
#endif  // __SOCKET_HPP__
