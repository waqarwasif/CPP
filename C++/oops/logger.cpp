#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <typeinfo>

enum class LogLevel
{
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

// =====================================================================
// 1. THE BACKEND: Singleton Log Manager (Stripped for single-thread)
// =====================================================================
class LogManager
{
private:
    std::ofstream logFile;

    LogManager()
    {
        logFile.open("application.log", std::ios::app);
    }
    ~LogManager()
    {
        if (logFile.is_open())
            logFile.close();
    }

public:
    LogManager(const LogManager &) = delete;
    LogManager &operator=(const LogManager &) = delete;

    static LogManager &getInstance()
    {
        static LogManager instance;
        return instance;
    }

    void writeLog(const std::string &formattedMessage)
    {
        if (logFile.is_open())
        {
            logFile << formattedMessage << "\n";
            logFile.flush();
        }
        std::cout << formattedMessage << std::endl;
    }
};

// =====================================================================
// 2. THE FRONTEND: The CRTP Mixin (Stripped for single-thread)
// =====================================================================
template <typename Derived>
class LoggerMixin
{
private:
    std::string getCurrentTime() const
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
        return ss.str();
    }

    std::string levelToString(LogLevel level) const
    {
        switch (level)
        {
        case LogLevel::DEBUG:
            return "[DEBUG]";
        case LogLevel::INFO:
            return "[INFO] ";
        case LogLevel::WARNING:
            return "[WARN] ";
        case LogLevel::ERROR:
            return "[ERROR]";
        default:
            return "[LOG]  ";
        }
    }

protected:
    void log(LogLevel level, const std::string &message) const
    {
        std::string className = typeid(Derived).name();
        if (className.length() > 2 && isdigit(className[0]))
        {
            className.erase(0, 1);
        }

        std::stringstream ss;
        ss << "[" << getCurrentTime() << "] "
           << levelToString(level)
           << " [" << className << "] -> "
           << message;

        LogManager::getInstance().writeLog(ss.str());
    }
};

// =====================================================================
// 3. USAGE
// =====================================================================
class DatabaseConnection : public LoggerMixin<DatabaseConnection>
{
public:
    void connect()
    {
        log(LogLevel::INFO, "Attempting to connect to the server...");
        log(LogLevel::ERROR, "Connection timed out. Server unreachable.");
    }
};

int main()
{
    DatabaseConnection db;
    db.connect();
    return 0;
}