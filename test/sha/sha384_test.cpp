/**
 * @file   sha384_test.cpp
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
void
test_sha384(string& test, string& exact_result)
{
  string hash = sha384::generate(test);
  string hash_in_hex = hash.to_hex();
  std::printf("%s\n", hash_in_hex.c_str());
  assert(hash_in_hex == exact_result);
  std::printf("string: \"%s\" pass.\n", test.c_str());
  std::printf("hash: %s\n", hash_in_hex.c_str());
}

string RESULT1 =
    "54a59b9f22b0b80880d8427e548b7c23abd873486e1f035dce9cd697e85175033caa88e6d5"
    "7bc35efae0b5afd3145f31";
string RESULT2 =
    "cb00753f45a35e8bb5a03d699ac65007272c32ab0eded1631a8b605a43ff5bed8086072ba1"
    "e7cc2358baeca134c825a7";
string RESULT3 =
    "38b060a751ac96384cd9327eb1b1e36a21fdb71114be07434c0cc7bf63f6e1da274edebfe7"
    "6f65fbd51ad2f14898b95b";
string RESULT4 =
    "c9f77c856f5165466b2fc4c7e8c3af9dabb4b96e068a31f5f083e1cdb41cce41d9994e0243"
    "b3ddd92b06debc03704e25";
string RESULT5 =
    "8d452e28abb1d3eb83c5047ae6f2312d284e7f041cff1ce8c81c5c44dd34925c14aad45433"
    "ccb89bf1133419a2c5bf7a";
string RESULT6 =
    "53c0b220db2c6629248c32d7053407eb2998908a6c07bbfcde4ae2fd2086f2af89fb615714"
    "cca0e4b8a375ae46764a9e";
string RESULT7 =
    "d937482fa3169042e0f513777b71d095c61814a023423bda94ce2573f2abd8201d014826ec"
    "b56efb5ff494e69b0e8b79";

int
main(int, char**)
{
  test_sha384(TEST1, RESULT1);
  test_sha384(TEST2, RESULT2);
  test_sha384(TEST3, RESULT3);
  test_sha384(TEST4, RESULT4);
  test_sha384(TEST5, RESULT5);
  test_sha384(TEST6, RESULT6);
  test_sha384(TEST7, RESULT7);
  return 0;
}
