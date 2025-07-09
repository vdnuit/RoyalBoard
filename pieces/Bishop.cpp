// pieces/Bishop.cpp
#include "Bishop.h"
#include "../Board.h"
#include <cmath>

char Bishop::getSymbol() const {
    return (color == Color::WHITE) ? 'B' : 'b';
}

bool Bishop::canMoveTo(const Board& board, const Position& from, const Position& to) const {
    int dr = to.row - from.row;
    int dc = to.col - from.col;
    if (std::abs(dr) != std::abs(dc)) return false;

    int stepR = (dr > 0) ? 1 : -1;
    int stepC = (dc > 0) ? 1 : -1;

    int r = from.row + stepR;
    int c = from.col + stepC;
    while (r != to.row && c != to.col) {
        if (board.getPieceAt(Position(r, c))) return false;
        r += stepR;
        c += stepC;
    }

    Piece* target = board.getPieceAt(to);
    return !target || target->getColor() != color;
}