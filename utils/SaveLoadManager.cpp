#include "SaveLoadManager.h"
#include <fstream>
#include <iostream>

namespace utils {

    bool SaveLoadManager::saveGame(const Board& board, Color currentColor,int turnCount, const std::string& filename) {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "파일을 저장할 수 없습니다.\n";
            return false;
        }

        // 현재 턴 색상 저장
        outFile << static_cast<int>(currentColor) << "\n";
        outFile << static_cast<int>(currentColor) << " " << turnCount << "\n";

        // 보드 상태 저장
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                const Piece* p = board.getPieceAt(Position(row, col));
                if (p) {
                    outFile << row << " " << col << " " << p->getSymbol() << "\n";
                }
            }
        }

        outFile.close();
        return true;
    }

    bool SaveLoadManager::loadGame(Board& board, Color& currentColor, int& turnCount,const std::string& filename) {
        std::ifstream inFile(filename);
        if (!inFile) {
            std::cerr << "저장된 게임이 없습니다.\n";
            return false;
        }

        board.clear(); // 기존 보드 초기화

        int colorInt;
        int savedTurnCount;

        inFile >> colorInt;
        inFile >> colorInt >> savedTurnCount;
        currentColor = static_cast<Color>(colorInt);
        turnCount = savedTurnCount;
        
        int row, col;
        char symbol;
        while (inFile >> row >> col >> symbol) {
            board.placePieceFromSymbol(row, col, symbol);
        }

        inFile.close();
        return true;
    }

}
