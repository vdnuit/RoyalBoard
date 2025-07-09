// pieces/Rook.h
#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
public:
    Rook(Color c) : Piece(c) {}
    char getSymbol() const override;
    bool canMoveTo(const Board& board, const Position& from, const Position& to) const override;
};

#endif // ROOK_H