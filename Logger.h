#ifndef LOGGER_H
#define LOGGER_H

#include "Log.h"
#include "LogFactory.h"
#include <vector>
#include <memory>
#include <iostream>

class Logger {
    //Static poniewaz ma być Singletonem
    static Logger* instance;
    std::vector<std::unique_ptr<Log>> logs;

    Logger() = default;

public:
    static Logger* getInstance() {
        if (!instance) instance = new Logger();
        return instance;
    }

    void addMessage(const int& type, const std::string& message) {
        try {
            logs.push_back(LogFactory::createLog(type, message));
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    void printLogs() const {
        std::cout << "===Przechowywane logi====="<<std::endl;
        for (const auto& log : logs) {
            std::cout << log->getMessage() << "\n";
        }
        std::cout << "===========KONIEC========"<<std::endl<<std::endl;
    }

    // Disallow copying
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

Logger* Logger::instance = nullptr;

#endif // LOGGER_H
