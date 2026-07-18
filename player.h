#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player
{
private:

    string name;
    char symbol;

    int wins;
    int draws;
    int losses;


public:

    Player(string n = "", char s = 'X');


    string getName();
    char getSymbol();


    int getWins();
    int getDraws();
    int getLosses();


    void addWin();
    void addDraw();
    void addLoss();


    void showStats();


    // File storage functions
    void saveProfile();
    void loadProfile();

};

#endif