#include "ai.h"
#include <cstdlib>
#include <ctime>


bool checkLine(char board[3][3], char symbol)
{
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == symbol &&
           board[i][1] == symbol &&
           board[i][2] == ' ')
        {
            board[i][2] = 'O';
            return true;
        }


        if(board[i][0] == symbol &&
           board[i][2] == symbol &&
           board[i][1] == ' ')
        {
            board[i][1] = 'O';
            return true;
        }


        if(board[i][1] == symbol &&
           board[i][2] == symbol &&
           board[i][0] == ' ')
        {
            board[i][0] = 'O';
            return true;
        }




        if(board[0][i] == symbol &&
           board[1][i] == symbol &&
           board[2][i] == ' ')
        {
            board[2][i] = 'O';
            return true;
        }


        if(board[0][i] == symbol &&
           board[2][i] == symbol &&
           board[1][i] == ' ')
        {
            board[1][i] = 'O';
            return true;
        }


        if(board[1][i] == symbol &&
           board[2][i] == symbol &&
           board[0][i] == ' ')
        {
            board[0][i] = 'O';
            return true;
        }
    }



    if(board[0][0] == symbol &&
       board[1][1] == symbol &&
       board[2][2] == ' ')
    {
        board[2][2] = 'O';
        return true;
    }



    if(board[0][2] == symbol &&
       board[1][1] == symbol &&
       board[2][0] == ' ')
    {
        board[2][0] = 'O';
        return true;
    }


    return false;
}




void AI::makeRandomMove(char board[3][3])
{
    srand(time(0));


    while(true)
    {
        int row = rand() % 3;
        int col = rand() % 3;


        if(board[row][col] == ' ')
        {
            board[row][col] = 'O';
            break;
        }
    }
}





void AI::makeMediumMove(char board[3][3])
{

    // Try to win first
    if(checkLine(board, 'O'))
        return;



    // Block player X
    if(checkLine(board, 'X'))
        return;



    // Otherwise random move
    makeRandomMove(board);

}