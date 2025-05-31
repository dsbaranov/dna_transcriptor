#pragma once
#include "../codone.h"
#include "details.h"
#include <memory>
#include <sstream>

namespace test::codone
{
void CTOR_Nucleotides()
{
    Nucleotide first(Nucleotide::Type::Adenine);
    Nucleotide second(Nucleotide::Type::Cytosine);
    Nucleotide third(Nucleotide::Type::Guanine);
    {
        Codone codone(first, second, third);
        assert(codone.at(0).Get() == Nucleotide::Type::Adenine);
        assert(codone.at(1).Get() == Nucleotide::Type::Cytosine);
        assert(codone.at(2).Get() == Nucleotide::Type::Guanine);
    }
    {
        Codone codone(std::move(first), std::move(second), std::move(third));
        assert(codone.at(0).Get() == Nucleotide::Type::Adenine);
        assert(codone.at(1).Get() == Nucleotide::Type::Cytosine);
        assert(codone.at(2).Get() == Nucleotide::Type::Guanine);
        assert(first.IsNull() && second.IsNull() && third.IsNull());
    }
}

void CTOR_String()
{
    Codone codone("ACG");
    assert(codone.at(0).Get() == Nucleotide::Type::Adenine);
    assert(codone.at(1).Get() == Nucleotide::Type::Cytosine);
    assert(codone.at(2).Get() == Nucleotide::Type::Guanine);
}

void CTOR_Wrong_String()
{
    bool not_created = false;
    try
    {
        [[maybe_unused]] Codone codone("ABC");
    }
    catch (...)
    {
        not_created = true;
    }
    assert(not_created == true);
}

void CTOR_COPY()
{
    Codone source("ACG");
    Codone codone(source);
    assert(codone.at(0).Get() == Nucleotide::Type::Adenine);
    assert(codone.at(1).Get() == Nucleotide::Type::Cytosine);
    assert(codone.at(2).Get() == Nucleotide::Type::Guanine);
}

void OPERATOR_COPY()
{
    Codone source("ACG");
    Codone codone("GTA");
    codone = source;
    assert(codone.at(0).Get() == Nucleotide::Type::Adenine);
    assert(codone.at(1).Get() == Nucleotide::Type::Cytosine);
    assert(codone.at(2).Get() == Nucleotide::Type::Guanine);
}

void CTOR_MOVE()
{
    Codone source("ACG");
    Codone codone(std::move(source));
    assert(codone.at(0).Get() == Nucleotide::Type::Adenine);
    assert(codone.at(1).Get() == Nucleotide::Type::Cytosine);
    assert(codone.at(2).Get() == Nucleotide::Type::Guanine);
    assert(source.at(0).IsNull() && source.at(1).IsNull() && source.at(2).IsNull());
}

void OPERATOR_MOVE()
{
    Codone source("ACG");
    Codone codone = std::move(source);
    assert(codone.at(0).Get() == Nucleotide::Type::Adenine);
    assert(codone.at(1).Get() == Nucleotide::Type::Cytosine);
    assert(codone.at(2).Get() == Nucleotide::Type::Guanine);
    assert(source.at(0).IsNull() && source.at(1).IsNull() && source.at(2).IsNull());
}

void TO_MATRIX()
{
    Codone codone("ACG");
    codone.ToMatrix();
    assert(codone.at(0).Get() == Nucleotide::Type::Thymine);
    assert(codone.at(1).Get() == Nucleotide::Type::Guanine);
    assert(codone.at(2).Get() == Nucleotide::Type::Cytosine);
}

void TO_WRONG_MATRIX()
{
    bool triggered = false;
    try
    {
        Codone codone("AUG");
        codone.ToMatrix();
    }
    catch (...)
    {
        triggered = true;
    }
    assert(triggered);
}

void TO_RNA()
{
    {
        Codone codone("ACG");
        codone.ToMatrix().ToRNA();
        assert(codone.at(0).Get() == Nucleotide::Type::Adenine);
        assert(codone.at(1).Get() == Nucleotide::Type::Cytosine);
        assert(codone.at(2).Get() == Nucleotide::Type::Guanine);
    }
    {
        Codone codone("CGT");
        codone.ToMatrix().ToRNA();
        assert(codone.at(0) == Nucleotide::Type::Cytosine);
        assert(codone.at(1) == Nucleotide::Type::Guanine);
        assert(codone.at(2) == Nucleotide::Type::Uracil);
    }
}

void TO_OSTREAM()
{
    std::string codone_string("ACG");
    {

        std::stringstream ss("");
        ss << Codone(codone_string);
        assert(ss.str() == codone_string);
    }
    {
        std::stringstream ss("");
        ss << Codone(codone_string).ToMatrix();
        assert(ss.str() == "TGC");
    }
    {
        std::stringstream ss("");
        ss << Codone(codone_string).ToMatrix().ToRNA();
        assert(ss.str() == "ACG");
    }
}

void UNIT_TEST_Codone()
{
    using namespace test::details;
    std::cout << "UNIT TEST Codone" << std::endl;
    TestLambda("CTOR_Nucleotides", CTOR_Nucleotides);
    TestLambda("CTOR_String", CTOR_String);
    TestLambda("CTOR_Wrong_String", CTOR_Wrong_String);
    TestLambda("CTOR_COPY", CTOR_COPY);
    TestLambda("OPERATOR_COPY", OPERATOR_COPY);
    TestLambda("CTOR_MOVE", CTOR_MOVE);
    TestLambda("OPERATOR_MOVE", OPERATOR_MOVE);
    TestLambda("TO_MATRIX", TO_MATRIX);
    TestLambda("TO_WRONG_MATRIX", TO_WRONG_MATRIX);
    TestLambda("TO_RNA", TO_RNA);
    TestLambda("TO_OSTREAM", TO_OSTREAM);
}
} // namespace test::codone
