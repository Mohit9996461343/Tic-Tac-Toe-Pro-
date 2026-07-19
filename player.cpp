#include "player.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "achievement.h"

using namespace std;


struct PlayerRecord
{
    string name;

    int wins;
    int draws;
    int losses;
    int points;
    int trophies;
};



Player::Player(string n, char s)
{
    name = n;
    symbol = s;

    wins = 0;
    draws = 0;
    losses = 0;
    points = 0;
    trophies = 0;
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



int Player::getPoints()
{
    return points;
}



int Player::getTrophies()
{
    return trophies;
}






string Player::getRank()
{

    if(points >= 300)
        return "Diamond";

    else if(points >= 150)
        return "Gold";

    else if(points >= 50)
        return "Silver";

    else
        return "Bronze";
}







void Player::addWin()
{
    wins++;
    points += 10;
}




void Player::addDraw()
{
    draws++;
    points += 3;
}




void Player::addLoss()
{
    losses++;
    points -= 2;
}





void Player::addTrophy()
{
    trophies++;
    points += 50;
}








void Player::showStats()
{

    cout << "\n============================\n";

    cout << " Player: " << name << endl;
    cout << " Wins   : " << wins << endl;
    cout << " Draws  : " << draws << endl;
    cout << " Losses : " << losses << endl;
    cout << " Points : " << points << endl;
    cout << " Rank   : " << getRank() << endl;
    cout << " Trophy : " << trophies << endl;

    cout << "============================\n";
}








void Player::showProfile()
{

    int totalGames = wins + draws + losses;


    double winRate = 0;


    if(totalGames > 0)
        winRate = ((double)wins / totalGames) * 100;




    cout << "\n============================\n";
    cout << "       PLAYER PROFILE\n";
    cout << "============================\n";


    cout << "Player       : " << name << endl;

    cout << "Wins         : " << wins << endl;

    cout << "Losses       : " << losses << endl;

    cout << "Draws        : " << draws << endl;

    cout << "Games Played : " << totalGames << endl;

    cout << "Win Rate     : " << winRate << "%" << endl;

    cout << "Points       : " << points << endl;

    cout << "Rank         : " << getRank() << endl;

    cout << "Trophies     : " << trophies << endl;




    cout << "\nAchievements:\n";



    vector<string> achievements =
    Achievement::getAchievements(
        wins,
        losses,
        draws,
        points,
        totalGames
    );



    if(achievements.empty())
    {
        cout << "No achievements yet.\n";
    }

    else
    {
        for(string a : achievements)
        {
            cout << "- " << a << endl;
        }
    }



    cout << "============================\n";

}









void Player::saveProfile()
{

    vector<PlayerRecord> players;


    ifstream inFile("players.txt");


    PlayerRecord temp;


    bool found = false;




    while(inFile >> temp.name
                 >> temp.wins
                 >> temp.draws
                 >> temp.losses
                 >> temp.points
                 >> temp.trophies)
    {

        if(temp.name == name)
        {

            temp.wins = wins;
            temp.draws = draws;
            temp.losses = losses;
            temp.points = points;
            temp.trophies = trophies;

            found = true;
        }


        players.push_back(temp);
    }




    inFile.close();






    if(!found)
    {

        PlayerRecord newPlayer;


        newPlayer.name = name;
        newPlayer.wins = wins;
        newPlayer.draws = draws;
        newPlayer.losses = losses;
        newPlayer.points = points;
        newPlayer.trophies = trophies;


        players.push_back(newPlayer);
    }







    ofstream outFile("players.txt");



    for(auto &player : players)
    {

        outFile << player.name << " "
                << player.wins << " "
                << player.draws << " "
                << player.losses << " "
                << player.points << " "
                << player.trophies
                << endl;

    }



    outFile.close();

}









void Player::loadProfile()
{

    ifstream file("players.txt");


    string savedName;


    int savedWins;
    int savedDraws;
    int savedLosses;
    int savedPoints;
    int savedTrophies;




    while(file >> savedName
              >> savedWins
              >> savedDraws
              >> savedLosses
              >> savedPoints
              >> savedTrophies)
    {

        if(savedName == name)
        {

            wins = savedWins;
            draws = savedDraws;
            losses = savedLosses;
            points = savedPoints;
            trophies = savedTrophies;


            break;
        }

    }



    file.close();

}