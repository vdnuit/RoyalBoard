// ui/Screen.h
#ifndef SCREEN_H
#define SCREEN_H

#include <string>

namespace ui {

    void clearConsole();
    
    // 출력용 구분선
    void printLine(int width = 39, char fill = '-');

    // 제목 출력
    void printTitle(const std::string& title, int width = 39);

    // 가운데 정렬 텍스트 출력
    void printCentered(const std::string& text, int width = 39);

    // 사용자 입력 유도 (ex. "입력: ")
    void printPrompt(const std::string& prompt = "입력: ");

} // namespace ui

#endif // SCREEN_H
