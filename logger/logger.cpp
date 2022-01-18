#include "logger.hpp"

LOG::Logger * LOG::Logger::singleLog = nullptr;

LOG::Logger::Logger()
{
    log_file = new std::ofstream(log_file_dest);

    if (!log_file->is_open())
        log_file->open(log_file_dest);

    (*log_file) << "Hello!";
}

LOG::Logger &LOG::Logger::getInstance()
{
    if (singleLog == nullptr)
        singleLog = new Logger();
    return *singleLog;
}

LOG::Logger::~Logger()
{
}

void LOG::Logger::addTrace(std::string trace)
{
    (*log_file) << trace;
}