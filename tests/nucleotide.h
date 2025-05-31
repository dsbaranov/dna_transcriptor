#pragma once
#include "../nucleotide.h"
#include "./details.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std::string_literals;

namespace test::nucleotide
{
void NucleotideTypeToSerial()
{
    std::stringstream ss("");
    ss << Nucleotide::Type::Adenine;
    assert(ss.str() == "A"s);
}
void CTOR_FromChar()
{
    Nucleotide test_nucleotide('A');
    assert(test_nucleotide.Get() == Nucleotide::Type::Adenine);
}

void CTOR_FromWrongChar()
{
    bool cant_parse = false;
    try
    {
        Nucleotide test('1');
    }
    catch (std::logic_error &)
    {
        cant_parse = true;
    }
    assert(cant_parse);
}
void CTOR_FromType()
{
    Nucleotide test(Nucleotide::Type::Guanine);
    assert(test.Get() == Nucleotide::Type::Guanine);
}
void CTOR_COPY()
{
    Nucleotide first(Nucleotide::Type::Adenine);
    Nucleotide second(first);
    assert(!first.IsNull() && !second.IsNull());
    assert(first.Get() == second.Get());
}
void OPERATOR_COPY()
{
    Nucleotide first(Nucleotide::Type::Cytosine);
    Nucleotide second = first;
    assert(!first.IsNull() && !second.IsNull());
    assert(first.Get() == second.Get());
}
void CTOR_MOVE()
{
    Nucleotide first(Nucleotide::Type::Adenine);
    Nucleotide second(std::move(first));
    assert(first.IsNull());
    bool uninit_get_impossible = false;
    try
    {
        [[maybe_unused]] Nucleotide::Type type = first.Get();
    }
    catch (std::runtime_error &)
    {
        uninit_get_impossible = true;
    }
    assert(uninit_get_impossible);
    assert(!second.IsNull());
    assert(second.Get() == Nucleotide::Type::Adenine);
}

void UNIT_TEST_Nucleotide()
{
    using namespace test::details;
    std::cout << "UNIT TEST Nucleotide" << std::endl;
    TestLambda("NucleotideToSerial", NucleotideTypeToSerial);
    TestLambda("CTOR_FromChar", CTOR_FromChar);
    TestLambda("CTOR_FromWrongChar", CTOR_FromWrongChar);
    TestLambda("CTOR_FromType", CTOR_FromType);
    TestLambda("CTOR_COPY", CTOR_COPY);
    TestLambda("OPERATOR_COPY", OPERATOR_COPY);
    TestLambda("CTOR_MOVE", CTOR_MOVE);
}
} // namespace test::nucleotide
