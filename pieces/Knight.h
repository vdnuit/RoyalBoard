// pieces/Knight.h
#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
    Knight(Color c) : Piece(c) {}
    char getSymbol() const override;
    bool canMoveTo(const Board& board, const Position& from, const Position& to) const override;
};

#endif // KNIGHT_H