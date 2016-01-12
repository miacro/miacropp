/**
 * @file   echo_handler.cpp
 * @author  fqguozhou@163.com
 * @date   Tue Jan 12 23:27:09 2016
 *
 * @brief
 *
 *
 */

#include "echo_handler.hpp"
#include <vector>
#include <iostream>
using namespace miacropp::asio;
using namespace boost::asio;
using namespace boost::system;

void
echo_handler::handle(connection_ptr peer)
{
  auto handler = [peer](yield_context yield)
  {
    std::vector<char> data(1024);
    while (true)
    {
      error_code read_error;
      auto read_size =
          peer->get_socket().async_read_some(buffer(data), yield[read_error]);
      std::cout << std::string(data.data(), read_size) << std::endl;
      if (read_error)
      {
        std::cout << read_error.message() << std::endl;
        break;
      }
      error_code write_error;
      async_write(peer->get_socket(), buffer(data, read_size),
                  yield[write_error]);
      if (write_error)
      {
        std::cout << write_error.message() << std::endl;
        break;
      }
    };
    peer->get_socket().close();
  };
  spawn(peer->get_io_service(), std::move(handler));
}
