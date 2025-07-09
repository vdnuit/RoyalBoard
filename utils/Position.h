// utils/Position.h
#ifndef POSITION_H
#define POSITION_H

#include <string>

class Position {
public:
    int row; // 0~7 (8행 → row 0, 1행 → row 7)
    int col; // 0~7 (a열 → col 0, h열 → col 7)

    Position();                         // 기본 생성자 (0,0)
    Position(int r, int c);             // 지정 생성자
    bool isValid() const;               // 유효한 좌표인지 확인
    std::string toString() const;       // (6,4) → "e2"
    static Position fromString(const std::string& coord); // "e2" → (6,4)

    bool operator==(const Position& other) const;
    bool operator!=(const Position& other) const;
};

#endif // POSITION_H
