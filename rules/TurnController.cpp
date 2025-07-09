// rules/TurnController.cpp
#include "TurnController.h"

namespace rules {
    bool isDrawByTurnLimit(int turnCount) {
        return turnCount >= 80;
    }
}