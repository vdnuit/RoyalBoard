// pieces/Rook.cpp
#include "Rook.h"
#include "../Board.h"
#include <cmath>

char Rook::getSymbol() const {
    return (color == Color::WHITE) ? 'R' : 'r';
}

bool Rook::canMoveTo(const Board& board, const Position& from, const Position& to) const {
    if (from.row != to.row && from.col != to.col) return false;
    int dr = (to.row > from.row) - (to.row < from.row);
    int dc = (to.col > from.col) - (to.col < from.col);

    int r = from.row + dr;
    int c = from.col + dc;
    while (r != to.row || c != to.col) {
        if (board.getPieceAt(Position(r, c))) return false;
        r += dr;
        c += dc;
    }

    Piece* target = board.getPieceAt(to);
    return !target || target->getColor() != color;
}