#include "Game.hxx"

Player** Game::EntityList() {
    return *(Player***)(0x58AC04);
}

int Game::PlayersOnMap() {
    return *(int*)(0x58AC0C);
}

const float* Game::ViewMatrix() {
    return (float*)(0x57DFD0);
}