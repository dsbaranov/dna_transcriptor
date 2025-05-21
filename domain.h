#pragma once

#include <algorithm>
#include <array>
#include <iostream>
#include <stdexcept>

enum class Nucleotide { Adenine, Cytosine, Guanine, Thymine, Uracil };

std::ostream& operator<<(std::ostream& os, Nucleotide nucleotide) {
  switch (nucleotide) {
    case Nucleotide::Adenine:
      os << 'A';
      break;
    case Nucleotide::Cytosine:
      os << 'C';
      break;
    case Nucleotide::Guanine:
      os << 'G';
      break;
    case Nucleotide::Thymine:
      os << 'T';
      break;
    case Nucleotide::Uracil:
      os << 'U';
      break;
  }
  return os;
}

Nucleotide CharToNucleotide(char ch) {
  switch (std::toupper(ch)) {
    case 'A':
      return Nucleotide::Adenine;
      break;
    case 'C':
      return Nucleotide::Cytosine;
      break;
    case 'G':
      return Nucleotide::Guanine;
      break;
    case 'T':
      return Nucleotide::Thymine;
      break;
    case 'U':
      return Nucleotide::Uracil;
    default:
      throw std::out_of_range("char is not in the list of appropriate N bases");
  }
}

Nucleotide EncodeToMatrix(Nucleotide nucleotide) {
  switch (nucleotide) {
    case Nucleotide::Adenine:
      return Nucleotide::Thymine;
      break;
    case Nucleotide::Cytosine:
      return Nucleotide::Guanine;
      break;
    case Nucleotide::Guanine:
      return Nucleotide::Cytosine;
      break;
    case Nucleotide::Thymine:
      return Nucleotide::Adenine;
      break;
    default:
      throw std::logic_error(
          "invalid nucleotide to convert from coding to matrix sequence");
  }
}

static Nucleotide EncodeToRNA(Nucleotide nucleotide) {
  switch (nucleotide) {
    case Nucleotide::Adenine:
      return Nucleotide::Uracil;
      break;
    case Nucleotide::Cytosine:
      return Nucleotide::Guanine;
      break;
    case Nucleotide::Guanine:
      return Nucleotide::Cytosine;
      break;
    case Nucleotide::Thymine:
      return Nucleotide::Adenine;
      break;
    default:
      throw std::logic_error(
          "invalid base to convert from matrix to rnk sequence");
  }
}
