set(target_name miacropp)
#add_subdirectory(websocket websocket)
add_subdirectory(asio asio)
if(UNIX)
  add_subdirectory(epoll epoll)
endif()

set(target_files ${src_list}
  ${CMAKE_CURRENT_SOURCE_DIR}/string.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/utils.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/dll.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/base64.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/sha.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/uuid.cpp
  )

generate_library(${target_name} ${target_files})
