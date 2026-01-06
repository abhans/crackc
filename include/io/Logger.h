#ifndef AVI_IO_LOGGER_H
#define AVI_IO_LOGGER_H

#include <fstream>
#include <string>

namespace avi::io {

    enum Level { DEBUG, INFO, WARNING, ERROR, CRITICAL };

    class Logger {
    public:
        explicit Logger(const std::string& filename);
        ~Logger();

        // Log a message with the given level
        void log(Level level, const std::string& message);

    private:
        std::ofstream logFile;

        std::string levelToString(Level level);
    };
}

#endif  // AVI_IO_LOGGER_H