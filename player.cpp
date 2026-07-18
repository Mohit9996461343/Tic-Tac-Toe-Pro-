#include "player.h"
#include <iostream>
#include <fstream>

using namespace std;



Player::Player(string n, char s)
{
    name = n;
    symbol = s;

    wins = 0;
    draws = 0;
    losses = 0;
}



string Player::getName()
{
    return name;
}



char Player::getSymbol()
{
    return symbol;
}



int Player::getWins()
{
    return wins;
}



int Player::getDraws()
{
    return draws;
}



int Player::getLosses()
{
    return losses;
}



void Player::addWin()
{
    wins++;
}



void Player::addDraw()
{
    draws++;
}



void Player::addLoss()
{
    losses++;
}





void Player::showStats()
{
    cout << "\n============================\n";
    cout << " Player: " << name << endl;
    cout << " Wins   : " << wins << endl;
    cout << " Draws  : " << draws << endl;
    cout << " Losses : " << losses << endl;
    cout << "============================\n";
}





void Player::showProfile()
{
    int totalGames = wins + draws + losses;


    double winRate = 0;


    if(totalGames > 0)
    {
        winRate = ((double)wins / totalGames) * 100;
    }



    cout << "\n============================\n";
    cout << "       PLAYER PROFILE\n";
    cout << "============================\n";


    cout << "Player       : " << name << endl;

    cout << "Wins         : " << wins << endl;

    cout << "Losses       : " << losses << endl;

    cout << "Draws        : " << draws << endl;

    cout << "Games Played : " << totalGames << endl;

    cout << "Win Rate     : " << winRate << "%" << endl;


    cout << "============================\n";
}





void Player::saveProfile()
{
    ofstream file("players.txt", ios::app);


    if(file.is_open())
    {
        file << name << " "
             << wins << " "
             << draws << " "
             << losses << endl;


        file.close();
    }
}





void Player::loadProfile()
{
    ifstream file("players.txt");


    string savedName;

    int savedWins;
    int savedDraws;
    int savedLosses;



    while(file >> savedName
              >> savedWins
              >> savedDraws
              >> savedLosses)
    {

        if(savedName == name)
        {
            wins = savedWins;
            draws = savedDraws;
            losses = savedLosses;

            break;
        }
    }



    file.close();
}