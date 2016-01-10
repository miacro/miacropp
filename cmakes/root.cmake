cmake_minimum_required(VERSION 2.8)
project (miacropp)
set(MPP_ROOT ${PROJECT_SOURCE_DIR})

set(MPP_MAJOR_VERSION 0)
set(MPP_MINOR_VERSION 1)
set(MPP_BUILD_VERSION 1)
set(MPP_VERSION ${MPP_MAJOR_VERSION}.${MPP_MINOR_VERSION}.${MPP_BUILD_VERSION})

option(MPP_RELEASE "set the build_type(Debug default)." OFF)
option(CMAKE_CL_64 "set 32 bits or 64 bits(64 bits default)." ON)
option(BUILD_TEST "build the test project or not(OFF default)." ON)

include(${MPP_ROOT}/cmakes/functions.cmake)
include(${MPP_ROOT}/cmakes/properties.cmake)
include(${MPP_ROOT}/cmakes/path.cmake)
