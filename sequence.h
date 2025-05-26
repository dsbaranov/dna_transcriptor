#pragma once
#include <vector>
#include "codone.h"
class Sequence {
 public:
  Sequence([[maybe_unused]] const std::string& string_sequence) {}
  Sequence([[maybe_unused]] std::istream& is) {}

  Codone at(std::size_t index) const {
    if (index >= sequence_.size()) {
      throw std::out_of_range("index out of sequence bounds");
    }
    return sequence_.at(index);
  }

 private:
  std::vector<Codone> FromString(
      [[maybe_unused]] std::string&& string_sequence) {
    return {};
  }
  std::vector<Codone> FromStream([[maybe_unused]] std::istream& is) {
    return {};
  }

  std::vector<Codone> sequence_;
};