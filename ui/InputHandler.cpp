// ui/InputHandler.cpp
#include "InputHandler.h"
#include <iostream>
#include <sstream>

namespace ui {

    bool getMoveInput(std::string& from, std::string& to) {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        return (iss >> from >> to) ? true : false;
    }

}
