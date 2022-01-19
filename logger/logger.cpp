#include "logger.hpp"
#include <iostream>

LOG::Logger *LOG::Logger::singleLog = nullptr;

LOG::Logger::Logger()
{
    log_file.open(log_file_dest, std::fstream::trunc);
    addTrace("Start log");
}

LOG::Logger *LOG::Logger::getInstance()
{
    if (singleLog == nullptr)
        singleLog = new Logger();
    return singleLog;
}

LOG::Logger::~Logger()
{
    addTrace("End log!");
    log_file.close();
}

void LOG::Logger::addTrace(std::string trace)
{
    // add lock on mutex to prevent too much traceing add
    std::lock_guard<std::mutex> guard(mutex_controler);
    if (log_file.is_open())
        log_file << trace << std::endl;
    else
        std::cerr << "Log file is not open!";
}