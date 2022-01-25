#ifndef __NUMBER_OPS_HPP__
#define __NUMBER_OPS_HPP__

#include <string>
#include <chrono>

namespace STOPER
{
    namespace UTILS
    {
        std::string time_to_show(const std::chrono::steady_clock::time_point &start, const std::chrono::steady_clock::time_point &end);
    };
};

#endif