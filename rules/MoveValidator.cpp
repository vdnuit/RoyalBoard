// rules/MoveValidator.cpp
#include "MoveValidator.h"

namespace rules {
    bool isValidMove(Board& board, const Position& from, const Position& to, Color playerColor) {
        Piece* piece = board.getPieceAt(from);
        if (!piece || piece->getColor() != playerColor) return false;
        return piece->canMoveTo(board, from, to);
    }
}