// ui/RuleScreen.cpp
#include "RuleScreen.h"
#include "Screen.h"
#include <iostream>

namespace ui {

    void showRuleScreen() {
        clearConsole();
        printTitle("체스 게임 규칙");

        std::cout << R"(■ 기본 사항
  - 8x8 체스판에서 흑(Black)과 백(White)이 번갈아 수를 둡니다.
  - 흑은 소문자, 백은 대문자로 표기됩니다.
  - 백이 먼저 시작합니다.

■ 기물 기호
  - K/k : King      → 모든 방향으로 한 칸
  - Q/q : Queen     → 직선 + 대각선
  - R/r : Rook      → 직선
  - B/b : Bishop    → 대각선
  - N/n : Knight    → 'ㄴ'자 이동
  - P/p : Pawn      → 전진, 대각선 공격

■ 승리 조건
  - 상대 King을 체크메이트하면 승리
  - 80턴 이상 시 무승부 선언

)" << std::endl;

        printLine();
        printPrompt("0을 입력하면 메인 화면으로 돌아갑니다: ");

        int back;
        std::cin >> back;
        std::cin.ignore();
    }

}
