#include "Logger.h"
#include <iostream>

int main() {
    Logger* logger = Logger::getInstance();
    Logger* logger2 = Logger::getInstance();
    std::string choice;
    int wybor;
    do {
        std::cout << "1. Dodaj 2. Wypisz 9. Test zawartosci logera 3. Exit\nWybierz: ";
        std::cin >> choice;
        try {
            wybor=stoi(choice);
        }catch (...) {
            // std::cout << "Błędny wybór, nie r\n";
            wybor=-1;
        }
        if (wybor == 1) {
            std::string type, message;
            std::cout << "Typ (1.Info 2.Warning 3.Error): ";
            std::cin >> type;
            std::cin.ignore(); // Ignore newline character
            std::cout << "Enter message: ";
            std::getline(std::cin, message);
            
            try {
                logger->addMessage(stoi(type), message);
            }
            catch (...) {
                std::cout << "Błędny poziom logu\n";
            }
        } else if (wybor == 2) {
            logger->printLogs();
        } else if (wybor == 9) {
            std::cout << "Print logger 2!\n";
            logger2->printLogs();
        } else if (wybor != 3) {
             std::cout << "Nie rozumiem"<<std::endl;
        }
    } while (wybor != 3);

    return 0;
}
