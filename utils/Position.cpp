// utils/Position.cpp
#include "Position.h"
#include <cctype>
#include <stdexcept>

Position::Position() : row(0), col(0) {}

Position::Position(int r, int c) : row(r), col(c) {}

bool Position::isValid() const {
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

std::string Position::toString() const {
    if (!isValid()) return "??";

    char file = 'a' + col;       // col 0 → 'a'
    char rank = '8' - row;       // row 0 → '8'
    return std::string{file, rank};
}

Position Position::fromString(const std::string& coord) {
    if (coord.length() != 2) {
        throw std::invalid_argument("좌표 형식이 잘못되었습니다: " + coord);
    }

    char file = std::tolower(coord[0]); // 'a'~'h'
    char rank = coord[1];               // '1'~'8'

    if (file < 'a' || file > 'h' || rank < '1' || rank > '8') {
        throw std::invalid_argument("좌표 범위가 잘못되었습니다: " + coord);
    }

    int col = file - 'a';       // a~h → 0~7
    int row = 8 - (rank - '0'); // '1'~'8' → 7~0

    return Position(row, col);
}

bool Position::operator==(const Position& other) const {
    return row == other.row && col == other.col;
}

bool Position::operator!=(const Position& other) const {
    return !(*this == other);
}
