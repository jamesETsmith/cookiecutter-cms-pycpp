/*
Test case for our simple C++ program
*/

#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <vector>

#include "simple_include.hpp"

TEST_CASE("Test that our program runs", "[simple]") {
  SECTION("IO") {
    //
    printSomething();
  }

  SECTION("MATH") {
    std::vector<double> v{1, 2, 3, 4, 5};
    REQUIRE(mean(v) == 3);
  }
}
