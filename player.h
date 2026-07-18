#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player
{
private:
    string name;
    char symbol;
    int score;

public:
    Player(string n = "", char s = 'X');

    string getName();
    char getSymbol();
    int getScore();

    void increaseScore();
};

#endif