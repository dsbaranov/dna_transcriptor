#pragma once

#include <cstdlib>
#include <ctime>
#include <string>
#include "../log_duration.h"

using namespace std::string_literals;

namespace test::details {
template <typename Lambda>
void TestLambda(const std::string& name, Lambda* lambda) {
  std::cout << "\tTEST "s << name;
  try {
    {
      lambda();
    }

  } catch (...) {
    std::cout << " FAILED" << std::endl;
    throw;
  }
  std::cout << " SUCCESS" << std::endl;
}

std::string GenerateRandomStringSequece(size_t length) {
  const std::string nucleotides = "ATCG";
  std::string result;
  result.reserve(length);
  std::srand(std::time(0));
  for (size_t i = 0; i < length; i++) {
    result.push_back(nucleotides.at(std::rand() % nucleotides.size()));
  }
  return result;
}

}  // namespace test::details
