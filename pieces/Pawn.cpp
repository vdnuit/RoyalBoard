// pieces/Pawn.cpp
#include "Pawn.h"
#include "../Board.h"

char Pawn::getSymbol() const {
    return (color == Color::WHITE) ? 'P' : 'p';
}

bool Pawn::canMoveTo(const Board& board, const Position& from, const Position& to) const {
    int direction = (color == Color::WHITE) ? -1 : 1;
    int startRow = (color == Color::WHITE) ? 6 : 1;

    if (from.col == to.col) {
        if (to.row == from.row + direction && board.getPieceAt(to) == nullptr) return true;
        if (from.row == startRow && to.row == from.row + 2 * direction && board.getPieceAt(to) == nullptr) return true;
    } else if (std::abs(from.col - to.col) == 1 && to.row == from.row + direction) {
        Piece* target = board.getPieceAt(to);
        if (target && target->getColor() != color) return true;
    }
    return false;
}
