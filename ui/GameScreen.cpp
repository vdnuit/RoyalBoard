// ui/GameScreen.cpp
#include "GameScreen.h"
#include "../Board.h"
#include <iostream>

namespace ui {

    void renderBoard(const Board& board) {
        std::cout << "\n    a   b   c   d   e   f   g   h\n";
        std::cout << "  +---+---+---+---+---+---+---+---+\n";

        for (int row = 0; row < 8; ++row) {
            std::cout << 8 - row << " |";
            for (int col = 0; col < 8; ++col) {
                char symbol = board.getSymbolAt(row, col);  // 기물 없으면 ' '
                std::cout << " " << symbol << " |";
            }
            std::cout << " " << 8 - row << "\n";
            std::cout << "  +---+---+---+---+---+---+---+---+\n";
        }

        std::cout << "    a   b   c   d   e   f   g   h\n\n";
    }

}
