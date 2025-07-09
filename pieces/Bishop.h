// pieces/Bishop.h
#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(Color c) : Piece(c) {}
    char getSymbol() const override;
    bool canMoveTo(const Board& board, const Position& from, const Position& to) const override;
};

#endif // BISHOP_H