// pieces/Piece.h
#ifndef PIECE_H
#define PIECE_H

#include "../Color.h"
#include "../utils/Position.h"
class Board; // 전방 선언

class Piece {
protected:
    Color color;

public:
    Piece(Color c) : color(c) {}
    virtual ~Piece() = default;

    Color getColor() const { return color; }
    virtual char getSymbol() const = 0;
    virtual bool canMoveTo(const Board& board, const Position& from, const Position& to) const = 0;
};

#endif // PIECE_H