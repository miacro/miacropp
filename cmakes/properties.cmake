set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INSTALL_MESSAGE NEVER)
set(CMAKE_CXX_FLAGS "-Wall ${CMAKE_CXX_FLAGS}")
set(CMAKE_C_FLAGS "-Wall ${CMAKE_C_FLAGS}")

if(MPP_RELEASE)
  set(CMAKE_BUILD_TYPE Release)
  set(build_type_postfix "")
else()
  set(CMAKE_BUILD_TYPE Debug)
  set(build_type_postfix d)
endif()

add_definitions(-DBOOST_ALL_NO_LIB)
if(WIN32)
  add_definitions(-DMPP_WIN32)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
  set(target_library_type RUNTIME)
  if(CMAKE_CL_64)
    message(STATUS "win64")
    set(platform win64)
  else()
    message(STATUS "win32")
    set(platform win32)
  endif()
elseif(UNIX)
  add_definitions(-DMPP_LINUX)
  # set(CMAKE_CXX_COMPILER clang++)
  set(CMAKE_CXX_FLAGS_DEBUG "-ggdb ${CMAKE_CXX_FLAGS_DEBUG}")
  set(CMAKE_CXX_FLAGS "-std=c++11 -static-libstdc++ -pie -fPIC -Wall -Wextra -ldl ${CMAKE_CXX_FLAGS}")
  set(CMAKE_C_FLAGS_DEBUG "-ggdb ${CMAKE_C_FLAGS_DEBUG}")
  set(CMAKE_C_FLAGS "-std=c11 -pie -fPIC -Wextra ${CMAKE_C_FLAGS}")

  set(target_library_type LIBRARY)
  set(thread_library_name pthread)
  set(build_type_postfix "")
  set(platform linux)
endif()

set(mpp_link_library)
