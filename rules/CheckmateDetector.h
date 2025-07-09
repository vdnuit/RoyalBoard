// rules/CheckmateDetector.h
#ifndef CHECKMATEDETECTOR_H
#define CHECKMATEDETECTOR_H

#include "../Board.h"
#include "../Color.h"

namespace rules {
    bool isCheckmate(Board& board, Color kingColor);
}

#endif // CHECKMATEDETECTOR_H