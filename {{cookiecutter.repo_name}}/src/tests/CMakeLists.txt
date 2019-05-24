message(STATUS "\n-- Setting up tests ...\n-- ")
message(STATUS "For verbose test output:\n" "\texport CTEST_OUTPUT_ON_FAILURE=1")

######################
### Compiler Flags ###
######################

# Set compiler flags for gcov
set(CMAKE_CXX_STANDARD 14) # TODO
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1) # *.cpp.o -> *.o


###################
### Dependecies ###
###################

include_directories(${INCLUDE_DIR})
include_directories(${CATCH2_INCLUDE_DIR})


###############
### Sources ###
###############

# Gather all test sources in the unittests directory
file(GLOB TEST_SOURCES *.cpp)


#####################
### Compilitation ###
#####################

# Iterate through each .cpp file found in tests and create and executable
# and test.
foreach(file ${TEST_SOURCES})
  get_filename_component(file_basename ${file} NAME_WE)

  # Convert unit-file1.cpp to unittest-file1 (creates test name)
  string(REGEX REPLACE "test_([^$]+)" "test-\\1" testcase ${file_basename})
  # message(STATUS ${testcase})

  # Add executable for test (including source file)
  # message(STATUS ${testcase} ${file})
  add_executable(${testcase} ${file})

  # Add test so executable is picked up by CMake/CTest
  # Adding Catch2 specific flag "--success" which prints out more detailed test
  # results to /build/Testing/Temporary/LastTest.log
  add_test(NAME ${testcase} COMMAND ${testcase} --success)

endforeach()
