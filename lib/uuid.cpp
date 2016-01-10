/**
 * @file   uuid.cpp
 * @author  fqguozhou@163.com
 * @date   Mon Mar 16 13:37:20 2015
 *
 * @brief
 *
 *
 */

#include "uuid.hpp"
#include <cstring>
#include "boost/uuid/string_generator.hpp"
#include "boost/uuid/random_generator.hpp"
#include "boost/uuid/uuid_io.hpp"
using namespace miacropp;
uuid::uuid() {}
uuid::~uuid() {}
uuid::uuid(const uuid &uuid) : uuid_(uuid.uuid_) {}
uuid::uuid(uuid &&uuid) { this->uuid_.swap(uuid.uuid_); }
uuid::uuid(const char *buf, size_t length)
{
  if (length < uuid::size())
    return;
  std::memcpy(this->uuid_.data, buf, uuid::size());
}

uuid &uuid::operator=(const uuid &uuid)
{
  this->uuid_ = uuid.uuid_;
  return *(this);
}

uuid &uuid::operator=(uuid &&uuid)
{
  this->uuid_.swap(uuid.uuid_);
  return *(this);
}

bool uuid::operator==(const uuid &uuid) const
{
  return this->uuid_ == uuid.uuid_;
}

void
uuid::from_string(const string &uuid)
{
  boost::uuids::string_generator string_gen;
  this->uuid_ = string_gen(uuid);
}

string
uuid::to_string() const
{
  return boost::uuids::to_string(this->uuid_);
}

void
uuid::generate()
{
  boost::uuids::random_generator rand_gen;
  this->uuid_ = rand_gen();
}

bool
uuid::is_null() const
{
  return this->uuid_.is_nil();
}

const boost::uuids::uuid &
uuid::get() const
{
  return this->uuid_;
}

size_t
uuid::size()
{
  return boost::uuids::uuid::static_size();
}
const char *
uuid::data() const
{
  return reinterpret_cast<const char *>(this->uuid_.data);
}
