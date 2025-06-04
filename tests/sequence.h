#pragma once
#include <cassert>
#include <sstream>
#include <string>
#include "../sequence.h"
#include "details.h"

namespace test::sequence {
void CTOR_FromString() {
  Sequence sequence("ACGACG"s);
  assert(!sequence.empty());
  assert(sequence.at(0).at(0) == Nucleotide::Type::Adenine);
  assert(sequence.at(0).at(1) == Nucleotide::Type::Cytosine);
  assert(sequence.at(0).at(2) == Nucleotide::Type::Guanine);
  assert(sequence.at(1).at(0) == Nucleotide::Type::Adenine);
  assert(sequence.at(1).at(1) == Nucleotide::Type::Cytosine);
  assert(sequence.at(1).at(2) == Nucleotide::Type::Guanine);
}

void CTOR_FromStream() {
  std::stringstream ss("ACGCGAGTA");
  Sequence sequence(ss);
  assert(sequence.at(0).at(0) == Nucleotide::Type::Adenine);
  assert(sequence.at(0).at(1) == Nucleotide::Type::Cytosine);
  assert(sequence.at(0).at(2) == Nucleotide::Type::Guanine);
  assert(sequence.at(1).at(0) == Nucleotide::Type::Cytosine);
  assert(sequence.at(1).at(1) == Nucleotide::Type::Guanine);
  assert(sequence.at(1).at(2) == Nucleotide::Type::Adenine);
  assert(sequence.at(2).at(0) == Nucleotide::Type::Guanine);
  assert(sequence.at(2).at(1) == Nucleotide::Type::Thymine);
  assert(sequence.at(2).at(2) == Nucleotide::Type::Adenine);
}

void CTOR_FromStringTimedOneMillion() {
  LOG_DURATION("CTOR_FromStringTimedOneMillion");
  Sequence sequence(test::details::GenerateRandomStringSequece(999999u));
  sequence.ToMatrix();
  sequence.ToRNA();
}
void CTOR_FromStringTimedTwoMillions() {
  LOG_DURATION("CTOR_FromStringTimedTwoMillions");
  Sequence sequence(test::details::GenerateRandomStringSequece(1999998));
  sequence.ToMatrix();
  sequence.ToRNA();
}

void UNIT_TEST_Sequence() {
  std::cout << "UNIT TEST Sequence" << std::endl;
  test::details::TestLambda("CTOR_FromString", CTOR_FromString);
  test::details::TestLambda("CTOR_FromStream", CTOR_FromStream);
  test::details::TestLambda("CTOR_FromStringTimed",
                            CTOR_FromStringTimedOneMillion);
  test::details::TestLambda("CTOR_FromStringTimedTwoMillions",
                            CTOR_FromStringTimedTwoMillions);
}
};  // namespace test::sequence
