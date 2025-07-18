#include "EndScreen.h"
#include "Screen.h"
#include <iostream>

namespace ui {

    void showEndScreen(Color winner) {
        clearConsole();
        printTitle("게임 종료");

        std::string name = (winner == Color::WHITE) ? "백(White)" : "흑(Black)";
        printCentered(name + "이 이겼습니다!");

        printCentered("체크메이트로 게임이 종료되었습니다.");
        printLine();

        printCentered("[1] 처음으로 돌아가기");
        printCentered("[2] 종료");
        printLine();

        printPrompt("번호를 입력하세요: ");int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
        } else if (choice == 2) {
            std::cout << "게임을 종료합니다.\n";
            exit(0);
        }

    }

}
