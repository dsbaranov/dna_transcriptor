#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>

class Nucleotide {
 public:
  enum class Type { Adenine, Cytosine, Guanine, Thymine, Uracil };

  Nucleotide(char c) : type_(std::make_unique<Type>(ParseFromChar(c))) {}

  Nucleotide(Type type) : type_(std::make_unique<Type>(type)) {}

  Nucleotide(const Nucleotide& other)
      : type_(std::make_unique<Type>(*(other.type_))) {}
  Nucleotide& operator=(const Nucleotide& other) {
    type_ = std::make_unique<Type>(*(other.type_));
    return *this;
  }
  Nucleotide(Nucleotide&& other) {
    if (other.IsNull()) {
      throw std::logic_error("Move ctor other is uninitialized");
    }
    type_ = std::move(other.type_);
  }
  Nucleotide& operator=(Nucleotide&& other) {
    if (other.IsNull()) {
      throw std::logic_error("Move operator= other is uninitialized");
    }
    type_ = std::move(other.type_);
    return *this;
  }

  static Type ParseFromChar(char c) {
    if (!isalpha(c)) {
      throw std::logic_error("ParseFromChar can't parse : char is not letter");
    }
    if (!isupper(c)) {
      c = std::toupper(c);
    }
    switch (c) {
      case 'A':
        return Type::Adenine;
        break;
      case 'C':
        return Type::Cytosine;
        break;
      case 'G':
        return Type::Guanine;
        break;
      case 'T':
        return Type::Thymine;
        break;
      default:
        throw std::logic_error("inaproppriate symbol");
    }
  }

  Nucleotide& ToMatrix() {
    if (!type_) {
      throw std::runtime_error("ToMatrix of uninitialized is forbidden");
    }
    switch (*type_) {
      case Type::Adenine:
        *type_ = Type::Thymine;
        break;
      case Type::Cytosine:
        *type_ = Type::Guanine;
        break;
      case Type ::Guanine:
        *type_ = Type::Cytosine;
        break;
      case Type::Thymine:
        *type_ = Type::Adenine;
        break;
      default:  // in case of inapropriate U
        throw std::logic_error("forbidden Type");
    }
    return *this;
  }

  Nucleotide& ToRNA() {
    if (!type_) {
      throw std::runtime_error("ToRNA of uninitialized is forbidden");
    }
    switch (*type_) {
      case Type::Adenine:
        *type_ = Type::Uracil;
        break;
      case Type::Cytosine:
        *type_ = Type::Guanine;
        break;
      case Type ::Guanine:
        *type_ = Type::Cytosine;
        break;
      case Type::Thymine:
        *type_ = Type::Adenine;
        break;
      default:  // in case of inapropriate U
        throw std::logic_error("forbidden Type");
    }
    return *this;
  }

  Type& Get() {
    if (!type_) {
      throw std::runtime_error("Get() of uninitialized Nucleotide forbidden");
    }
    return *type_;
  }
  Type& Get() const {
    if (!type_) {
      throw std::runtime_error(
          "Get() const of uninitialized Nucleotide forbidden");
    }
    return *type_;
  }

  bool IsNull() { return type_ == nullptr; }

 private:
  std::unique_ptr<Type> type_ = nullptr;
};

std::ostream& operator<<(std::ostream& os, const Nucleotide::Type& type) {
  char c;
  switch (type) {
    case Nucleotide::Type::Adenine:
      c = 'A';
      break;
    case Nucleotide::Type::Cytosine:
      c = 'C';
      break;
    case Nucleotide::Type::Guanine:
      c = 'G';
      break;
    case Nucleotide::Type::Thymine:
      c = 'T';
      break;
    case Nucleotide::Type::Uracil:
      c = 'U';
      break;
  }
  return os << c;
}
