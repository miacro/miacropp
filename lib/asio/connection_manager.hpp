/**
 * @file   handler_manager.hpp
 * @author  fqguozhou@gmail.com
 * @date   Mon Jan  4 21:39:15 2016
 *
 * @brief
 *
 *
 */

#ifndef __HANDLER_MANAGER_HPP__
#define __HANDLER_MANAGER_HPP__
#include "connection.hpp"
#include "boost/thread/thread.hpp"
#include <unordered_set>
#include <string>
namespace miacropp
{
  namespace asio
  {
    template <typename Handler>
    class handler_manager
    {
     public:
      typedef boost::shared_mutex shared_mutex;
      typedef std::unordered_set<Handler> handler_set;

     public:
      handler_manager() {}
      handler_manager(const handler_manager&) = delete;
      handler_manager(handler_manager&&) = delete;
      handler_manager& operator=(const handler_manager&) = delete;
      handler_manager& operator=(handler_manager&&) = delete;
      ~handler_manager() {}

     public:
      bool add(connection_ptr);
      bool remove(connection_ptr);

     private:
      shared_mutex shared_mutex_;
      handler_set handlers_;
    };
  };
};
#endif  // __HANDLER_MANAGER_HPP__
