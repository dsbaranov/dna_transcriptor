#pragma once
#include "domain.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std::string_literals;

class Sequence
{
  public:
    using BaseSequence = std::vector<NBase>;

    Sequence() = default;

    explicit Sequence(std::istream &is)
    {
        FromStream(is);
    }

    explicit Sequence(const std::string &line)
    {
        FromString(line);
    }

    const BaseSequence &GetCodingSequence() const
    {
        return coding_sequence_;
    }

    BaseSequence GetMatrixSequence() const
    {
        BaseSequence matrix;
        matrix.reserve(coding_sequence_.size());
        for (const NBase &base : coding_sequence_)
        {
            matrix.push_back(CodingToMatrix(base));
        }
        return matrix;
    }

    BaseSequence GetRNKSequence() const
    {
        BaseSequence rnk;
        rnk.reserve(coding_sequence_.size());
        for (const NBase &base : GetMatrixSequence())
        {
            rnk.push_back(MatrixBaseToRBase(base));
        }
        return rnk;
    }

  private:
    void FromString(const std::string line)
    {
        if (!coding_sequence_.empty())
        {
            coding_sequence_.clear();
        }
        coding_sequence_.reserve(line.size());
        for (char c : line)
        {
            if (c == ' ')
            {
                continue;
            }
            coding_sequence_.push_back(CharToNBase(c));
        }
    }
    void FromStream(std::istream &is)
    {
        std::string line;
        std::getline(is, line);
        FromString(line);
    }

    BaseSequence coding_sequence_;
};

std::ostream &operator<<(std::ostream &os, const Sequence::BaseSequence &sequence)
{
    size_t counter = 0;
    for (const NBase &base : sequence)
    {
        if (counter >= 3)
        {
            counter = 0;
            os << " "s;
        }
        os << base;
        counter++;
    }
    return os;
}