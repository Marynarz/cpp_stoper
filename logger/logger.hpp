#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <fstream>
#include <string>

namespace LOG
{
    // singleton class for logging activities
    class Logger
    {
        std::ofstream *log_file;
        static Logger *singleLog;
        Logger();

    public:
        // remove copy-constructor and move-constructor
        Logger(Logger &log) = delete;
        Logger(Logger &&log) = delete;

        // remove assign-operator and move-operator
        void operator=(const Logger &log) = delete;
        void operator=(const Logger &&log) = delete;

        static Logger *getInstance();
        ~Logger();
        void addTrace(std::string trace);
    };
};

#endif