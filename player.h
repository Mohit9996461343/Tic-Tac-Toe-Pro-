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

    int points;

    int trophies;     // NEW: Tournament trophies


public:


    Player(string n = "", char s = 'X');



    string getName();

    char getSymbol();



    int getWins();

    int getDraws();

    int getLosses();

    int getPoints();

    int getTrophies();     // NEW



    // Rank System
    string getRank();



    void addWin();

    void addDraw();

    void addLoss();

    void addTrophy();      // NEW



    void showStats();

    void showProfile();



    void saveProfile();

    void loadProfile();

};


#endif