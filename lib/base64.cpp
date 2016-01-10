/**
 * @file   base64.cpp
 * @author  fqguozhou@gmail.com
 * @date   Thu Apr 30 12:45:02 2015
 *
 * @brief
 *
 *
 */

#include "base64.hpp"
#include <functional>
using namespace std;
using namespace miacropp;
string
base64::encode(const string& bytes_stream)
{
  return base64::encode(bytes_stream.c_str(), bytes_stream.length());
}

string
base64::encode(const char* bytes_stream, size_t stream_length)
{
  string encoded_string;
  size_t encoded_length = stream_length / 3 * 4 + 4 + 1;
  encoded_string.resize(encoded_length);
  size_t real_length =
      base64::encode(const_cast<char*>(encoded_string.c_str()),
                     encoded_string.length(), bytes_stream, stream_length);
  if (real_length == 0)
  {
    encoded_string.erase();
    return encoded_string;
  }
  while (encoded_string.length() > real_length)
    encoded_string.pop_back();
  return encoded_string;
}

string
base64::decode(const string& bytes_stream)
{
  size_t decoded_length = bytes_stream.length() / 4 * 3 + 3 + 1;
  string decoded_string;
  decoded_string.resize(decoded_length);
  size_t real_length = base64::decode(
      const_cast<char*>(decoded_string.c_str()), decoded_string.length(),
      bytes_stream.c_str(), bytes_stream.length());
  if (real_length == 0)
  {
    decoded_string.erase();
    return decoded_string;
  }
  while (decoded_string.length() > real_length)
    decoded_string.pop_back();
  return decoded_string;
}

size_t
base64::encode(char* buffer, size_t buffer_length, const char* bytes_stream,
               size_t stream_length)
{
  size_t total_frames = (stream_length / 3);
  size_t encoded_length = 0;
  if ((stream_length % 3) == 0)
    encoded_length = total_frames * 4;
  else
    encoded_length = (total_frames + 1) * 4;
  if (buffer_length <= encoded_length)
    return 0;
  buffer[encoded_length] = '\0';

  auto encode_frame = [](char* frame_to_encode, char* frame_encoded)
  {
    size_t index = 0;
    index = (frame_to_encode[0] & 0xfc) >> 2;
    frame_encoded[0] = base64::ALPHABET[index];

    index =
        ((frame_to_encode[0] & 0x03) << 4) + ((frame_to_encode[1] & 0xf0) >> 4);
    frame_encoded[1] = base64::ALPHABET[index];

    index =
        ((frame_to_encode[1] & 0x0f) << 2) + ((frame_to_encode[2] & 0xc0) >> 6);
    frame_encoded[2] = base64::ALPHABET[index];

    index = frame_to_encode[2] & 0x3f;
    frame_encoded[3] = base64::ALPHABET[index];
  };

  for (size_t i = 0; i < total_frames; ++i)
    encode_frame(const_cast<char*>(bytes_stream) + i * 3, buffer + i * 4);

  if ((total_frames * 3) < stream_length)
  {
    size_t deal_count = total_frames * 3;
    size_t left_count = stream_length - deal_count;

    char frame_to_encode[3];
    for (size_t i = 0; i < left_count; ++i)
      frame_to_encode[i] = bytes_stream[deal_count + i];
    for (size_t i = left_count; i < 3; ++i)
      frame_to_encode[i] = 0;
    encode_frame(frame_to_encode, buffer + total_frames * 4);
    for (size_t i = left_count + 1; i < 4; ++i)
      buffer[total_frames * 4 + i] = '=';
  }
  return encoded_length;
}

size_t
base64::decode(char* buffer, size_t buffer_length, const char* bytes_stream,
               size_t stream_length)
{
  size_t total_frames = stream_length / 4;
  size_t decoded_length = total_frames * 3;
  for (size_t i = 0; bytes_stream[total_frames * 4 - 1 - i] == '='; ++i)
    --decoded_length;
  if (buffer_length <= decoded_length)
    return 0;
  buffer[decoded_length] = '\0';

  auto get_char_index = [](char ch) -> char
  {
    if ((ch >= 'A') && (ch <= 'Z'))
      return ch - 'A';
    if ((ch >= 'a') && (ch <= 'z'))
      return ch - 'a' + 26;
    if ((ch >= '0') && (ch <= '9'))
      return ch - '0' + 52;
    if (ch == '+')
      return 62;
    if (ch == '/')
      return 63;
    if (ch == '=')
      return 0;
    return -1;
  };

  auto decode_frame = [get_char_index](char* frame_to_decode,
                                       char* frame_decoded) -> int
  {
    char frame_to_decoded_index[4] = {0};
    for (size_t i = 0; i < 4; ++i)
    {
      char index = get_char_index(frame_to_decode[i]);
      if (index == -1)
        return -1;
      frame_to_decoded_index[i] = index;
    }
    frame_decoded[0] = (frame_to_decoded_index[0] << 2)
                       + ((frame_to_decoded_index[1] & 0x30) >> 4);
    frame_decoded[1] = ((frame_to_decoded_index[1] & 0x0f) << 4)
                       + ((frame_to_decoded_index[2] & 0x3c) >> 2);
    frame_decoded[2] =
        ((frame_to_decoded_index[2] & 0x03) << 6) + frame_to_decoded_index[3];
    return 0;
  };

  for (size_t i = 0; i < total_frames; ++i)
    if (decode_frame(const_cast<char*>(bytes_stream) + i * 4, buffer + i * 3)
        == -1)
      return 0;

  return decoded_length;
}
