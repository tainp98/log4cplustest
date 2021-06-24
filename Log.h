#ifndef LOG_H
#define LOG_H

#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <consoleappender.h>
#include <fileappender.h>
#include <tstring.h>
#include <iostream>

using namespace log4cplus;



class Log
{
public:
    enum class LogLevel{
        TRACE = 0,
        DEBUG = 1,
        INFO = 2,
        WARN = 3,
        ERROR = 4,
        FATAL = 5
    };
public:
    Log(std::string name, LogLevel logLevel=LogLevel::TRACE);
    Logger getLogger() const {
        return logger;
    }


private:
    void initLog();
    log4cplus::Logger logger;
    std::string m_name;
    LogLevel m_logLevel;
//    log4cplus::tstring pattern;

};
#endif // LOG_H
