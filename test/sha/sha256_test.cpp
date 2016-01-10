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
#include <cassert>
#include "sha_test.hpp"
using namespace miacropp::sha;

void
test_sha256(string& test, string& exact_result)
{
  string hash = sha256::generate(test);
  string hash_in_hex = hash.to_hex();
  std::printf("%s\n", hash_in_hex.c_str());
  assert(hash_in_hex == exact_result);
  std::printf("string: \"%s\" pass.\n", test.c_str());
  std::printf("hash: %s\n", hash_in_hex.c_str());
}

string RESULT1 =
    "ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb";
string RESULT2 =
    "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad";
string RESULT3 =
    "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855";
string RESULT4 =
    "eeaa9a34d36d852595d0eb256addb1c77c3fe473fac981bc899c203cde666c7b";
string RESULT5 =
    "2378d314a98e2394fec97b780aa58704a667b7dba1769473c494f4ab3f67e236";
string RESULT6 =
    "8aee5fc3470a93500f68b57522ce46b7dfd3fce654f576950fa9396bdec72423";
string RESULT7 =
    "8fc7daab2b6db5ecf0d160149b2b1ff63f2112ebc65c9e877d76be5be2a6d960";

int
main(int, char**)
{
  test_sha256(TEST1, RESULT1);
  test_sha256(TEST2, RESULT2);
  test_sha256(TEST3, RESULT3);
  test_sha256(TEST4, RESULT4);
  test_sha256(TEST5, RESULT5);
  test_sha256(TEST6, RESULT6);
  test_sha256(TEST7, RESULT7);
  return 0;
}
