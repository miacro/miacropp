set(DEPEND_ROOT ${MPP_ROOT}/../mpp_install)

include_directories(${DEPEND_ROOT}/include)
include_directories(${MPP_ROOT}/src)
include_directories(${MPP_ROOT})

link_directories(${DEPEND_ROOT}/lib/${platform})

set(CMAKE_INSTALL_PREFIX ${DEPEND_ROOT}/${platform})
