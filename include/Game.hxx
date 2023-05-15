#pragma once

#include "Player.hxx"

class Game {
public:
    static Player** EntityList();
    static int PlayersOnMap();
    static const float* ViewMatrix();
};
