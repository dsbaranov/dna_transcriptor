#pragma once
#include "codone.h"
#include <istream>
#include <string>
#include <vector>
class Sequence
{
  public:
    Sequence() = delete;

    Sequence(const std::string &str_sequence)
    {
    }
    Sequence(std::iostream &is)
    {
    }

    Sequence(const Sequence &other)
    {
    }

    Sequence(std::vector<Nucleotide::Type> &&type_sequence)
    {
    }

    Sequence &operator=(const Sequence &other)
    {
        return *this;
    }

    Sequence(Sequence &&other)
    {
    }

    Sequence &operator=(Sequence &&other)
    {
        return *this;
    }

    const Codone &at(size_t index) const
    {
        if (index >= sequence_.size())
        {
            throw std::out_of_range("index out of Sequence bounds");
        }
        return sequence_.at(index);
    }

    Codone &operator[](size_t index)
    {
        if (index >= sequence_.size())
        {
            throw std::out_of_range("index out of Sequnece bounds");
        }
        return sequence_[index];
    }
    const Codone &operator[](size_t index) const
    {
        if (index >= sequence_.size())
        {
            throw std::out_of_range("index out of Sequnece bounds");
        }
        return sequence_[index];
    }

  private:
    std::vector<Codone> sequence_;
};
