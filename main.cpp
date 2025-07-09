// main.cpp
#include <iostream>
#include "ui/StartScreen.h"
#include "ui/RuleScreen.h"
#include "ui/EndScreen.h"
#include "GameManager.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    
    while (true) {
        int choice = ui::showStartScreen();

        switch (choice) {
            case 1: {
                GameManager game;
                game.start();
                break;
            }
            case 2:
                ui::showRuleScreen();
                break;
            case 3:
                std::cout << "\n게임을 종료합니다.\n";
                return 0;
            default:
                std::cout << "올바른 번호를 입력해주세요.\n";
                break;
        }
    }
}
