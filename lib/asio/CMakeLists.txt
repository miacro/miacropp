set(src_list ${src_list}
  ${CMAKE_CURRENT_SOURCE_DIR}/server.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/client.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/echo_handler.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/connection.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/connection_manager.cpp
  PARENT_SCOPE
  )
set(mpp_link_library
  ${mpp_link_library}
  boost_coroutine
  boost_context
  boost_system
  PARENT_SCOPE
)
