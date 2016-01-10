set(target_name lexer)
set(target_files
  ${CMAKE_CURRENT_SOURCE_DIR}/lexer.cpp
  )
generate_library(${target_name} ${target_files})
