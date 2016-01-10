/**
 * @file   uuid.h
 * @author fqguozhou@163.com
 * @date   Mon Mar 16 12:16:37 2015
 *
 * @brief
 *
 *
 */

#ifndef __UUID_H__
#define __UUID_H__
#include "miacropp/config.hpp"
#include "string.hpp"
#include <cstdint>
#include "boost/uuid/uuid.hpp"
namespace miacropp
{
  class MPP_EXPORT uuid
  {
   public:
    uuid();
    uuid(const char *buf, size_t length = uuid::size());
    uuid(const uuid &guid);
    uuid(uuid &&guid);
    uuid &operator=(const uuid &);
    uuid &operator=(uuid &&);
    ~uuid();

    bool operator==(const uuid &) const;

   public:
    void from_string(const string &uuid_string);
    string to_string() const;
    void generate();
    const boost::uuids::uuid &get() const;
    bool is_null() const;
    static size_t size();
    const char *data() const;

   private:
    boost::uuids::uuid uuid_;
  };
};

namespace std
{
  template <>
  struct hash<miacropp::uuid>
  {
    size_t operator()(miacropp::uuid const &guid) const
    {
      return boost::uuids::hash_value(guid.get());
    }

    bool operator()(const miacropp::uuid &lhs, const miacropp::uuid &rhs) const
    {
      return lhs == rhs;
    }
  };
};

#endif  // __UUID_H__
