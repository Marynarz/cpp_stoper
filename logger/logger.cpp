#include "logger.hpp"
#include <iostream>

LOG::Logger *LOG::Logger::singleLog = nullptr;

LOG::Logger::Logger()
{
    log_file = new std::ofstream("log.txt", std::fstream::out);
    if (log_file->is_open())
        (*log_file) << "Hej!";
    else
        std::cout << "Error";

    std::cout <<log_file->fail() <<std::endl;
}

LOG::Logger *LOG::Logger::getInstance()
{
    if (singleLog == nullptr)
        singleLog = new Logger();
    return singleLog;
}

LOG::Logger::~Logger()
{
    log_file->close();
}

void LOG::Logger::addTrace(std::string trace)
{
    (*log_file) << trace;
}