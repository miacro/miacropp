/**
 * @file   epoll_echo_test.cpp
 * @author  fqguozhou@163.com
 * @date   Mon Jan 18 12:19:31 2016
 *
 * @brief
 *
 *
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>

int
main(int, char**)
{
  uint16_t port_num = 56000;
  int socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_file_descriptor == -1)
    return 0;
  return 0;
}
