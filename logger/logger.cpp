#include "logger.hpp"
#include <iostream>

LOG::Logger *LOG::Logger::singleLog = nullptr;

LOG::Logger::Logger()
{
    log_file = new std::ofstream("log.txt");
    if (log_file->is_open())
        (*log_file) << "Hej!";
    else
        std::cout << "Error";
}

LOG::Logger *LOG::Logger::getInstance()
{
    if (singleLog == nullptr)
        singleLog = new Logger();
    return singleLog;
}

LOG::Logger::~Logger()
{
    log_file->flush();
    log_file->close();
}

void LOG::Logger::addTrace(std::string trace)
{
    (*log_file) << trace;
}