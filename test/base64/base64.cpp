/**
 * @file   base64/g_Test.cpp
 * @author  fqguozhou@gmail.com
 * @date   Thu Apr 30 17:01:59 2015
 *
 * @brief
 *
 *
 */

#include "lib/base64.hpp"
#include <cassert>
#include <string>
using namespace std;
using namespace miacropp;

void
encode_assert_1(string decoded_str, string encoded_str)
{
  size_t encoded_length = decoded_str.length() / 3 * 4 + 4 + 1;
  char* encoded_string = new char[encoded_length];
  size_t length = base64::encode(encoded_string, encoded_length,
                                 decoded_str.c_str(), decoded_str.length());
  assert(encoded_str == encoded_string);
  assert(static_cast<size_t>(length) == encoded_str.length());
  std::printf("encode test string: \"%s\" pass.\n", decoded_str.c_str());
  delete encoded_string;
}
void
encode_assert_2(string decoded_str, string encoded_str)
{
  string encoded_string =
      base64::encode(decoded_str.c_str(), decoded_str.length());
  assert(encoded_str == encoded_string);
  std::printf("encode test string: \"%s\" pass.\n", decoded_str.c_str());
}
void
encode_assert_3(string decoded_str, string encoded_str)
{
  string encoded_string = base64::encode(decoded_str);
  assert(encoded_str == encoded_string);
  std::printf("encode test string: \"%s\" pass.\n", decoded_str.c_str());
}
void
encode_assert(string& decoded_str, string& encoded_str)
{
  encode_assert_1(decoded_str, encoded_str);
  encode_assert_2(decoded_str, encoded_str);
  encode_assert_3(decoded_str, encoded_str);
}
void
test_base64_encode()
{
  string test_encoded, test_decoded;
  test_decoded =
      "Man is distinguished, not only by his reason, "
      "but by this singular passion from other animals, "
      "which is a lust of the mind, that by a perseverance "
      "of delight in the continued and indefatigable generation "
      "of knowledge, exceeds the short vehemence of any carnal "
      "pleasure.";
  test_encoded =
      "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0"
      "aGlz"
      "IHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qg"
      "b2Yg"
      "dGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29u"
      "dGlu"
      "dWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRz"
      "IHRo"
      "ZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=";
  encode_assert(test_decoded, test_encoded);

  test_encoded = "";
  test_decoded = "";
  encode_assert(test_decoded, test_encoded);

  test_decoded = "f";
  test_encoded = "Zg==";
  encode_assert(test_decoded, test_encoded);

  test_decoded = "fo";
  test_encoded = "Zm8=";
  encode_assert(test_decoded, test_encoded);

  test_decoded = "foo";
  test_encoded = "Zm9v";
  encode_assert(test_decoded, test_encoded);

  test_decoded = "foob";
  test_encoded = "Zm9vYg==";
  encode_assert(test_decoded, test_encoded);

  test_decoded = "fooba";
  test_encoded = "Zm9vYmE=";
  encode_assert(test_decoded, test_encoded);

  test_decoded = "foobar";
  test_encoded = "Zm9vYmFy";
  encode_assert(test_decoded, test_encoded);
}

void
decode_assert_1(string encoded_str, string decoded_str)
{
  size_t decoded_length = encoded_str.length() / 4 * 3 + 3 + 1;
  char* decoded_string = new char[decoded_length];
  size_t length = base64::decode(decoded_string, decoded_length,
                                 encoded_str.c_str(), encoded_str.length());
  assert(decoded_string != 0);
  assert(decoded_str == decoded_string);
  assert(decoded_str.length() == static_cast<size_t>(length));
  std::printf("decode test string: \"%s\" pass.\n", encoded_str.c_str());
  delete decoded_string;
}
void
decode_assert_2(string encoded_str, string decoded_str)
{
  string decoded_string = base64::decode(encoded_str);
  assert(decoded_str == decoded_string);
  std::printf("decode test string: \"%s\" pass.\n", encoded_str.c_str());
}

void
decode_assert(string& encoded_str, string& decoded_str)
{
  decode_assert_1(encoded_str, decoded_str);
  decode_assert_2(encoded_str, decoded_str);
}

void
test_base64_decode()
{
  string test_encoded, test_decoded;
  test_decoded =
      "Man is distinguished, not only by his reason, "
      "but by this singular passion from other animals, "
      "which is a lust of the mind, that by a perseverance "
      "of delight in the continued and indefatigable generation "
      "of knowledge, exceeds the short vehemence of any carnal "
      "pleasure.";
  test_encoded =
      "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0"
      "aGlz"
      "IHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qg"
      "b2Yg"
      "dGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29u"
      "dGlu"
      "dWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRz"
      "IHRo"
      "ZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=";
  decode_assert(test_encoded, test_decoded);

  test_encoded = "";
  test_decoded = "";
  decode_assert(test_encoded, test_decoded);

  test_decoded = "f";
  test_encoded = "Zg==";
  decode_assert(test_encoded, test_decoded);

  test_decoded = "fo";
  test_encoded = "Zm8=";
  decode_assert(test_encoded, test_decoded);

  test_decoded = "foo";
  test_encoded = "Zm9v";
  decode_assert(test_encoded, test_decoded);

  test_decoded = "foob";
  test_encoded = "Zm9vYg==";
  decode_assert(test_encoded, test_decoded);

  test_decoded = "fooba";
  test_encoded = "Zm9vYmE=";
  decode_assert(test_encoded, test_decoded);

  test_decoded = "foobar";
  test_encoded = "Zm9vYmFy";
  decode_assert(test_encoded, test_decoded);
}

int
main(int, char**)
{
  test_base64_encode();
  test_base64_decode();
  return 0;
}
