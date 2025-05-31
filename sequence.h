#pragma once
#include "codone.h"
#include <istream>
#include <string>
#include <vector>
class Sequence
{
  public:
    Sequence() = delete;

    Sequence([[maybe_unused]] const std::string &str_sequence)
    {
    }
    Sequence([[maybe_unused]] std::iostream &is)
    {
    }

    Sequence([[maybe_unused]] const Sequence &other)
    {
    }

    Sequence([[maybe_unused]] std::vector<Nucleotide::Type> &&type_sequence)
    {
    }

    Sequence &operator=([[maybe_unused]] const Sequence &other)
    {
        return *this;
    }

    Sequence([[maybe_unused]] Sequence &&other)
    {
    }

    Sequence &operator=([[maybe_unused]] Sequence &&other)
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

    bool empty() const
    {
        return sequence_.empty();
    }

  private:
    std::vector<Codone> FromString(std::string &&str_sequence)
    {
    }

    std::vector<Codone> FromStream()
    {
    }

    std::vector<Codone> sequence_;
};
