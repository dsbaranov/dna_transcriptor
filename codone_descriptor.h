#pragma once

#include <string>
#include <unordered_map>
#include "codone.h"
#include "nucleotide.h"

using namespace std::string_literals;

struct ProteinDescriptionItem {
  std::string en;
  std::string ru;
};

std::unordered_map<Protein, ProteinDescriptionItem> PROTEIN_DESCRIPTION = {
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

static const std::unordered_map<Codone::Triplet, Protein> CODONE_TO_PROTEIN{
    // ROW URACIL -> U C A G
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
     Protein::Gly},
};

class CodoneDescriptor {
 public:
  static std::string DescribeCodoneAsString(const Codone& codone) {
    return PROTEIN_DESCRIPTION.at();
  }

 private:
};
