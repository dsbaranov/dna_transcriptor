#include "./tests/codone.h"
#include "./tests/nucleotide.h"
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    test::nucleotide::UNIT_TEST_Nucleotide();
    test::codone::UNIT_TEST_Codone();
}
