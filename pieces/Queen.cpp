// pieces/Queen.cpp
#include "Queen.h"
#include "../Board.h"
#include <cmath>
#include "Rook.h"
#include "Bishop.h"

char Queen::getSymbol() const {
    return (color == Color::WHITE) ? 'Q' : 'q';
}

bool Queen::canMoveTo(const Board& board, const Position& from, const Position& to) const {
    Rook tempR(color);
    Bishop tempB(color);
    return tempR.canMoveTo(board, from, to) || tempB.canMoveTo(board, from, to);
}