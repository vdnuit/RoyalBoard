// pieces/King.cpp
#include "King.h"
#include "../Board.h"
#include <cmath>

char King::getSymbol() const {
    return (color == Color::WHITE) ? 'K' : 'k';
}

bool King::canMoveTo(const Board& board, const Position& from, const Position& to) const {
    int dr = std::abs(to.row - from.row);
    int dc = std::abs(to.col - from.col);
    Piece* target = board.getPieceAt(to);
    if (target && target->getColor() == color) return false;
    return dr <= 1 && dc <= 1;
}