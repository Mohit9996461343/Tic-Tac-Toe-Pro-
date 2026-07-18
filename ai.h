#ifndef AI_H
#define AI_H

#include <iostream>

using namespace std;


class AI
{

private:

    static int minimax(char board[3][3], int depth, bool isMax);



public:

    static void makeRandomMove(char board[3][3]);

    static void makeMediumMove(char board[3][3]);

    static void makeHardMove(char board[3][3]);

};


#endif