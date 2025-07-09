// pieces/Knight.cpp
#include "Knight.h"
#include "../Board.h"
#include <cmath>

char Knight::getSymbol() const {
    return (color == Color::WHITE) ? 'N' : 'n';
}

bool Knight::canMoveTo(const Board& board, const Position& from, const Position& to) const {
    int dr = std::abs(to.row - from.row);
    int dc = std::abs(to.col - from.col);
    Piece* target = board.getPieceAt(to);
    if (target && target->getColor() == color) return false;
    return (dr == 2 && dc == 1) || (dr == 1 && dc == 2);
}