/**
 * @file   echo_server.cpp
 * @author  fqguozhou@163.com
 * @date   Sun Jan 10 22:31:55 2016
 *
 * @brief
 *
 *
 */

#include "ace/Svc_Handler.h"
#include "ace/SOCK_Stream.h"
#include "ace/Acceptor.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/Dev_Poll_Reactor.h"
ACE_Reactor *ace_svc_reactor = nullptr;
typedef ACE_Svc_Handler<ACE_SOCK_Stream, ACE_MT_SYNCH> ace_svc_handler;
class svc_handler : public ace_svc_handler
{
 public:
  virtual int
  handle_input(ACE_HANDLE fd = ACE_INVALID_HANDLE)
  {
    if (fd == ACE_INVALID_HANDLE)
      return -1;
    char data[128];
    auto recv_size = this->peer().recv(data, 1024);
    if (recv_size == -1 || recv_size == 0)
      return -1;
    auto write_size = this->peer().send_n(data, recv_size);
    if (write_size != recv_size)
      return -1;
    return 0;
  }
  virtual int
  handle_close(ACE_HANDLE fd = ACE_INVALID_HANDLE,
               ACE_Reactor_Mask = ACE_Event_Handler::ALL_EVENTS_MASK)
  {
    if (fd == ACE_INVALID_HANDLE)
      return -1;
    this->peer().close();
    return 0;
  }
};

typedef ACE_Acceptor<svc_handler, ACE_SOCK_Acceptor> ace_svc_acceptor;
class svc_acceptor : public ace_svc_acceptor
{
 public:
  int
  listen_on_service(uint16_t service_port)
  {
    return this->open(ACE_INET_Addr(service_port), ace_svc_reactor);
  }
};

int
main(int, char **)
{
  ACE_Dev_Poll_Reactor *dev_poll_reactor = new ACE_Dev_Poll_Reactor();
  ace_svc_reactor = new ACE_Reactor(dev_poll_reactor, true);
  svc_acceptor acceptor;
  acceptor.listen_on_service(56000);
  ace_svc_reactor->run_reactor_event_loop();
  return 0;
}
