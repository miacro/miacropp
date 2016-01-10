/**
 * @file   base64.hpp
 * @author  fqguozhou@gmail.com
 * @date   Thu Apr 30 12:45:24 2015
 *
 * @brief
 *
 *
 */

#ifndef __BASE64__H_
#define __BASE64__H_
#include "miacropp/config.hpp"
#include <string>
namespace miacropp
{
  namespace base64
  {
    using namespace std;
    const char ALPHABET[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";
    MPP_EXPORT size_t encode(char* buffer, size_t buffer_length,
                             const char* bytes_stream, size_t stream_length);
    MPP_EXPORT size_t decode(char* buffer, size_t buffer_length,
                             const char* bytes_stream, size_t stream_length);
    MPP_EXPORT string encode(const char* bytes_stream, size_t stream_length);
    MPP_EXPORT string encode(const string& bytes_stream);
    MPP_EXPORT string decode(const string& bytes_stream);
  };
};
#endif  // __BASE64__H_
