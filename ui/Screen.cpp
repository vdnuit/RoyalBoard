// ui/Screen.cpp

#include "Screen.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <locale>
#include <codecvt>
#include <cwchar>

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

    int getDisplayWidth(const std::string& text) {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        std::wstring wstr = converter.from_bytes(text);
        int width = 0;

        for (wchar_t wc : wstr) {
            if (wc >= 0xAC00 && wc <= 0xD7A3) width += 2; // 한글
            else if (std::iswalpha(wc)) width += 1;
            else if (std::iswspace(wc)) width += 1;
            else width += 1;
        }

        return width;
    }

    void printCentered(const std::string& text, int width) {
        int displayWidth = getDisplayWidth(text);
        int padding = (width - displayWidth) / 2;
        std::cout << "  |" << std::string(padding, ' ')
                  << text << std::string(width - padding - displayWidth, ' ') << "|\n";
    }

    void printPrompt(const std::string& prompt) {
        std::cout << "\n" << prompt;
    }

} // namespace ui
