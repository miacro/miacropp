/**
 * @file   connection_manager.hpp
 * @author  fqguozhou@gmail.com
 * @date   Mon Jan  4 21:39:15 2016
 *
 * @brief
 *
 *
 */

#ifndef __CONNECTION_MANAGER_HPP__
#define __CONNECTION_MANAGER_HPP__
#include "connection.hpp"
#include "boost/thread/thread.hpp"
#include <unordered_set>
#include <string>
namespace miacropp
{
  namespace asio
  {
    class connection_manager
    {
     public:
      typedef boost::shared_mutex shared_mutex;
      typedef std::unordered_set<connection_ptr> connection_set;

     public:
      connection_manager() {}
      connection_manager(const connection_manager&) = delete;
      connection_manager(connection_manager&&) = delete;
      connection_manager& operator=(const connection_manager&) = delete;
      connection_manager& operator=(connection_manager&&) = delete;
      ~connection_manager() {}

     public:
      bool add(connection_ptr);
      bool remove(connection_ptr);

     private:
      shared_mutex shared_mutex_;
      connection_set connections_;
    };
  };
};
#endif  // __CONNECTION_MANAGER_HPP__
