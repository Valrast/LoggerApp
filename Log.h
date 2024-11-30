#ifndef LOG_H
#define LOG_H

#include <string>

class Log {
public:
    virtual ~Log() = default;
    virtual std::string getMessage() const = 0;
};

class InfoLog : public Log {
    std::string message;
public:
    explicit InfoLog(const std::string& msg) : message("INFO: " + msg) {}
    std::string getMessage() const override { return message; }
};

class WarningLog : public Log {
    std::string message;
public:
    explicit WarningLog(const std::string& msg) : message("WARNING: " + msg) {}
    std::string getMessage() const override { return message; }
};

class ErrorLog : public Log {
    std::string message;
public:
    explicit ErrorLog(const std::string& msg) : message("ERROR: " + msg) {}
    std::string getMessage() const override { return message; }
};

#endif // LOG_H
