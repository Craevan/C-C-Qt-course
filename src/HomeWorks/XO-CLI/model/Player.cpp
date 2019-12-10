#include "Player.h"

void Player::initializePlayer(std::string playerName, char playerMark) {
    name = std::move(playerName);
    mark = playerMark;
}

std::string Player::getName() {
    return name;
}

char Player::getMark() {
    return mark;
}

void Player::updateDidWin(){
    winner = true;
}
bool Player::didWin(){
    return winner or false;
}
