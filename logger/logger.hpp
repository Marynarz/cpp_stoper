#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <fstream>

namespace LOG
{
    // singleton class for logging activities
    class Logger
    {
        const std::string log_file_dest = "log.txt";
        std::ofstream *log_file = nullptr;

    protected:
        static Logger *singleLog;
        Logger();

    public:
        // remove copy-constructor and move-constructor
        Logger(Logger &log) = delete;
        Logger(Logger &&log) = delete;

        // remove assign-operator and move-operator
        void operator=(const Logger &log) = delete;
        void operator=(const Logger &&log) = delete;

        static Logger &getInstance();
        ~Logger();
        void addTrace(std::string trace);
    };
};

#endif