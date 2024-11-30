#ifndef LOGFACTORY_H
#define LOGFACTORY_H

#include "Log.h"
#include <memory>
#include <stdexcept>

//Klasa  fabryki tworzaca obiekty
class LogFactory {
public:
    static std::unique_ptr<Log> createLog(const int& type, const std::string& message) {
        if (type == 1) return std::make_unique<InfoLog>(message);
        if (type == 2) return std::make_unique<WarningLog>(message);
        if (type == 3) return std::make_unique<ErrorLog>(message);
        throw std::invalid_argument("Unknown log type");
    }
};

#endif // LOGFACTORY_H



