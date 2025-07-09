// Move.h
#ifndef MOVE_H
#define MOVE_H

#include <string>

struct Position {
    int row; // 0~7
    int col; // 0~7

    Position(int r, int c) : row(r), col(c) {}
    bool isValid() const;

    static Position fromString(const std::string& coord); // "e2" → (6,4)
};

#endif // MOVE_H
