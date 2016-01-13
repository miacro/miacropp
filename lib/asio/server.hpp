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
#include "handler_manager.hpp"
#include "echo_handler.hpp"
namespace miacropp
{
  namespace asio
  {
    template <typename Handler>
    class server
    {
     public:
      typedef boost::asio::io_service io_service;
      typedef boost::asio::ip::tcp::acceptor acceptor;
      typedef basic_handler_manager<Handler> handler_manager;
      typedef typename handler_manager::handler_ptr handler_ptr;

     public:
      server(io_service& ios)
          : io_service_(ios), acceptor_(io_service_), handler_manager_()
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
      handler_manager handler_manager_;
    };

    typedef server<echo_handler> echo_server;

    template <typename Handler>
    void
    server<Handler>::listen(uint16_t port)
    {
      using namespace boost::asio;
      using namespace boost::system;
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
            // std::printf("accept a new connection\n");
            auto peer = std::make_shared<connection>(std::move(socket));
            auto handler = std::make_shared<Handler>(peer);
            if (this->handler_manager_.add(handler) == false)
            {
              socket.close();
              return;
            }
            handler->handle();
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
  };
};
#endif  // __SERVER_HPP__
