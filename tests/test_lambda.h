#pragma once

#include <string>
using namespace std::string_literals;

template <typename Lambda>
void TestLambda(const std::string& name, Lambda* lambda) {
  std::cout << "TEST "s << name;
  try {
    lambda();
  } catch (...) {
    std::cout << " FAILED" << std::endl;
  }
  std::cout << " SUCCESS" << std::endl;
}