// ui/EndScreen.cpp
#include "EndScreen.h"
#include "Screen.h"
#include <iostream>

namespace ui {

    void showEndScreen(Color winner) {
        clearConsole();
        printTitle("게임 종료");

        std::string name = (winner == Color::WHITE) ? "백(White)" : "흑(Black)";
        std::string icon = (winner == Color::WHITE) ? "♛" : "♚";

        printCentered(icon + "  " + name + "이 이겼습니다!  " + icon);
        std::cout << "\n  체크메이트로 게임이 종료되었습니다.\n";
        printLine();

        printCentered("[1] 처음으로 돌아가기");
        printCentered("[2] 종료");
        printLine();

        printPrompt("번호를 입력하세요: ");
    }

}
