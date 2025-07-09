// rules/MoveValidator.h
#ifndef MOVEVALIDATOR_H
#define MOVEVALIDATOR_H

#include "../Board.h"
#include "../utils/Position.h"
#include "../Color.h"

namespace rules {
    bool isValidMove(Board& board, const Position& from, const Position& to, Color playerColor);
}

#endif // MOVEVALIDATOR_H