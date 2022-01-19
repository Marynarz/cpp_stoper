#include "logger.hpp"
#include <iostream>

LOG::Logger *LOG::Logger::singleLog = nullptr;

LOG::Logger::Logger()
{
    log_file.open(log_file_dest, std::fstream::trunc);
    if (log_file.is_open())
        log_file << "Hej!" <<std::endl;
    else
        std::cout << "Error" <<std::endl;

}

LOG::Logger *LOG::Logger::getInstance()
{
    if (singleLog == nullptr)
        singleLog = new Logger();
    return singleLog;
}

LOG::Logger::~Logger()
{
    log_file.close();
}

void LOG::Logger::addTrace(std::string trace)
{
    log_file << trace <<std::endl;
}