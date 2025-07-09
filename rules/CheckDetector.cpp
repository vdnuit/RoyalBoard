// rules/CheckDetector.cpp
#include "CheckDetector.h"
#include "../utils/Position.h"

namespace rules {
    bool isKingInCheck(const Board& board, Color kingColor) {
        Position kingPos(-1, -1);
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                Piece* p = board.getPieceAt(Position(row, col));
                if (p && p->getColor() == kingColor && p->getSymbol() == (kingColor == Color::WHITE ? 'K' : 'k')) {
                    kingPos = Position(row, col);
                }
            }
        }

        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                Piece* p = board.getPieceAt(Position(row, col));
                if (p && p->getColor() != kingColor) {
                    if (p->canMoveTo(board, Position(row, col), kingPos)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}