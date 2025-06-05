#pragma once
#include <array>
#include <cassert>
#include <memory>
#include <unordered_map>
#include "nucleotide.h"
using namespace std::string_literals;

class Codone {
 public:
  using Triplet = std::array<Nucleotide, 3>;
  Codone() = delete;
  Codone(const Nucleotide& first,
         const Nucleotide& second,
         const Nucleotide& third)
      : triplet_{first, second, third} {}

  Codone(Nucleotide&& first, Nucleotide&& second, Nucleotide&& third)
      : triplet_{std::move(first), std::move(second), std::move(third)} {}

  Codone(const std::string& codone_string) {
    if (codone_string.size() != 3) {
      throw std::logic_error("codone string size must be 3");
    }
    for (uint8_t index(0); index < 3; index++) {
      triplet_[index] = {codone_string[index]};
    }
  }

  Codone(const Codone& other) : triplet_(other.triplet_) {}

  Codone& operator=(const Codone& other) {
    triplet_ = other.triplet_;
    return (*this);
  }

  Codone(Codone&& other) {
    for (uint8_t index = 0; index < 3; index++) {
      triplet_[index] = std::move(other.triplet_[index]);
    }
  }

  Codone& operator=(Codone&& other) {
    for (uint8_t index = 0; index < 3; index++) {
      triplet_[index] = std::move(other.triplet_[index]);
    }
    return *this;
  }

  Codone& ToMatrix() {
    for (Nucleotide& nucleotide : triplet_) {
      nucleotide.ToMatrix();
    }
    return *this;
  }

  Codone& ToRNA() {
    for (Nucleotide& nucleotide : triplet_) {
      nucleotide.ToRNA();
    }
    return *this;
  }

  const Triplet& Get() const { return triplet_; }

    Nucleotide& operator[](size_t index) {
    if (index >= triplet_.size()) {
      throw std::out_of_range("triplet index out of range");
    }
    return triplet_[index];
  }

  const Nucleotide& operator[](size_t index) const {
    if (index >= triplet_.size()) {
      throw std::out_of_range("triplet index out of range");
    }
    return triplet_.at(index);
  }

  const Nucleotide& at(size_t index) const {
    if (index >= triplet_.size()) {
      throw std::out_of_range("triplet index out of range");
    }
    return triplet_.at(index);
  }

 private:
  Triplet triplet_;
};

std::ostream& operator<<(std::ostream& os, const Codone& codone) {
  os << codone.at(0) << codone.at(1) << codone.at(2);
  return os;
}

bool operator==(const Codone& left, const Codone& right) {
  return left.at(0) == right.at(0) && left.at(1) == right.at(1) &&
         left.at(2) == right.at(2);
}
