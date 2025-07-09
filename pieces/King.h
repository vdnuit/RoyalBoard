// pieces/King.h
#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
public:
    King(Color c) : Piece(c) {}
    char getSymbol() const override;
    bool canMoveTo(const Board& board, const Position& from, const Position& to) const override;
};

#endif // KING_H