#include "domain.h"
#include "log_duration.h"
#include "sequence.h"
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

void CTOR_FromStream()
{
    LOG_DURATION("CTOR_FromStream");
    cout << "CTOR_FromStream"s;
    std::stringstream fake_in("ACGT"s);
    Sequence sequence(fake_in);
    Sequence::BaseSequence comp_sequence{NBase::A, NBase::C, NBase::G, NBase::T};
    try
    {
        assert(sequence.GetCodingSequence() == comp_sequence);
    }
    catch (...)
    {
        cout << " FAILED"s << endl;
    }
    cout << " PASSED"s << endl;
}

void CTOR_FromString()
{
    LOG_DURATION("CTOR_FromString");
    cout << "CTOR_FromString"s;
    std::string fake_str("ACGT"s);
    Sequence sequence(fake_str);
    Sequence::BaseSequence comp_sequence{NBase::A, NBase::C, NBase::G, NBase::T};
    try
    {
        assert(sequence.GetCodingSequence() == comp_sequence);
    }
    catch (...)
    {
        cout << " FAILED"s << endl;
    }
    cout << " PASSED"s << endl;
}

void TEST_Sequences()
{
    LOG_DURATION("TEST_Sequences");
    cout << "TEST_Sequences"s;
    std::string fake_str("ACGT"s);
    Sequence sequence(fake_str);
    Sequence::BaseSequence comp_ctor_sequence{NBase::A, NBase::C, NBase::G, NBase::T};
    Sequence::BaseSequence comp_matrix_sequence{NBase::T, NBase::G, NBase::C, NBase::A};
    Sequence::BaseSequence comp_rnk_sequence{NBase::A, NBase::C, NBase::G, NBase::U};
    try
    {
        assert(sequence.GetCodingSequence() == comp_ctor_sequence);
        assert(sequence.GetMatrixSequence() == comp_matrix_sequence);
        assert(sequence.GetRNKSequence() == comp_rnk_sequence);
    }
    catch (...)
    {
        cout << " FAILED"s << endl;
    }
    cout << " PASSED"s << endl;
}

void ExecuteTests()
{
    CTOR_FromStream();
    CTOR_FromString();
    TEST_Sequences();
}

int main()
{
    ExecuteTests();
    cout << "DNA:" << endl;
    Sequence seq(std::cin);
    cout << "MATRIX :"s << std::endl;
    cout << seq.GetMatrixSequence() << endl;
    cout << "RNA :"s << std::endl;
    cout << seq.GetRNKSequence() << endl;
}
