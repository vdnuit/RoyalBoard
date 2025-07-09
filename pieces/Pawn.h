// pieces/Pawn.h
#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(Color c) : Piece(c) {}
    char getSymbol() const override;
    bool canMoveTo(const Board& board, const Position& from, const Position& to) const override;
};

#endif // PAWN_H