#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "player.h"

using namespace std;

class Game
{
private:
    char board[3][3];
    Player player1;
    Player player2;

public:
    Game(Player p1, Player p2);

    void displayBoard();
    bool makeMove(Player &player, int row, int col);
    bool checkWinner(Player &player);
    bool isDraw();
    void startGame();
};

#endif