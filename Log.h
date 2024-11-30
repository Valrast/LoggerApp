#ifndef LOG_H
#define LOG_H

#include <string>
//Klasa bazowa
class Log {
public:
    virtual ~Log() = default;
    virtual std::string getMessage() const = 0;
};

//Implementacje klasa info
class InfoLog : public Log {
    std::string message;
public:
    explicit InfoLog(const std::string& msg) : message("INFO: " + msg) {}
    std::string getMessage() const override { return message; }
};

//Implementacje klasa warning
class WarningLog : public Log {
    std::string message;
public:
    explicit WarningLog(const std::string& msg) : message("WARNING: " + msg) {}
    std::string getMessage() const override { return message; }
};


//Implementacje klasa error
class ErrorLog : public Log {
    std::string message;
public:
    explicit ErrorLog(const std::string& msg) : message("ERROR: " + msg) {}
    std::string getMessage() const override { return message; }
};

#endif // LOG_H
