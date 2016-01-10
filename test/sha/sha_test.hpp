/**
 * @file   sha_test.hpp
 * @author  fqguozhou@gmail.com
 * @date   Sun Jul 19 12:05:56 2015
 *
 * @brief
 *
 *
 */

#ifndef __SHA_TEST_HPP__
#define __SHA_TEST_HPP__
#include "lib/string.hpp"
#include "lib/sha.hpp"
using namespace miacropp;
string TEST1 = "a";
string TEST2 = "abc";
string TEST3 = "";
string TEST4 = "svpiahiohvoidsjnvinolinoihdwghonlkneolivhbniohoihoihiofh";

string TEST5 = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";

string TEST6 = TEST5 + TEST5 + TEST5 + TEST5 + TEST5 + TEST5 + TEST5 + TEST5
               + TEST5 + TEST5 + TEST5 + TEST5 + TEST5 + TEST5 + TEST5 + TEST5;

string TEST7 = TEST6 + TEST6;
#endif  // __SHA_TEST_HPP__
