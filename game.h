#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "player.h"
#include "ai.h"

using namespace std;


class Game
{

private:

    char board[3][3];

    Player player1;
    Player player2;


    bool singlePlayer;

    int difficulty;


    void saveHistory(string result);


public:


    Game(Player p1, Player p2, bool aiMode = false, int level = 1);



    void displayBoard();


    bool makeMove(Player &player, int row, int col);


    bool checkWinner(Player &player);


    bool isDraw();



    void startGame();


};

#endif