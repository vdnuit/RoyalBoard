// GameManager.cpp
#include "GameManager.h"
#include <iostream>
#include "ui/RuleScreen.h"
#include "utils/GameFlow.h"

GameManager::GameManager()
    : whitePlayer(Color::WHITE), blackPlayer(Color::BLACK), currentPlayer(&whitePlayer) {
    board.initialize();
}

void GameManager::start() {
    int turnCount = 0;

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
            std::cout << "\n게임을 종료합니다.\n";
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
            break;
        }

        if (++turnCount >= 80) {
            ui::renderBoard(board);
            std::cout << "\n80턴이 지나 무승부입니다.\n";
            utils::waitAndContinue();
            break;
        }

        switchTurn();
    }
}


void GameManager::switchTurn() {
    currentPlayer = (currentPlayer == &whitePlayer) ? &blackPlayer : &whitePlayer;
}
