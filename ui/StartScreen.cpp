// ui/StartScreen.cpp
#include "StartScreen.h"
#include "Screen.h"
#include <iostream>

namespace ui {

    int showStartScreen() {
        printTitle("Royal Board");
        printCentered("[1] 게임 시작");
        printCentered("[2] 게임 규칙 보기");
        printCentered("[3] 종료");
        printLine();

        printPrompt("번호를 입력하세요: ");

        int choice;
        std::cin >> choice;
        std::cin.ignore();
        return choice;
    }

}
