set(target_name echo_server)
set(target_files ${target_name}.cpp)
generate_test(${target_name} ${target_files})

set(target_name echo_client)
set(target_files ${target_name}.cpp)
generate_test(${target_name} ${target_files})

add_subdirectory(ace_echo ace_echo_test)
