#include "GameFlow.h"
#include <iostream>
#include <thread>
#include <chrono>

namespace utils {

    void waitAndContinue(int seconds) {
        std::cout << seconds << "초 후에 다시 진행됩니다...\n";
        std::this_thread::sleep_for(std::chrono::seconds(seconds));
    }

}
