set(mpp_link_library ACE)
set(target_name ace_echo_server)
set(target_files ${target_name}.cpp)
generate_test(${target_name} ${target_files})
