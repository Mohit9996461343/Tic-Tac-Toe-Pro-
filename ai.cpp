#include "ai.h"
#include <cstdlib>
#include <ctime>


bool isMovesLeft(char board[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == ' ')
                return true;
        }
    }

    return false;
}



int evaluate(char board[3][3])
{
    // Rows
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2])
        {
            if(board[i][0] == 'O')
                return 10;

            if(board[i][0] == 'X')
                return -10;
        }
    }



    // Columns
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i])
        {
            if(board[0][i] == 'O')
                return 10;

            if(board[0][i] == 'X')
                return -10;
        }
    }



    // Diagonals
    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
    {
        if(board[0][0] == 'O')
            return 10;

        if(board[0][0] == 'X')
            return -10;
    }



    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
    {
        if(board[0][2] == 'O')
            return 10;

        if(board[0][2] == 'X')
            return -10;
    }


    return 0;
}




int AI::minimax(char board[3][3], int depth, bool isMax)
{
    int score = evaluate(board);


    if(score == 10)
        return score - depth;


    if(score == -10)
        return score + depth;


    if(!isMovesLeft(board))
        return 0;




    if(isMax)
    {
        int best = -1000;


        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i][j] == ' ')
                {
                    board[i][j] = 'O';


                    best = max(best,
                    minimax(board, depth + 1, false));


                    board[i][j] = ' ';
                }
            }
        }


        return best;
    }



    else
    {
        int best = 1000;


        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i][j] == ' ')
                {
                    board[i][j] = 'X';


                    best = min(best,
                    minimax(board, depth + 1, true));


                    board[i][j] = ' ';
                }
            }
        }


        return best;
    }
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
    // Try winning move
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == ' ')
            {
                board[i][j] = 'O';

                if(evaluate(board) == 10)
                    return;


                board[i][j] = ' ';
            }
        }
    }



    // Block player
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == ' ')
            {
                board[i][j] = 'X';

                if(evaluate(board) == -10)
                {
                    board[i][j] = 'O';
                    return;
                }


                board[i][j] = ' ';
            }
        }
    }


    makeRandomMove(board);
}







void AI::makeHardMove(char board[3][3])
{
    int bestScore = -1000;

    int bestRow = -1;
    int bestCol = -1;



    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == ' ')
            {
                board[i][j] = 'O';


                int score = minimax(board,0,false);


                board[i][j] = ' ';



                if(score > bestScore)
                {
                    bestScore = score;

                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }



    if(bestRow != -1 && bestCol != -1)
    {
        board[bestRow][bestCol] = 'O';
    }
}