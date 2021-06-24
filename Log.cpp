#include "Log.h"

Log::Log(std::string name, LogLevel logLevel)
    : m_name(name), m_logLevel(logLevel)
{
    initLog();
}

void Log::initLog(){
    Logger myroot = Logger::getInstance(LOG4CPLUS_TEXT("myroot"));
    SharedAppenderPtr console = myroot.getAppender(LOG4CPLUS_TEXT("STDOUT"));
    SharedAppenderPtr rollingfile = myroot.getAppender(LOG4CPLUS_TEXT("ROLLINGFILE"));
    SharedAppenderPtr dailyrolling = myroot.getAppender(LOG4CPLUS_TEXT("DAILYROLLING"));

    //create log for m_name
    logger = Logger::getInstance(m_name);
    switch(m_logLevel){
    case LogLevel::TRACE :
        logger.setLogLevel(log4cplus::TRACE_LOG_LEVEL);
        break;

    case LogLevel::DEBUG :
        logger.setLogLevel(log4cplus::DEBUG_LOG_LEVEL);
        break;

    case LogLevel::INFO :
        logger.setLogLevel(log4cplus::INFO_LOG_LEVEL);
        break;

    case LogLevel::WARN :
        logger.setLogLevel((log4cplus::WARN_LOG_LEVEL));
        break;

    case LogLevel::ERROR :
        logger.setLogLevel(log4cplus::ERROR_LOG_LEVEL);
        break;

    case LogLevel::FATAL :
        logger.setLogLevel(log4cplus::FATAL_LOG_LEVEL);
        break;

    }

    logger.addAppender(console);
    logger.addAppender(rollingfile);
    logger.addAppender(dailyrolling);
}

//Logger Log::getLogger() {

//    return logger;
//}

