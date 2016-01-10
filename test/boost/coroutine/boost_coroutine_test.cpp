/**
 * @file   boost_coroutine_test.cpp
 * @author  fqguozhou@gmail.com
 * @date   Sun Jan  3 21:48:10 2016
 *
 * @brief
 *
 *
 */

#include "boost/coroutine/all.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iostream>
#include <algorithm>
using namespace std;

typedef std::vector<int> array_t;
array_t
merge_sorted_array(array_t left, array_t right)
{
  typedef boost::coroutines::symmetric_coroutine<void>::call_type call_type;
  typedef boost::coroutines::symmetric_coroutine<void>::yield_type yield_type;
  size_t index_left = 0, index_right = 0;
  array_t result;

  call_type *call_left_ptr, *call_right_ptr;

  call_type call_left([&](yield_type &yield)
                      {
                        while (index_left < left.size())
                        {
                          if (right[index_right] < left[index_left])
                            yield(*call_right_ptr);
                          result.push_back(left[index_left++]);
                        }
                        while (index_right < right.size())
                          result.push_back(right[index_right++]);
                      });
  call_type call_right([&](yield_type &yield)
                       {
                         while (index_right < right.size())
                         {
                           if (left[index_left] < right[index_right])
                             yield(*call_left_ptr);
                           result.push_back(right[index_right++]);
                         }
                         while (index_left < left.size())
                           result.push_back(left[index_left++]);
                       });
  call_left_ptr = &call_left;
  call_right_ptr = &call_right;
  call_left();
  return result;
}

array_t
general_merge_sorted_array(array_t left, array_t right)
{
  size_t index_left = 0, index_right = 0;
  array_t result;
  while ((index_left < left.size()) && (index_right < right.size()))
  {
    if (left[index_left] < right[index_right])
      result.push_back(left[index_left++]);
    else
      result.push_back(right[index_right++]);
  }
  while (index_left < left.size())
    result.push_back(left[index_left++]);
  while (index_right < right.size())
    result.push_back(right[index_right++]);
  return result;
}

int
main()
{
  const size_t left_count = 1000000;
  const size_t right_count = 2000000;
  std::srand(std::time(0));
  array_t left, right;
  for (size_t i = 0; i < left_count; ++i)
    left.push_back(std::rand());
  for (size_t i = 0; i < right_count; ++i)
    right.push_back(std::rand());

  std::sort(left.begin(), left.end());
  std::sort(right.begin(), right.end());
  auto start = std::chrono::high_resolution_clock::now();
  auto result = merge_sorted_array(left, right);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = end - start;
  std::cout << "merge array using coroutine: " << duration.count() << endl;
  start = std::chrono::high_resolution_clock::now();
  result = general_merge_sorted_array(left, right);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "merge array general: " << duration.count() << endl;
  return 0;
}
