#include <cassert>
#include <iostream>
#include <string>
#include "./tests/codone.h"
#include "./tests/nucleotide.h"
#include "./tests/sequence.h"
using namespace std;

int main() {
  test::nucleotide::UNIT_TEST_Nucleotide();
  test::codone::UNIT_TEST_Codone();
  test::sequence::UNIT_TEST_Sequence();
}
