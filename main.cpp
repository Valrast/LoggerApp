#include "Logger.h"
#include <iostream>

int main() {
    Logger* logger = Logger::getInstance();

    int choice;
    do {
        std::cout << "1. Add log\n2. Show logs\n3. Exit\nChoose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string type, message;
            std::cout << "Enter log type (1.Info 2.Warning 3.Error): ";
            std::cin >> type;
            std::cin.ignore(); // Ignore newline character
            std::cout << "Enter message: ";
            std::getline(std::cin, message);

            logger->logMessage(stoi(type), message);
        } else if (choice == 2) {
            logger->showLogs();
        } else if (choice != 3) {
             std::cout << "Nie rozumiem"<<std::endl;
        }
    } while (choice != 3);

    return 0;
}
