#include "io/Logger.h"

#include <ctime>
#include <iostream>
#include <sstream>
#include <cstdio>

namespace avi::io {

    Logger::Logger(const std::string& filename)
    {
        logFile.open(filename, std::ios::app);

        if (!logFile.is_open()) {
            std::cerr << "Error opening the log file." << std::endl;
        }
    }

    Logger::~Logger()
    {
        if (logFile.is_open()) {
            logFile.close();
            return;
        }
    }

    void Logger::log(Level level, const std::string& message)
    {
        time_t now = time(0);
        tm* timeinfo = localtime(&now);

        char timestamp[64];
        size_t _timestampLength = strftime(timestamp, sizeof(timestamp),
                "%d.%m.%Y @ %H:%M:%S", timeinfo);

        std::ostringstream logEntry;
        logEntry << "[" << timestamp << "] "
                << levelToString(level) << " | "
                << message << std::endl;

        std::cout << logEntry.str();

        if (logFile.is_open()) {
            logFile << logEntry.str();
            logFile.flush();
        }
    };

    std::string Logger::levelToString(Level level)
    {
        switch (level)
        {
            case DEBUG:    return "DEBUG";
            case INFO:     return "INFO";
            case WARNING:  return "WARNING";
            case ERROR:    return "ERROR";
            case CRITICAL: return "CRITICAL";
            default:       return "UNKNOWN";
        }
    };
}