/*
Simple C++ program header to show how CMake works with the
{{cookiecutter.repo_name}}.
*/
#ifndef SIMPLE_INCULDE_HPP
#define SIMPLE_INCULDE_HPP

#include <stdio.h>
#include <numeric>
#include <vector>

void printSomething() {
  printf("The truth is rarely pure and never simple.\n\t-Oscar Wilde\n");
  return;
}

double mean(std::vector<double>& v) {
  if (v.size() == 0) {
    throw "Cannot calculate the mean of a vector with no length!";
  }

  return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}
#endif
