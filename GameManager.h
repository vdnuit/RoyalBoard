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
    GameManager(const Board& loadedBoard, Color currentColor, int turnCount);  // 저장된 게임 불러오기
    void start();

    Board& getBoard();
    Color& getCurrentColor();

private:
    Board board;
    Player whitePlayer;
    Player blackPlayer;
    Player* currentPlayer;

    int turnCount;
    bool loadedFromSave = false;

    void switchTurn();
    void handleTurn();
};

#endif // GAMEMANAGER_H
