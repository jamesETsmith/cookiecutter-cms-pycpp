cmake_minimum_required (VERSION 3.0)

###############
### Project ###
###############

project (simple_cpp)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-g -O3")
option(ENABLE_TESTS "Enable unit tests." OFF)

###############
### Sources ###
###############

set (EXTERNAL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external)
set (CATCH2_INCLUDE_DIR ${EXTERNAL_DIR}/Catch2/single_include/catch2)
set (INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

message(STATUS ${INCLUDE_DIR})
include_directories(${INCLUDE_DIR})
add_executable(simple_cpp ${SOURCE_DIR}/simple_cpp.cxx)

#######################
# Build Python Module #
#######################
add_subdirectory(${EXTERNAL_DIR}/pybind11)
pybind11_add_module(simple ${SOURCE_DIR}/py_simple.cpp)


###############
### Testing ###
###############

if (ENABLE_TESTS)
  include(CTest) #adds option BUILD_TESTING (default ON)
  enable_testing()
  set(TEST_DIR ${SOURCE_DIR}/tests)
  add_subdirectory(${TEST_DIR})
  message(STATUS "C++ Test Directory:" ${TEST_DIR})
endif()
