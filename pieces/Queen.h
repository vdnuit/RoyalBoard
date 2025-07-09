// pieces/Queen.h
#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
public:
    Queen(Color c) : Piece(c) {}
    char getSymbol() const override;
    bool canMoveTo(const Board& board, const Position& from, const Position& to) const override;
};

#endif // QUEEN_H