// Player.cpp
#include "Player.h"

Player::Player(Color color) : color(color) {}

Color Player::getColor() const {
    return color;
}

Color Player::getOpponentColor() const {
    return opposite(color);
}
