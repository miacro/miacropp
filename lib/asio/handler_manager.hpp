/**
 * @file   basic_handler_manager.hpp
 * @author  fqguozhou@gmail.com
 * @date   Mon Jan  4 21:39:15 2016
 *
 * @brief
 *
 *
 */

#ifndef __BASIC_HANDLER_MANAGER_HPP__
#define __BASIC_HANDLER_MANAGER_HPP__
#include "connection.hpp"
#include "boost/thread/thread.hpp"
#include <unordered_set>
#include <string>
namespace miacropp
{
  namespace asio
  {
    template <typename Handler>
    class basic_handler_manager
    {
     public:
      typedef boost::shared_mutex shared_mutex;
      typedef boost::unique_lock<shared_mutex> unique_lock;
      typedef boost::shared_lock<shared_mutex> shared_lock;
      typedef std::shared_ptr<Handler> handler_ptr;
      typedef std::unordered_set<handler_ptr> handler_set;

     public:
      basic_handler_manager() {}
      basic_handler_manager(const basic_handler_manager&) = delete;
      basic_handler_manager(basic_handler_manager&&) = delete;
      basic_handler_manager& operator=(const basic_handler_manager&) = delete;
      basic_handler_manager& operator=(basic_handler_manager&&) = delete;
      ~basic_handler_manager() {}

     public:
      bool add(handler_ptr);
      bool remove(handler_ptr);

     private:
      shared_mutex shared_mutex_;
      handler_set handlers_;
    };

    template <typename Handler>
    bool
    basic_handler_manager<Handler>::add(handler_ptr peer)
    {
      unique_lock lock(this->shared_mutex_);
      auto result = this->handlers_.insert(peer);
      return result.second;
    }

    template <typename Handler>
    bool
    basic_handler_manager<Handler>::remove(handler_ptr peer)
    {
      unique_lock lock(this->shared_mutex_);
      if (this->handlers_.erase(peer) == 0)
        return false;
      else
        return true;
    }
  };
};
#endif  // __BASIC_HANDLER_MANAGER_HPP__
