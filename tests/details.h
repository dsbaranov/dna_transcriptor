#pragma once

#include <string>
using namespace std::string_literals;

namespace test::details
{
template <typename Lambda> void TestLambda(const std::string &name, Lambda *lambda)
{
    std::cout << "\tTEST "s << name;
    try
    {
        lambda();
    }
    catch (...)
    {
        std::cout << " FAILED" << std::endl;
    }
    std::cout << " SUCCESS" << std::endl;
}
} // namespace test::details
