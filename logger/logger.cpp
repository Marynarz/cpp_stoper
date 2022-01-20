#include "logger.hpp"
#include <iostream>

LOG::Logger *LOG::Logger::single_log = nullptr;
std::mutex LOG::Logger::mutex_controler;

LOG::Logger::Logger()
{
    log_file.open(log_file_dest, std::fstream::trunc);
    addTrace("Start log");
}

LOG::Logger *LOG::Logger::getInstance()
{
    // add lock on mutex to prevent too much traceing add
    std::lock_guard<std::mutex> guard(mutex_controler);
    if (single_log == nullptr)
        single_log = new Logger();
    return single_log;
}

LOG::Logger::~Logger()
{
    addTrace("End log!");
    log_file.close();
}

void LOG::Logger::addTrace(std::string trace)
{
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    if (log_file.is_open())
        log_file << now << ": " << trace << std::endl;
    else
        std::cerr << "Log file is not open!";
}