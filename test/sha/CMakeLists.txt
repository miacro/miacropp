set(target_name sha1_test)
set(target_files ${target_name}.cpp)
generate_test(${target_name} ${target_files})

set(target_name sha224_test)
set(target_files ${target_name}.cpp)
generate_test(${target_name} ${target_files})

set(target_name sha256_test)
set(target_files ${target_name}.cpp)
generate_test(${target_name} ${target_files})

set(target_name sha384_test)
set(target_files ${target_name}.cpp)
generate_test(${target_name} ${target_files})

set(target_name sha512_test)
set(target_files ${target_name}.cpp)
generate_test(${target_name} ${target_files})
