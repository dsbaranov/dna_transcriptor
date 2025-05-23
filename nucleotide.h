#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>

enum class NucleotideType { Adenine, Cytosine, Guanine, Thymine, Uracil };

std::ostream& operator<<(std::ostream& os, const NucleotideType& type) {
  char c;
  switch (type) {
    case NucleotideType::Adenine:
      c = 'A';
      break;
    case NucleotideType::Cytosine:
      c = 'C';
      break;
    case NucleotideType::Guanine:
      c = 'G';
      break;
    case NucleotideType::Thymine:
      c = 'T';
      break;
    case NucleotideType::Uracil:
      c = 'U';
      break;
  }
  return os << c;
}

class Nucleotide {
 public:
  Nucleotide(char c)
      : type_(std::make_unique<NucleotideType>(ParseFromChar(c))) {}

  Nucleotide(NucleotideType type)
      : type_(std::make_unique<NucleotideType>(type)) {}

  Nucleotide(const Nucleotide& other)
      : type_(std::make_unique<NucleotideType>(*(other.type_))) {}
  Nucleotide& operator=(const Nucleotide& other) {
    type_ = std::make_unique<NucleotideType>(*(other.type_));
    return *this;
  }
  Nucleotide(Nucleotide&& other) : type_(std::move(other.type_)) {
    other.type_.release();
  }
  Nucleotide& operator=(Nucleotide&& other) {
    type_ = std::move(other.type_);
    other.type_.release();
    return *this;
  }

  static NucleotideType ParseFromChar(char c) {
    switch (std::toupper(c)) {
      case 'A':
        return NucleotideType::Adenine;
        break;
      case 'C':
        return NucleotideType::Cytosine;
        break;
      case 'G':
        return NucleotideType::Guanine;
        break;
      case 'T':
        return NucleotideType::Thymine;
        break;
      case 'U':
        return NucleotideType::Uracil;
        break;
      default:
        throw std::logic_error("Недопустимый символ");
    }
  }

  Nucleotide& ToMatrix() {
    if (!type_) {
      throw std::runtime_error("Нуклеотид не инициализирован");
    }
    switch (*type_) {
      case NucleotideType::Adenine:
        *type_ = NucleotideType::Thymine;
        break;
      case NucleotideType::Cytosine:
        *type_ = NucleotideType::Guanine;
        break;
      case NucleotideType ::Guanine:
        *type_ = NucleotideType::Cytosine;
        break;
      case NucleotideType::Thymine:
        *type_ = NucleotideType::Adenine;
        break;
      default:  // in case of inapropriate U
        throw std::logic_error("Недопустимый тип нуклеотида");
    }
    return *this;
  }

  Nucleotide& ToRNA() {
    if (!type_) {
      throw std::runtime_error("Нуклеотид не инициализирован");
    }
    switch (*type_) {
      case NucleotideType::Adenine:
        *type_ = NucleotideType::Uracil;
        break;
      case NucleotideType::Cytosine:
        *type_ = NucleotideType::Guanine;
        break;
      case NucleotideType ::Guanine:
        *type_ = NucleotideType::Cytosine;
        break;
      case NucleotideType::Thymine:
        *type_ = NucleotideType::Adenine;
        break;
      default:  // in case of inapropriate U
        throw std::logic_error("Недопустимый тип нуклеотида");
    }
    return *this;
  }

 private:
  std::unique_ptr<NucleotideType> type_ = nullptr;
};
