#pragma once
#include "../sequence.h"
#include "details.h"
#include <cassert>
#include <string>

namespace test::sequence
{
void CTOR_FromString()
{
    Sequence sequence("ACGACG"s);
    assert(!sequence.empty());
    assert(sequence.at(0).at(0) == Nucleotide::Type::Adenine);
    assert(sequence.at(0).at(1) == Nucleotide::Type::Cytosine);
    assert(sequence.at(0).at(2) == Nucleotide::Type::Guanine);
    assert(sequence.at(1).at(0) == Nucleotide::Type::Adenine);
    assert(sequence.at(1).at(1) == Nucleotide::Type::Cytosine);
    assert(sequence.at(1).at(2) == Nucleotide::Type::Guanine);
}

void UNIT_TEST_Sequence()
{
    std::cout << "UNIT TEST Sequence" << std::endl;
    test::details::TestLambda("CTOR_FromString", CTOR_FromString);
}
}; // namespace test::sequence
