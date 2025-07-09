// Board.h
#ifndef BOARD_H
#define BOARD_H

#include "Color.h"
#include "pieces/Piece.h"
#include "utils/Position.h"

class Board {
public:
    Board();
    void initialize();

    void movePiece(const Position& from, const Position& to);
    Piece* getPieceAt(const Position& pos) const;
    char getSymbolAt(int row, int col) const;
    void clear();
    void placePieceFromSymbol(int row, int col, char symbol);

private:
    Piece* squares[8][8]; // 체스판: 8x8 기물 포인터
};

#endif // BOARD_H
