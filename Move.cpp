// Move.cpp
#include "Move.h"
#include <cctype>
#include <stdexcept>

bool Position::isValid() const {
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

Position Position::fromString(const std::string& coord) {
    if (coord.length() != 2) throw std::invalid_argument("좌표 형식 오류");

    char file = std::tolower(coord[0]); // 'a'~'h'
    char rank = coord[1];               // '1'~'8'

    int col = file - 'a';
    int row = 8 - (rank - '0');

    return Position(row, col);
}
