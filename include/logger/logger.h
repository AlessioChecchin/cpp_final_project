/**
 * Logger class.
 * 
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
 * Logger is a singleton.
 */
class logger
{

public:
    /**
     * Getter for logger instance.
     * @return The instance of the singleton.
     */
    static logger& get_logger();

    /**
     * Destructor. It's necessary to close file 
     */
    ~ logger();

private:

    /**
     * Default constructor
     */
    logger();

    /**
     * Copy disabled.
     */
    logger(const logger& l) = delete;

    /**
     * Copy disabled.
     */
    logger& operator=(const logger& l) = delete;
    
    /**
     * operator<< sends logs to the logger.
     */
    template <typename T>
    friend logger& operator<<(logger& log, const T& obj);
    
    /**
     * Saves the log message in the log file.
     */
    void save_log();

	/**
	 * File stream.
	*/
    std::ofstream file_;
};
    
/**
 * Second operator<< overload. Necessary to allow std::endl concatenation 
 * E.g: log << "test" << std::endl
 * @param log Logger to use
 * @param f std::endl
 * @return logger& 
 */
logger& operator<<(logger& log, std::ostream& (*f)(std::ostream&));

} // prj

// Template implementation.
#include "logger/logger.hpp"

#endif // LOGGER_H