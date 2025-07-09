// rules/CheckDetector.h
#ifndef CHECKDETECTOR_H
#define CHECKDETECTOR_H

#include "../Board.h"
#include "../Color.h"

namespace rules {
    bool isKingInCheck(const Board& board, Color kingColor);
}

#endif // CHECKDETECTOR_H
