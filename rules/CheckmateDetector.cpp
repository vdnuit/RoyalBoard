// rules/CheckmateDetector.cpp
#include "CheckmateDetector.h"
#include "CheckDetector.h"
#include "../utils/Position.h"

namespace rules {
    bool isCheckmate(Board& board, Color kingColor) {
        if (!isKingInCheck(board, kingColor)) return false;

        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                Piece* p = board.getPieceAt(Position(row, col));
                if (p && p->getColor() == kingColor) {
                    for (int r2 = 0; r2 < 8; ++r2) {
                        for (int c2 = 0; c2 < 8; ++c2) {
                            Position from(row, col);
                            Position to(r2, c2);
                            if (p->canMoveTo(board, from, to)) {
                                Board tempBoard = board;
                                tempBoard.movePiece(from, to);
                                if (!isKingInCheck(tempBoard, kingColor)) {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
}
