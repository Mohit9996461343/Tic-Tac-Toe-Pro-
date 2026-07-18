#include "player.h"

Player::Player(string n, char s)
{
    name = n;
    symbol = s;
    score = 0;
}

string Player::getName()
{
    return name;
}

char Player::getSymbol()
{
    return symbol;
}

int Player::getScore()
{
    return score;
}

void Player::increaseScore()
{
    score++;
}