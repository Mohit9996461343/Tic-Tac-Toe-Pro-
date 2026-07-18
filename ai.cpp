#include "ai.h"
#include <cstdlib>
#include <ctime>


void AI::makeMove(char board[3][3])
{
    int row;
    int col;


    srand(time(0));


    while(true)
    {
        row = rand() % 3;
        col = rand() % 3;


        if(board[row][col] == ' ')
        {
            board[row][col] = 'O';
            break;
        }
    }
}