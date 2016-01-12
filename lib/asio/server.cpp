/**
 * @file   server.cpp
 * @author  fqguozhou@gmail.com
 * @date   Sat Jan  9 00:48:31 2016
 *
 * @brief
 *
 *
 */

#include "server.hpp"
#include "connection.hpp"
#include "echo_handler.hpp"
using namespace miacropp::asio;
using namespace boost::asio;
using namespace boost::system;
void
server::listen(uint16_t port)
{
  acceptor new_acceptor(this->io_service_,
                        ip::tcp::endpoint(ip::tcp::v4(), port), true);
  this->acceptor_ = std::move(new_acceptor);
  auto accept_handler = [this](yield_context yield)
  {
    while (true)
    {
      error_code ec;
      connection::socket socket(this->io_service_);
      this->acceptor_.async_accept(socket, yield[ec]);
      if (!ec)
      {
        if (this->acceptor_.is_open() == false)
          return;
        std::printf("accept a new connection\n");
        auto peer = std::make_shared<connection>(std::move(socket));
        if (this->connection_manager_.add(peer) == false)
        {
          socket.close();
          return;
        }
        echo_handler::handle(peer);
      }
      else
      {
        std::cout << ec.message() << std::endl;
        socket.close();
        break;
      }
    }
  };
  spawn(this->io_service_, std::move(accept_handler));
  std::cout << "listening on " << port << std::endl;
}
