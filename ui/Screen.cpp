// ui/Screen.cpp
#include "Screen.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>


namespace ui {
    void clearConsole() {
        #ifdef _WIN32
            std::system("cls");
        #else
            std::system("clear");
        #endif
    }
    void printLine(int width, char fill) {
        std::cout << "  +" << std::string(width, fill) << "+\n";
    }

    void printTitle(const std::string& title, int width) {
        printLine(width, '=');
        printCentered(title, width);
        printLine(width, '=');
        std::cout << '\n';
    }

    void printCentered(const std::string& text, int width) {
        int padding = (width - static_cast<int>(text.length())) / 2;
        std::cout << "  |" << std::string(padding, ' ')
                  << text << std::string(width - padding - text.length(), ' ') << "|\n";
    }

    void printPrompt(const std::string& prompt) {
        std::cout << "\n" << prompt;
    }

} // namespace ui
