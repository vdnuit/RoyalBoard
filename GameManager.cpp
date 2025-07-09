// GameManager.cpp
#include "GameManager.h"
#include <iostream>

GameManager::GameManager()
    : whitePlayer(Color::WHITE), blackPlayer(Color::BLACK), currentPlayer(&whitePlayer) {
    board.initialize();
}

void GameManager::start() {
    int turnCount = 0;

    while (true) {
        ui::renderBoard(board);
        std::cout << (currentPlayer->getColor() == Color::WHITE ? "백" : "흑") << "의 차례입니다.\n";
        std::cout << "다음 수를 입력하세요. (예: e2 e4)\n";

        std::string fromStr, toStr;
        if (!ui::getMoveInput(fromStr, toStr)) {
            std::cout << "입력이 잘못되었습니다. 다시 시도하세요.\n";
            continue;
        }

        Position from = Position::fromString(fromStr);
        Position to = Position::fromString(toStr);

        if (!rules::isValidMove(board, from, to, currentPlayer->getColor())) {
            std::cout << "잘못된 수입니다. 다시 시도하세요.\n";
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
            break;
        }

        switchTurn();
    }
}

void GameManager::switchTurn() {
    currentPlayer = (currentPlayer == &whitePlayer) ? &blackPlayer : &whitePlayer;
}
