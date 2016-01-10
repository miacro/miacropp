/**
 * @file   sha1_test.cpp
 * @author  fqguozhou@gmail.com
 * @date   Mon Jun  1 16:39:07 2015
 *
 * @brief
 *
 *
 */

#include <cstdio>
#include "sha_test.hpp"
#include <cassert>
using namespace miacropp;
using namespace miacropp::sha;

void
test_sha1(string& test, string& exact_result)
{
  string hash = sha1::generate(test);
  string hash_in_hex = hash.to_hex();
  std::printf("%s\n", hash_in_hex.c_str());
  assert(hash_in_hex == exact_result);
  std::printf("string: \"%s\" pass.\n", test.c_str());
  std::printf("hash: %s\n", hash_in_hex.c_str());
}

string RESULT1 = "86f7e437faa5a7fce15d1ddcb9eaeaea377667b8";
string RESULT2 = "a9993e364706816aba3e25717850c26c9cd0d89d";
string RESULT3 = "da39a3ee5e6b4b0d3255bfef95601890afd80709";
string RESULT4 = "760d75212d6146ae512e2635493f1dee855d7a85";
string RESULT5 = "6d5025dd783aab6a0fd279bdb5fb7e0aea6cd1d5";
string RESULT6 = "52f7f771477e45169e9865c80ceb821133ed1994";
string RESULT7 = "a08e34f6e9217c901458d5f4c2f27351f60c70f7";
int
main(int, char**)
{
  test_sha1(TEST1, RESULT1);
  test_sha1(TEST2, RESULT2);
  test_sha1(TEST3, RESULT3);
  test_sha1(TEST4, RESULT4);
  test_sha1(TEST5, RESULT5);
  test_sha1(TEST6, RESULT6);
  test_sha1(TEST7, RESULT7);
  return 0;
}
