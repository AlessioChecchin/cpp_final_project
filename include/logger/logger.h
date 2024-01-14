/**
 * @author Jacopo Toniolo
 */
#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

#include "config.h"

namespace prj
{


/**
 * Logger is a Singleton
 */
class logger
{

public:
    /**
     * Getter for logger instance
     * @return logger& - Instance of the singleton
     */
    static logger& get_logger();

    /**
     * Destructor - necessary to close file 
     */
    ~ logger();

private:

    std::ofstream file_;

    /**
     * Default constructor
     */
    logger();

    /**
     * Copy disable
     */
    logger(const logger& l) = delete;

    /**
     * Copy disable
     */
    logger& operator=(const logger& l) = delete;
    

    /**
     * operator<< sends logs to the logger
     */
    template <typename T>
    friend logger& operator<<(logger& log, const T& obj);
    
    /**
     * Saves the log message in the log file
     */
    void save_log();

};
    
/**
 * Second operator<< overload. Necessary to allow std::endl concatenation 
 * E.g: log << "test" << std::endl
 * @param log Logger to use
 * @param f std::endl
 * @return logger& 
 */
logger& operator<<(logger& log, std::ostream& (*f)(std::ostream&));

}

#include "logger/logger.hpp"

#endif // LOGGER_H