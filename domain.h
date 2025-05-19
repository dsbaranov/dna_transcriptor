#pragma once

#include <iostream>
#include <stdexcept>

enum class NBase
{
    A,
    C,
    G,
    T,
    U
};

NBase CharToNBase(char ch)
{
    switch (ch)
    {
    case 'A':
        return NBase::A;
        break;
    case 'C':
        return NBase::C;
        break;
    case 'G':
        return NBase::G;
        break;
    case 'T':
        return NBase::T;
        break;
    case 'U':
        return NBase::U;
    default:
        throw std::out_of_range("char is not in the list of appropriate N bases");
    }
}

NBase CodingToMatrix(NBase coding_nbase)
{
    switch (coding_nbase)
    {
    case NBase::A:
        return NBase::T;
        break;
    case NBase::C:
        return NBase::G;
        break;
    case NBase::G:
        return NBase::C;
        break;
    case NBase::T:
        return NBase::A;
        break;
    default:
        throw std::logic_error("invalid base to convert from coding to matrix sequence");
    }
}

NBase MatrixBaseToRBase(NBase matrix_base)
{
    switch (matrix_base)
    {
    case NBase::A:
        return NBase::U;
        break;
    case NBase::C:
        return NBase::G;
        break;
    case NBase::G:
        return NBase::C;
        break;
    case NBase::T:
        return NBase::A;
        break;
    default:
        throw std::logic_error("invalid base to convert from matrix to rnk sequence");
    }
}

std::ostream &operator<<(std::ostream &os, NBase nbase)
{
    switch (nbase)
    {
    case NBase::A:
        os << 'A';
        break;
    case NBase::C:
        os << 'C';
        break;
    case NBase::G:
        os << 'G';
        break;
    case NBase::T:
        os << 'T';
        break;
    case NBase::U:
        os << 'U';
        break;
    }
    return os;
}
