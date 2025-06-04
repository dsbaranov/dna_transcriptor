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

  {
    cout << "main"s << endl;
    {
      stringstream ss(test::details::GenerateRandomStringSequece(999u));
      Sequence seq(ss);
      {
        LOG_DURATION("Base");
        cout << "Base:   "s << seq.ToMatrix() << endl;
      }
      {
        LOG_DURATION("ToMatrix");
        cout << "Matrix: "s << seq.ToMatrix() << endl;
      }
      {
        LOG_DURATION("ToRNA");
        cout << "RNA:    "s << seq.ToRNA() << endl;
      }
    }
  }
  return 0;
}
