#pragma once
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include "codone.h"
#include "domain.h"

using namespace std::string_literals;

class Translator {
 public:
  using Sequence = std::vector<Codone>;

 private:
  Sequence sequence_;
};
