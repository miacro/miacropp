set(target_name epoll_echo_server)
set(target_files ${target_name}.cpp)
generate_test(${target_name} ${target_files})
