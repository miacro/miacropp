/**
 * @file   utils.hpp
 * @author  fqguozhou@gmail.com
 * @date   Fri May 22 16:12:11 2015
 *
 * @brief
 *
 *
 */

#ifndef __UTILS_HPP__
#define __UTILS_HPP__
#include "miacropp/config.hpp"
#include <cstdio>
#include <cstdint>
#include <string>
namespace miacropp
{
  namespace utils
  {
    MPP_EXPORT std::string read_whole_file(const char* file_name);
    MPP_EXPORT std::string read_whole_file(const std::string& file_name);
    MPP_EXPORT std::string read_whole_file(FILE* file);
    MPP_EXPORT int append_to_file(const std::string& data,
                                  const std::string& file_name);
    MPP_EXPORT void dump_bytes(const char* bytes, size_t length,
                               const char* filename);

    MPP_EXPORT uint16_t host_to_net(uint16_t);
    MPP_EXPORT uint32_t host_to_net(uint32_t);
    MPP_EXPORT uint64_t host_to_net(uint64_t);

    MPP_EXPORT uint16_t net_to_host(uint16_t);
    MPP_EXPORT uint32_t net_to_host(uint32_t);
    MPP_EXPORT uint64_t net_to_host(uint64_t);
  };
};
#endif  // __UTILS_HPP__
