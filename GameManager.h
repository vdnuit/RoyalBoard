// GameManager.h
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Board.h"
#include "Player.h"
#include "rules/TurnController.h"
#include "rules/MoveValidator.h"
#include "rules/CheckDetector.h"
#include "rules/CheckmateDetector.h"
#include "ui/GameScreen.h"
#include "ui/EndScreen.h"
#include "ui/InputHandler.h"

class GameManager {
public:
    GameManager();
    void start();

private:
    Board board;
    Player whitePlayer;
    Player blackPlayer;
    Player* currentPlayer;

    void switchTurn();
    void handleTurn();
};

#endif // GAMEMANAGER_H
