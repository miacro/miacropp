/**
 * @file   sha512_test.cpp
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
test_sha512(string& test, string& exact_result)
{
  string hash = sha512::generate(test);
  string hash_in_hex = hash.to_hex();
  std::printf("%s\n", hash_in_hex.c_str());
  assert(hash_in_hex == exact_result);
  std::printf("string: \"%s\" pass.\n", test.c_str());
  std::printf("hash: %s\n", hash_in_hex.c_str());
}

string RESULT1 =
    "1f40fc92da241694750979ee6cf582f2d5d7d28e18335de05abc54d0560e0f5302860c652b"
    "f08d560252aa5e74210546f369fbbbce8c12cfc7957b2652fe9a75";
string RESULT2 =
    "ddaf35a193617abacc417349ae20413112e6fa4e89a97ea20a9eeee64b55d39a2192992a27"
    "4fc1a836ba3c23a3feebbd454d4423643ce80e2a9ac94fa54ca49f";
string RESULT3 =
    "cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d"
    "85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e";
string RESULT4 =
    "19401f47b3ce9cf35436389d1d08e0d58d58f563974ab9c77b8cf5b6f970cdb0ec64c62930"
    "8d153a90a9f520ebf7480b283946204b9a77c936d9ca485f15ab2c";
string RESULT5 =
    "93fa565eee502448d2c8430ada2977f846256217886e3a9c329154549e94a4ca7734ee3777"
    "e0358b8272b91909a73bd0b57e7f1b2e74648367a9d5fd418a5466";
string RESULT6 =
    "0e3fb9707cc1311024bbb6b012ce8d65b52e4ec5d4dce2bad15924d1263eb91fc64542123b"
    "52ef2b000017570fc1f831809797592260d5ec870efb5c0d515eac";
string RESULT7 =
    "38172abe0efa36bfacc4a513b5fcef7f55e0baae44ea32d697358dbee7f9feb7dc1a51d4ec"
    "e1a176d146f7d9445d3ff54006aa9b6d24f03df76215963343570c";

int
main(int, char**)
{
  test_sha512(TEST1, RESULT1);
  test_sha512(TEST2, RESULT2);
  test_sha512(TEST3, RESULT3);
  test_sha512(TEST4, RESULT4);
  test_sha512(TEST5, RESULT5);
  test_sha512(TEST6, RESULT6);
  test_sha512(TEST7, RESULT7);
  return 0;
}
