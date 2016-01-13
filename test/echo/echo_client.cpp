/**
 * @file   echo_client.cpp
 * @author  fqguozhou@gmail.com
 * @date   Sun Jan 10 22:32:14 2016
 *
 * @brief
 *
 *
 */

#include "lib/asio/connection.hpp"
#include <vector>
#include <thread>
#include <iostream>
#include <cstring>
using namespace miacropp::asio;
int
main(int, char**)
{
  std::string host("127.0.0.1");
  uint16_t port_num = 56000;
  std::vector<char> data(1024);
  std::string read_string;
  std::cin >> read_string;
  size_t read_size = read_string.length();
  std::memcpy(data.data(), read_string.c_str(), read_string.length());
  size_t total_count = 10000;
  auto start_time = std::chrono::steady_clock::now();
  while (total_count--)
  {
    boost::asio::io_service io_service;
    auto client = std::make_shared<connection>(io_service);
    client->connect(host, port_num);
    // std::this_thread::sleep_for(std::chrono::seconds(2));
    client->get_socket().write_some(boost::asio::buffer(data, read_size));
    read_size = client->get_socket().read_some(boost::asio::buffer(data));
  };
  auto end_time = std::chrono::steady_clock::now();
  auto expired_time = std::chrono::duration<double>(end_time - start_time);
  std::cout << expired_time.count() << " seconds." << std::endl;
  return 0;
}
