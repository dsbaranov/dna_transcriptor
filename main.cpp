#include "./tests/codone.h"
#include "./tests/nucleotide.h"
#include "./tests/sequence.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    test::nucleotide::UNIT_TEST_Nucleotide();
    test::codone::UNIT_TEST_Codone();
    test::sequence::UNIT_TEST_Sequence();

    {
        cout << "main"s << endl;
        {
            stringstream ss(test::details::GenerateRandomStringSequece(999u));
            Sequence seq(ss);
            seq.ToMatrix().ToRNA();
            {
                LOG_DURATION("DESCRIPTION");
                seq.SerializeRNAWithDesctiption(std::cout, false, 10u);
            }
        }
    }
    return 0;
}
