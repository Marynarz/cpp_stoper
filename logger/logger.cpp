#include "logger.hpp"
#include <iostream>

LOG::Logger *LOG::Logger::singleLog = nullptr;

LOG::Logger::Logger()
{
    log_file.open(QFile::WriteOnly | QFile::Truncate);
    out = new QTextStream(&log_file);
    if(log_file.isOpen())
        (*out) << "Hej!";
    else
        std::cout <<"Error";
    std::cout <<"Dupa!";
}

LOG::Logger &LOG::Logger::getInstance()
{
    if (singleLog == nullptr)
        singleLog = new Logger();
    return *singleLog;
}

LOG::Logger::~Logger()
{
    log_file.flush();
    log_file.close();
}

void LOG::Logger::addTrace(QString trace)
{
    (*out) << trace;
}