// ui/GameScreen.cpp
#include "GameScreen.h"
#include "../Board.h"
#include "Screen.h"
#include <iostream>
#include <cctype>

#ifdef _WIN32
#include <windows.h>
void printColoredChar(char c, bool isRed) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(hConsole, &info);
    WORD originalAttr = info.wAttributes;

    if (isRed) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    }

    std::cout << " " << c;

    if (isRed) {
        SetConsoleTextAttribute(hConsole, originalAttr);
    }

    std::cout << " |";
}
#else
#define RED_COLOR "\033[31m"
#define RESET_COLOR "\033[0m"
void printColoredChar(char c, bool isRed) {
    if (isRed) std::cout << " " << RED_COLOR << c << RESET_COLOR << " |";
    else       std::cout << " " << c << " |";
}
#endif

namespace ui {

    void renderBoard(const Board& board) {
        clearConsole();

        printLine();
        printCentered("Royal Board");
        printLine();

        std::cout << "\n  [0] 메인 화면으로 돌아가기\n";
        std::cout << "  [1] 룰 설명 화면으로 가기\n";
        std::cout << "  [2] 게임 종료하기\n\n";

        std::cout << "    a   b   c   d   e   f   g   h\n";
        std::cout << "  +---+---+---+---+---+---+---+---+\n";

        for (int row = 0; row < 8; ++row) {
            std::cout << 8 - row << " |";
            for (int col = 0; col < 8; ++col) {
                char symbol = board.getSymbolAt(row, col);
                printColoredChar(symbol, std::islower(symbol));
            }
            std::cout << " " << 8 - row << "\n";
            std::cout << "  +---+---+---+---+---+---+---+---+\n";
        }

        std::cout << "    a   b   c   d   e   f   g   h\n\n";
    }

}
