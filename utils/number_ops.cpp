#include "number_ops.hpp"

std::string STOPER::UTILS::time_to_show(const std::chrono::steady_clock::time_point &start, const std::chrono::steady_clock::time_point &end)
{
    std::string ret{""};
    ret += std::to_string(std::chrono::duration_cast<std::chrono::hours>(end - start).count());
    ret += "h:";
    ret += std::to_string(std::chrono::duration_cast<std::chrono::minutes>(end - start).count() % 60);
    ret += "m:";
    ret += std::to_string(std::chrono::duration_cast<std::chrono::seconds>(end - start).count() % 60);
    ret += "s";
    return ret;
}