#pragma once
#include "nucleotide.h"
#include <array>
#include <cassert>
#include <memory>

class Codone
{
  public:
    using Triplet = std::array<Nucleotide, 3>;
    Codone() = delete;
    Codone(const Nucleotide &first, const Nucleotide &second, const Nucleotide &third) : triplet_{first, second, third}
    {
    }

    Codone(const std::string &codone_string)
        : triplet_({{codone_string.at(0)}, codone_string.at(1), {codone_string.at(2)}})
    {
        assert(codone_string.size() == 3u);
    }

    Codone &ToMatrix()
    {
        for (Nucleotide &nucleotide : triplet_)
        {
            nucleotide.ToMatrix();
        }
        return *this;
    }

    Codone &ToRNA()
    {
        for (Nucleotide &nucleotide : triplet_)
        {
            nucleotide.ToRNA();
        }
        return *this;
    }

    Nucleotide &operator[](size_t index)
    {
        if (index >= triplet_.size())
        {
            throw std::out_of_range("triplet index out of range");
        }
        return triplet_[index];
    }

    const Nucleotide &operator[](size_t index) const
    {
        if (index >= triplet_.size())
        {
            throw std::out_of_range("triplet index out of range");
        }
        return triplet_.at(index);
    }

    const Nucleotide &at(size_t index) const
    {
        if (index >= triplet_.size())
        {
            throw std::out_of_range("triplet index out of range");
        }
        return triplet_.at(index);
    }

  private:
    Triplet triplet_;
};

std::ostream &operator<<(std::ostream &os, const Codone &codone)
{
    os << codone.at(0) << codone.at(1) << codone.at(2);
    return os;
}