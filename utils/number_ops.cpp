#include "number_ops.hpp"

std::string STOPER::UTILS::time_to_show(const int & tt)
{
    auto time_duration = std::chrono::duration<int>(tt);
    std::string ret {""};
    ret += std::to_string(std::chrono::duration_cast<std::chrono::hours>(time_duration).count());
    ret +="h:";
    ret += std::to_string(std::chrono::duration_cast<std::chrono::hours>(time_duration).count());
    ret +="m:";
    ret += std::to_string(std::chrono::duration_cast<std::chrono::hours>(time_duration).count());
    ret +="s";
    return ret;
}