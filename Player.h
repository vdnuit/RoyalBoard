// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "Color.h"

class Player {
public:
    explicit Player(Color color);
    Color getColor() const;
    Color getOpponentColor() const;

private:
    Color color;
};

#endif // PLAYER_H
