#pragma once
#include "codone.h"
#include "codone_describer.h"
#include "log_duration.h"
#include <istream>
#include <string>
#include <vector>
class Sequence
{
  public:
    using Iterator = Codone *;
    using ConstIterator = const Codone *;

    Sequence() = delete;

    Sequence(std::string &&str_sequence) : sequence_(FromString(std::forward<std::string>(str_sequence)))
    {
    }
    Sequence(std::istream &is) : sequence_(FromStream(is))
    {
    }

    Sequence(const Sequence &other) : sequence_(other.sequence_.begin(), other.sequence_.end())
    {
    }
    Sequence &operator=([[maybe_unused]] const Sequence &other)
    {
        sequence_ = other.sequence_;
        return *this;
    }
    Sequence(Sequence &&other) : sequence_(std::move(other.sequence_))
    {
    }

    Sequence &operator=(Sequence &&other)
    {
        sequence_ = std::move(other.sequence_);
        return *this;
    }

    Sequence &ToMatrix()
    {
        std::for_each(sequence_.begin(), sequence_.end(), [](Codone &codone) { codone.ToMatrix(); });
        return *this;
    }

    Sequence &ToRNA()
    {
        std::for_each(sequence_.begin(), sequence_.end(), [](Codone &codone) { codone.ToRNA(); });
        return *this;
    }

    void SerializeRNAWithDesctiption([[maybe_unused]] std::ostream &os, [[maybe_unused]] bool eng = true,
                                     [[maybe_unused]] size_t codones_per_row = 10) const
    {
        std::stringstream ss_codone;
        std::stringstream ss_description;
        for (auto codone_it = sequence_.begin(); codone_it != sequence_.end(); codone_it++)
        {
            ss_codone << *codone_it << " "s;
            ss_description << (eng ? CodoneDescriber::DescribeAsEnString(*codone_it)
                                   : CodoneDescriber::DescribeAsRuString(*codone_it))
                           << " "s;

            if (static_cast<size_t>(std::distance(sequence_.begin(), next(codone_it))) % codones_per_row == 0)
            {
                os << ss_codone.str() << std::endl;
                os << ss_description.str() << std::endl;
                ss_codone.str("");
                ss_description.str("");
            }
        }
        os << std::endl;
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
    size_t size() const
    {
        return sequence_.size();
    }
    auto begin() const
    {
        return sequence_.begin();
    }
    auto end() const
    {
        return sequence_.end();
    }

  private:
    std::vector<Codone> sequence_;

    void RemoveSpaces(std::string &str)
    {
        str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    }

    std::vector<Codone> FromString(std::string &&str_sequence)
    {
        assert(!str_sequence.empty());
        std::vector<Codone> result;
        RemoveSpaces(str_sequence);
        assert(str_sequence.size() % 3 == 0);
        result.reserve(str_sequence.size() / 3);
        for (size_t index(0); index < str_sequence.size(); index++)
        {
            if ((index + 1) % 3 == 0)
            {
                result.push_back({{str_sequence[index - 2]}, {str_sequence[index - 1]}, {str_sequence[index]}});
            }
        }
        return result;
    }

    std::vector<Codone> FromStream(std::istream &is)
    {
        std::string line;
        getline(is, line);
        return FromString(std::move(line));
    }

    std::vector<Codone> FromType(std::vector<Nucleotide::Type> &&type_sequence)
    {
        assert(type_sequence.size() % 3 == 0);
        std::vector<Codone> result;
        result.reserve(type_sequence.size() / 3);
    }
};

std::ostream &operator<<(std::ostream &os, const Sequence &sequence)
{
    for (const Codone &codone : sequence)
    {
        os << codone << " ";
    }
    return os;
}
