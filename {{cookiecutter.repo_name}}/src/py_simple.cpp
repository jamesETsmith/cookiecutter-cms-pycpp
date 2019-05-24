#include <pybind11/pybind11.h>
#include "simple_include.hpp"

PYBIND11_MODULE(simple, m) {
  m.doc() = "pybind11 simple plugin";  // optional module docstring

  m.def("print_something", &printSomething, "A function that prints a quote.");

  m.def("mean", &mean, "A function that calculates the mean of a vector.");
}
