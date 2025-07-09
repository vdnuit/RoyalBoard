// Board.cpp
#include "Board.h"
#include "pieces/Pawn.h"
#include "pieces/Rook.h"
#include "pieces/Knight.h"
#include "pieces/Bishop.h"
#include "pieces/Queen.h"
#include "pieces/King.h"
#include <iostream>

Board::Board() {
    clear();
}

void Board::clear() {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            squares[i][j] = nullptr;
}

void Board::initialize() {
    clear();

    // 백 기물
    Color white = Color::WHITE;
    squares[7][0] = new Rook(white);
    squares[7][1] = new Knight(white);
    squares[7][2] = new Bishop(white);
    squares[7][3] = new Queen(white);
    squares[7][4] = new King(white);
    squares[7][5] = new Bishop(white);
    squares[7][6] = new Knight(white);
    squares[7][7] = new Rook(white);
    for (int i = 0; i < 8; ++i)
        squares[6][i] = new Pawn(white);

    // 흑 기물
    Color black = Color::BLACK;
    squares[0][0] = new Rook(black);
    squares[0][1] = new Knight(black);
    squares[0][2] = new Bishop(black);
    squares[0][3] = new Queen(black);
    squares[0][4] = new King(black);
    squares[0][5] = new Bishop(black);
    squares[0][6] = new Knight(black);
    squares[0][7] = new Rook(black);
    for (int i = 0; i < 8; ++i)
        squares[1][i] = new Pawn(black);
}

Piece* Board::getPieceAt(const Position& pos) const {
    if (!pos.isValid()) return nullptr;
    return squares[pos.row][pos.col];
}

char Board::getSymbolAt(int row, int col) const {
    Piece* p = squares[row][col];
    return p ? p->getSymbol() : ' ';
}

void Board::movePiece(const Position& from, const Position& to) {
    if (!from.isValid() || !to.isValid()) return;

    Piece* moving = squares[from.row][from.col];
    delete squares[to.row][to.col];  // 기존 기물 제거 (캡처)
    squares[to.row][to.col] = moving;
    squares[from.row][from.col] = nullptr;
}
