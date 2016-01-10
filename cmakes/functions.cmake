function(generate_hook target_name INSTALL_TYPE)
  target_link_libraries(${target_name}
    ${mpp_link_library}
    )
  #  if(NOT ("${pro_library_name}" STREQUAL ""))
  #    add_dependencies(${target_name} ${pro_library_name})
  #  endif()
  set_target_properties(${target_name} PROPERTIES DEBUG_POSTFIX d)

  INSTALL(TARGETS ${target_name}
    ${INSTALL_TYPE} DESTINATION ${CMAKE_INSTALL_PREFIX}
    CONFIGURATIONS Debug
    )
  INSTALL(TARGETS ${target_name}
    ${INSTALL_TYPE} DESTINATION ${CMAKE_INSTALL_PREFIX}/release
    CONFIGURATIONS Release
    )
  if(MSVC)
    INSTALL(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Debug/
      DESTINATION ${CMAKE_INSTALL_PREFIX}/    
      CONFIGURATIONS Debug
      FILES_MATCHING 
      PATTERN *.pdb
      )
  endif()
endfunction()

function(generate_library target_name)
  set(source_lists ${ARGN})
  add_library(${target_name} SHARED ${source_lists})
  generate_hook(${target_name} ${target_library_type})
  set_target_properties(${target_name} PROPERTIES
    VERSION ${MPP_VERSION}
    SOVERSION ${MPP_MAJOR_VERSION})
endfunction()

function(generate_binary target_name)
  set(source_lists ${ARGN})
  add_executable(${target_name} ${source_lists})
  generate_hook(${target_name} "RUNTIME")
endfunction()

function(generate_test target_name)
  set(source_lists ${ARGN})
  set(CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/test)
  generate_binary(${target_name} ${source_lists})
  add_test(NAME ${target_name}
    COMMAND ${target_name}
    WORKING_DIRECTORY ${CMAKE_INSTALL_PREFIX}
    )
endfunction()
