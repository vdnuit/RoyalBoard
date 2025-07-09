// GameManager.cpp
#include "GameManager.h"
#include <iostream>
#include <cstdio>
#include "ui/RuleScreen.h"
#include "utils/GameFlow.h"
#include "utils/SaveLoadManager.h"

GameManager::GameManager()
    : whitePlayer(Color::WHITE), blackPlayer(Color::BLACK), currentPlayer(&whitePlayer),turnCount(0) {
    board.initialize();
}

// 불러오기용
GameManager::GameManager(const Board& loadedBoard, Color currentColor, int turnCount)
    : board(loadedBoard),
      whitePlayer(Color::WHITE),
      blackPlayer(Color::BLACK),
      currentPlayer(currentColor == Color::WHITE ? &whitePlayer : &blackPlayer),
      loadedFromSave(true),
      turnCount(turnCount) {}

void GameManager::start() {
    // int turnCount = 0;

    while (true) {
        ui::renderBoard(board);
        int fullTurn = (turnCount / 2) + 1;

        std::cout << fullTurn << "번째 턴 - " << (currentPlayer->getColor() == Color::WHITE ? "백" : "흑") << "의 차례입니다.\n";
        std::cout << "다음 수를 입력하세요. (예: e2 e4)\n";

        std::string fromStr, toStr;
        if (!ui::getMoveInput(fromStr, toStr)) {
            std::cout << "입력이 잘못되었습니다. 다시 시도하세요.\n";
            utils::waitAndContinue();
            continue;
        }

        if (fromStr == "0") {
            return;
        } else if (fromStr == "1") {
            ui::showRuleScreen();
            continue;
        } else if (fromStr == "2") {
            std::cout << "\n게임을 저장하고 종료하시겠습니까? (y/n): ";
            char saveChoice;
            std::cin >> saveChoice;
            if (saveChoice == 'y' || saveChoice == 'Y') {
                
                if (utils::SaveLoadManager::saveGame(board, currentPlayer->getColor(), turnCount,"save.txt")) {
                    std::cout << "게임이 저장되었습니다.\n";
                }
            }
            std::cout << "게임을 종료합니다.\n";
            exit(0);
        }

        Position from, to;
        try {
            from = Position::fromString(fromStr);
            to = Position::fromString(toStr);
        } catch (const std::exception& e) {
            std::cout << "좌표 형식이 올바르지 않습니다. 다시 시도하세요.\n";
            utils::waitAndContinue();
            continue;
        }

        if (!rules::isValidMove(board, from, to, currentPlayer->getColor())) {
            std::cout << "잘못된 수입니다. 다시 시도하세요.\n";
            utils::waitAndContinue();
            continue;
        }

        board.movePiece(from, to);

        if (rules::isCheckmate(board, currentPlayer->getOpponentColor())) {
            ui::renderBoard(board);
            ui::showEndScreen(currentPlayer->getColor());
            if (loadedFromSave) {
                std::remove("save.txt");
            }
            break;
        }

        if (++turnCount >= 80) {
            ui::renderBoard(board);
            std::cout << "\n80턴이 지나 무승부입니다.\n";
            utils::waitAndContinue();
            if (loadedFromSave) {
                std::remove("save.txt");
            }
            break;
        }

        switchTurn();
    }
}


void GameManager::switchTurn() {
    currentPlayer = (currentPlayer == &whitePlayer) ? &blackPlayer : &whitePlayer;
}
