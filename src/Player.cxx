#include "Player.hxx"

Player* Player::LocalPlayer()
{
    static Player* player = nullptr;
    if (!player) {
        player = *(Player **)0x58AC00;
    }
    
    return player;
}

bool Player::IsAlive() {
    return this->state == 0;
}