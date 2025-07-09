// main.cpp
#include <iostream>
#include <fstream>
#include "ui/StartScreen.h"
#include "ui/RuleScreen.h"
#include "ui/EndScreen.h"
#include "GameManager.h"
#include <windows.h>
#include "utils/SaveLoadManager.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    while (true) {
        int choice = ui::showStartScreen();

        switch (choice) {
            case 1: {  // 새 게임
                GameManager game;
                game.start();
                break;
            }
            case 2: {  // 규칙 보기
                ui::showRuleScreen();
                break;
            }
            case 3: {  // 저장된 게임 불러오기
                Board loadedBoard;
                Color currentColor;
                int loadedTurnCount;

                if (utils::SaveLoadManager::loadGame(loadedBoard, currentColor, loadedTurnCount, "save.txt")) {
                    GameManager loadedGame(loadedBoard, currentColor, loadedTurnCount);
                    loadedGame.start();
                } else {
                    std::cout << "저장된 게임이 없습니다.\n";
                }
                break;
            }
            case 4:  // 종료
                std::cout << "\n게임을 종료합니다.\n";
                return 0;

            default:
                std::cout << "올바른 번호를 입력해주세요.\n";
                break;
        }
    }
}