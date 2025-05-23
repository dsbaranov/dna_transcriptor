#pragma once
#include <cassert>
#include <sstream>
#include <string>
#include "../nucleotide.h"

using namespace std::string_literals;

void TEST_NucleotideToSerial() {
  std::stringstream ss("");
  ss << NucleotideType::Adenine;
  assert(ss.str() == "A"s);
}