/**
 * @file   sha224_test.cpp
 * @author  fqguozhou@gmail.com
 * @date   Mon Jun  1 16:39:07 2015
 *
 * @brief
 *
 *
 */

#include <cstdio>
#include <cassert>
#include "sha_test.hpp"

using namespace miacropp::sha;
using namespace miacropp;
void
test_sha224(string& test, string& exact_result)
{
  string hash = sha224::generate(test);
  string hash_in_hex = hash.to_hex();
  std::printf("%s\n", hash_in_hex.c_str());
  assert(hash_in_hex == exact_result);
  std::printf("string: \"%s\" pass.\n", test.c_str());
  std::printf("hash: %s\n", hash_in_hex.c_str());
}

string RESULT1 = "abd37534c7d9a2efb9465de931cd7055ffdb8879563ae98078d6d6d5";
string RESULT2 = "23097d223405d8228642a477bda255b32aadbce4bda0b3f7e36c9da7";
string RESULT3 = "d14a028c2a3a2bc9476102bb288234c415a2b01f828ea62ac5b3e42f";
string RESULT4 = "d8251b4c6b0f34a9c960b67baa4e52bbf8ce03a2cf2364002a69301f";
string RESULT5 = "ed87e1ada2443eb3217bd2d54c83780ebcbb0b021916ca59b50da557";
string RESULT6 = "077253518320093bc58860ab1f06124f35804415676aa05e4e5bd571";
string RESULT7 = "89ed8dd66c96a599922da808e8da15ecf6979dc4d52234132b1ea9e0";
int
main(int, char**)
{
  test_sha224(TEST1, RESULT1);
  test_sha224(TEST2, RESULT2);
  test_sha224(TEST3, RESULT3);
  test_sha224(TEST4, RESULT4);
  test_sha224(TEST5, RESULT5);
  test_sha224(TEST6, RESULT6);
  test_sha224(TEST7, RESULT7);
  return 0;
}
