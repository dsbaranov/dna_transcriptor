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

  const Triplet& Get() const { return triplet_; }

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

enum class Protein {
  Phe,
  Leu,
  Ser,
  Tyr,
  Stop,
  Cys,
  Trp,
  Pro,
  His,
  Gln,
  Arg,
  Ile,
  Met,
  Thr,
  Asn,
  Lys,
  Val,
  Ala,
  Asp,
  Glu,
  Gly
};

struct ProteinDescriptionItem {
  std::string en;
  std::string ru;
};

static const std::unordered_map<Protein, ProteinDescriptionItem>
    PROTEIN_DESCRIPTION = {
        {Protein::Ala, {"Ala"s, "Ала"s}},   {Protein::Arg, {"Arg"s, "Арг"s}},
        {Protein::Asn, {"Asn"s, "Асн"s}},   {Protein::Asp, {"Asp"s, "Асп"s}},
        {Protein::Cys, {"Cys"s, "Цис"s}},   {Protein::Gln, {"Gln"s, "Глн"s}},
        {Protein::Glu, {"Glu"s, "Глу"s}},   {Protein::Gly, {"Gly"s, "Гли"s}},
        {Protein::His, {"His"s, "Гис"s}},   {Protein::Ile, {"Ile"s, "Иле"s}},
        {Protein::Leu, {"Leu"s, "Лей"s}},   {Protein::Lys, {"Lys"s, "Лиз"s}},
        {Protein::Met, {"Met"s, "Мет"s}},   {Protein::Phe, {"Phe"s, "Фен"s}},
        {Protein::Pro, {"Pro"s, "Про"s}},   {Protein::Ser, {"Ser"s, "Сер"s}},
        {Protein::Thr, {"Thr"s, "Тре"s}},   {Protein::Trp, {"Trp"s, "Три"s}},
        {Protein::Tyr, {"Tyr"s, "Тир"s}},   {Protein::Val, {"Val"s, "Вал"s}},
        {Protein::Stop, {"Stop"s, "---"s}},
};

struct TripletHasher {
  size_t operator()(const Codone::Triplet& triplet) const {
    return static_cast<size_t>(triplet[0].Get()) * 17 * 17 +
           static_cast<size_t>(triplet.at(1).Get()) * 17 +
           static_cast<size_t>(triplet.at(2).Get());
  }
};

static const std::unordered_map<Codone::Triplet, Protein, TripletHasher>
    CODONE_TO_PROTEIN{// ROW URACIL -> U C A G
                      {{Nucleotide::Type::Uracil, Nucleotide::Type::Uracil,
                        Nucleotide::Type::Uracil},
                       Protein::Phe},
                      {{Nucleotide::Type::Uracil, Nucleotide::Type::Uracil,
                        Nucleotide::Type::Cytosine},
                       Protein::Phe},
                      {{Nucleotide::Type::Uracil, Nucleotide::Type::Uracil,
                        Nucleotide::Type::Adenine},
                       Protein::Leu},
                      {{Nucleotide::Type::Uracil, Nucleotide::Type::Uracil,
                        Nucleotide::Type::Guanine},
                       Protein::Leu},

                      {{Nucleotide::Type::Uracil, Nucleotide::Type::Cytosine,
                        Nucleotide::Type::Uracil},
                       Protein::Ser},
                      {{Nucleotide::Type::Uracil, Nucleotide::Type::Cytosine,
                        Nucleotide::Type::Cytosine},
                       Protein::Ser},
                      {{Nucleotide::Type::Uracil, Nucleotide::Type::Cytosine,
                        Nucleotide::Type::Adenine},
                       Protein::Ser},
                      {{Nucleotide::Type::Uracil, Nucleotide::Type::Cytosine,
                        Nucleotide::Type::Guanine},
                       Protein::Ser},

                      {{Nucleotide::Type::Uracil, Nucleotide::Type::Adenine,
                        Nucleotide::Type::Uracil},
                       Protein::Tyr},
                      {{Nucleotide::Type::Uracil, Nucleotide::Type::Adenine,
                        Nucleotide::Type::Cytosine},
                       Protein::Tyr},
                      {{Nucleotide::Type::Uracil, Nucleotide::Type::Adenine,
                        Nucleotide::Type::Adenine},
                       Protein::Stop},
                      {{Nucleotide::Type::Uracil, Nucleotide::Type::Adenine,
                        Nucleotide::Type::Guanine},
                       Protein::Stop},

                      {{Nucleotide::Type::Uracil, Nucleotide::Type::Guanine,
                        Nucleotide::Type::Uracil},
                       Protein::Cys},
                      {{Nucleotide::Type::Uracil, Nucleotide::Type::Guanine,
                        Nucleotide::Type::Cytosine},
                       Protein::Cys},
                      {{Nucleotide::Type::Uracil, Nucleotide::Type::Guanine,
                        Nucleotide::Type::Adenine},
                       Protein::Stop},
                      {{Nucleotide::Type::Uracil, Nucleotide::Type::Guanine,
                        Nucleotide::Type::Guanine},
                       Protein::Trp},

                      // ROW CYTOSINE -> U C A G

                      {{Nucleotide::Type::Cytosine, Nucleotide::Type::Uracil,
                        Nucleotide::Type::Uracil},
                       Protein::Leu},
                      {{Nucleotide::Type::Cytosine, Nucleotide::Type::Uracil,
                        Nucleotide::Type::Cytosine},
                       Protein::Leu},
                      {{Nucleotide::Type::Cytosine, Nucleotide::Type::Uracil,
                        Nucleotide::Type::Adenine},
                       Protein::Leu},
                      {{Nucleotide::Type::Cytosine, Nucleotide::Type::Uracil,
                        Nucleotide::Type::Guanine},
                       Protein::Leu},

                      {{Nucleotide::Type::Cytosine, Nucleotide::Type::Cytosine,
                        Nucleotide::Type::Uracil},
                       Protein::Pro},
                      {{Nucleotide::Type::Cytosine, Nucleotide::Type::Cytosine,
                        Nucleotide::Type::Cytosine},
                       Protein::Pro},
                      {{Nucleotide::Type::Cytosine, Nucleotide::Type::Cytosine,
                        Nucleotide::Type::Adenine},
                       Protein::Pro},
                      {{Nucleotide::Type::Cytosine, Nucleotide::Type::Cytosine,
                        Nucleotide::Type::Guanine},
                       Protein::Pro},

                      {{Nucleotide::Type::Cytosine, Nucleotide::Type::Adenine,
                        Nucleotide::Type::Uracil},
                       Protein::His},
                      {{Nucleotide::Type::Cytosine, Nucleotide::Type::Adenine,
                        Nucleotide::Type::Cytosine},
                       Protein::His},
                      {{Nucleotide::Type::Cytosine, Nucleotide::Type::Adenine,
                        Nucleotide::Type::Adenine},
                       Protein::Gln},
                      {{Nucleotide::Type::Cytosine, Nucleotide::Type::Adenine,
                        Nucleotide::Type::Guanine},
                       Protein::Gln},

                      {{Nucleotide::Type::Cytosine, Nucleotide::Type::Guanine,
                        Nucleotide::Type::Uracil},
                       Protein::Arg},
                      {{Nucleotide::Type::Cytosine, Nucleotide::Type::Guanine,
                        Nucleotide::Type::Cytosine},
                       Protein::Arg},
                      {{Nucleotide::Type::Cytosine, Nucleotide::Type::Guanine,
                        Nucleotide::Type::Adenine},
                       Protein::Arg},
                      {{Nucleotide::Type::Cytosine, Nucleotide::Type::Guanine,
                        Nucleotide::Type::Guanine},
                       Protein::Arg},

                      // ROW ADENINE -> U C A G

                      {{Nucleotide::Type::Adenine, Nucleotide::Type::Uracil,
                        Nucleotide::Type::Uracil},
                       Protein::Ile},
                      {{Nucleotide::Type::Adenine, Nucleotide::Type::Uracil,
                        Nucleotide::Type::Cytosine},
                       Protein::Ile},
                      {{Nucleotide::Type::Adenine, Nucleotide::Type::Uracil,
                        Nucleotide::Type::Adenine},
                       Protein::Ile},
                      {{Nucleotide::Type::Adenine, Nucleotide::Type::Uracil,
                        Nucleotide::Type::Guanine},
                       Protein::Met},

                      {{Nucleotide::Type::Adenine, Nucleotide::Type::Cytosine,
                        Nucleotide::Type::Uracil},
                       Protein::Thr},
                      {{Nucleotide::Type::Adenine, Nucleotide::Type::Cytosine,
                        Nucleotide::Type::Cytosine},
                       Protein::Thr},
                      {{Nucleotide::Type::Adenine, Nucleotide::Type::Cytosine,
                        Nucleotide::Type::Adenine},
                       Protein::Thr},
                      {{Nucleotide::Type::Adenine, Nucleotide::Type::Cytosine,
                        Nucleotide::Type::Guanine},
                       Protein::Thr},

                      {{Nucleotide::Type::Adenine, Nucleotide::Type::Adenine,
                        Nucleotide::Type::Uracil},
                       Protein::Asn},
                      {{Nucleotide::Type::Adenine, Nucleotide::Type::Adenine,
                        Nucleotide::Type::Cytosine},
                       Protein::Asn},
                      {{Nucleotide::Type::Adenine, Nucleotide::Type::Adenine,
                        Nucleotide::Type::Adenine},
                       Protein::Lys},
                      {{Nucleotide::Type::Adenine, Nucleotide::Type::Adenine,
                        Nucleotide::Type::Guanine},
                       Protein::Lys},

                      {{Nucleotide::Type::Adenine, Nucleotide::Type::Guanine,
                        Nucleotide::Type::Uracil},
                       Protein::Ser},
                      {{Nucleotide::Type::Adenine, Nucleotide::Type::Guanine,
                        Nucleotide::Type::Cytosine},
                       Protein::Ser},
                      {{Nucleotide::Type::Adenine, Nucleotide::Type::Guanine,
                        Nucleotide::Type::Adenine},
                       Protein::Arg},
                      {{Nucleotide::Type::Adenine, Nucleotide::Type::Guanine,
                        Nucleotide::Type::Guanine},
                       Protein::Arg},

                      // ROW GUANINE -> U C A G

                      {{Nucleotide::Type::Guanine, Nucleotide::Type::Uracil,
                        Nucleotide::Type::Uracil},
                       Protein::Val},
                      {{Nucleotide::Type::Guanine, Nucleotide::Type::Uracil,
                        Nucleotide::Type::Cytosine},
                       Protein::Val},
                      {{Nucleotide::Type::Guanine, Nucleotide::Type::Uracil,
                        Nucleotide::Type::Adenine},
                       Protein::Val},
                      {{Nucleotide::Type::Guanine, Nucleotide::Type::Uracil,
                        Nucleotide::Type::Guanine},
                       Protein::Val},

                      {{Nucleotide::Type::Guanine, Nucleotide::Type::Cytosine,
                        Nucleotide::Type::Uracil},
                       Protein::Ala},
                      {{Nucleotide::Type::Guanine, Nucleotide::Type::Cytosine,
                        Nucleotide::Type::Cytosine},
                       Protein::Ala},
                      {{Nucleotide::Type::Guanine, Nucleotide::Type::Cytosine,
                        Nucleotide::Type::Adenine},
                       Protein::Ala},
                      {{Nucleotide::Type::Guanine, Nucleotide::Type::Cytosine,
                        Nucleotide::Type::Guanine},
                       Protein::Ala},

                      {{Nucleotide::Type::Guanine, Nucleotide::Type::Adenine,
                        Nucleotide::Type::Uracil},
                       Protein::Asp},
                      {{Nucleotide::Type::Guanine, Nucleotide::Type::Adenine,
                        Nucleotide::Type::Cytosine},
                       Protein::Asp},
                      {{Nucleotide::Type::Guanine, Nucleotide::Type::Adenine,
                        Nucleotide::Type::Adenine},
                       Protein::Glu},
                      {{Nucleotide::Type::Guanine, Nucleotide::Type::Adenine,
                        Nucleotide::Type::Guanine},
                       Protein::Glu},

                      {{Nucleotide::Type::Guanine, Nucleotide::Type::Guanine,
                        Nucleotide::Type::Uracil},
                       Protein::Gly},
                      {{Nucleotide::Type::Guanine, Nucleotide::Type::Guanine,
                        Nucleotide::Type::Cytosine},
                       Protein::Gly},
                      {{Nucleotide::Type::Guanine, Nucleotide::Type::Guanine,
                        Nucleotide::Type::Adenine},
                       Protein::Gly},
                      {{Nucleotide::Type::Guanine, Nucleotide::Type::Guanine,
                        Nucleotide::Type::Guanine},
                       Protein::Gly}};

class RnaDescriptor {
  static std::string DescribeAsString(const Codone& codone) {
    return (PROTEIN_DESCRIPTION.at(CODONE_TO_PROTEIN.at(codone.Get())));
  }
};