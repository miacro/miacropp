/**
 * @file   utils.cpp
 * @author  fqguozhou@gmail.com
 * @date   Fri May 22 16:13:13 2015
 *
 * @brief
 *
 *
 */

#include "utils.hpp"
#include <cstdlib>
#ifdef MPP_LINUX
#include <arpa/inet.h>
#endif
using namespace miacropp;
using namespace std;

int
utils::append_to_file(const string& data, const string& file_name)
{
  std::FILE* file = nullptr;
  file = std::fopen(file_name.c_str(), "a");
  if (file == nullptr)
    return -1;
  auto count = std::fwrite(data.c_str(), data.size(), 1, file);
  std::fclose(file);
  if (count < 1)
    return -1;
  return 0;
}

string
utils::read_whole_file(const string& file_name)
{
  return utils::read_whole_file(file_name.c_str());
}

string
utils::read_whole_file(const char* file_name)
{
  if (file_name == 0)
    return string();
  std::FILE* file = std::fopen(file_name, "r");
  if (file == 0)
    return string();
  string result_string = utils::read_whole_file(file);
  std::fclose(file);
  return result_string;
}

string
utils::read_whole_file(FILE* file)
{
  if (file == 0)
    return string();
  if (std::fseek(file, 0, SEEK_END) != 0)
    return string();
  long end_position = std::ftell(file);
  if (end_position == -1L)
    return string();
  if (std::fseek(file, 0, SEEK_SET) != 0)
    return string();
  string result_string;
  result_string.resize(end_position + 1);
  size_t length = std::fread(const_cast<char*>(result_string.c_str()), 1,
                             end_position, file);
  result_string[length] = 0;
  return result_string;
}

uint32_t
utils::host_to_net(uint32_t host)
{
  return htonl(host);
}
uint32_t
utils::net_to_host(uint32_t net)
{
  return ntohl(net);
}
uint16_t
utils::host_to_net(uint16_t host)
{
  return htons(host);
}
uint16_t
utils::net_to_host(uint16_t net)
{
  return ntohs(net);
}

uint64_t
utils::host_to_net(uint64_t host)
{
#ifdef MPP_LINUX
  return htobe64(host);
#elif defined(MPP_WIN32)
  uint16_t test = 1;
  if ((reinterpret_cast<char*>(&test))[0] == 0)
    return host;
  else
    return _byteswap_uint64(host);
#else
#error "Platform not supported."
#endif
}
uint64_t
utils::net_to_host(uint64_t net)
{
  return utils::host_to_net(net);
}
void
utils::dump_bytes(const char* bytes, size_t length, const char* filename)
{
  if (filename == 0)
    return;
  std::FILE* file = 0;
  file = std::fopen(filename, "a+");
  if (file == 0)
    return;
  std::fwrite(bytes, length, 1, file);
  std::fclose(file);
}
