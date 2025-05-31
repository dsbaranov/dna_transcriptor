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

  private:
    std::vector<Codone> sequence_;
};
