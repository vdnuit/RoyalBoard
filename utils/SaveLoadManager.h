#ifndef SAVELOADMANAGER_H
#define SAVELOADMANAGER_H

#include "../Board.h"
#include "../Player.h"
#include <string>

namespace utils {

    class SaveLoadManager {
    public:
        static bool saveGame(const Board& board, Color currentColor, int turnCount, const std::string& filename = "save.txt");
        static bool loadGame(Board& board, Color& currentColor, int& turnCount, const std::string& filename = "save.txt");
    };

}

#endif // SAVELOADMANAGER_H
