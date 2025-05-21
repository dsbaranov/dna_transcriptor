#include <cassert>
#include <iostream>
#include <string>
#include "codone.h"
#include "domain.h"

using namespace std;

template <typename Lambda>
void Test(const std::string& name, Lambda& function) {
  cout << "TEST "s << name << " ";
  function();
  cout << "SUCCESS" << endl;
}

void Codone_CTOR_Nucleotids() {
  Codone::codone ideal_codone{Nucleotide::Adenine, Nucleotide::Cytosine,
                              Nucleotide::Guanine};
  Codone test_codone(Nucleotide::Adenine, Nucleotide::Cytosine,
                     Nucleotide::Guanine);
  assert(test_codone.Get() == ideal_codone);
}

void Codone_CTOR_String() {
  Codone::codone ideal_codone{Nucleotide::Adenine, Nucleotide::Guanine,
                              Nucleotide::Thymine};
  Codone test_codone("AGT"s);
  assert(test_codone.Get() == ideal_codone);
}

void Codone_CTOR_String_FALSE() {
  bool false_result_size = false;
  {
    try {
      Codone test_codone("AGTC");
    } catch (...) {
      false_result_size = true;
    }
  }
  bool false_result_signature = false;
  {
    try {
      Codone test_codone("ABC");
    } catch (...) {
      false_result_signature = true;
    }
  }
  assert(false_result_size && false_result_signature);
}

void CodoneTests() {
  Test("Codone_CTOR_Nucleoids", Codone_CTOR_Nucleotids);
  Test("Codone_CTOR_String", Codone_CTOR_String);
  Test("Codone_CTOR_String_FALSE", Codone_CTOR_String_FALSE);
}

int main() {
  CodoneTests();
}
