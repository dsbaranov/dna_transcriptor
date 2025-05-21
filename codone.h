#include <array>
#include <string>
#include "domain.h"
#include "validation.h"

class Codone {
 public:
  using codone = std::array<Nucleotide, 3>;

  Codone() = delete;
  explicit Codone(Nucleotide first, Nucleotide second, Nucleotide third)
      : codone_{first, second, third} {}
  explicit Codone(const std::string& sequence) {
    if (!validation::IsValidCodoneString(sequence)) {
      throw std::logic_error(
          "Некорректные обозначения нуклеотидов (A, T, G, C) или размер "
          "строчного обозначения кодона (3)");
    }
    for (int i = 0; i < 3; ++i) {
      codone_[i] = CharToNucleotide(sequence.at(i));
    }
  }

  Nucleotide& operator[](size_t index) { return codone_[index]; }
  const Nucleotide& operator[](size_t index) const { return codone_.at(index); }

  codone AsMatrix() {}

  void ToMatrix() {}

  codone Get() const { return codone_; }

 private:
  codone codone_;
};