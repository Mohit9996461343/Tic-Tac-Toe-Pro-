#include "game.h"

Game::Game(Player p1, Player p2) : player1(p1), player2(p2)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void Game::displayBoard()
{
    cout << "\n";
    cout << "-------------\n";

    for(int i = 0; i < 3; i++)
    {
        cout << "| ";

        for(int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " | ";
        }

        cout << "\n-------------\n";
    }
}

bool Game::makeMove(Player &player, int row, int col)
{
    if(row < 0 || row >= 3 || col < 0 || col >= 3)
        return false;

    if(board[row][col] != ' ')
        return false;

    board[row][col] = player.getSymbol();

    return true;
}

bool Game::checkWinner(Player &player)
{
    char symbol = player.getSymbol();

    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == symbol &&
           board[i][1] == symbol &&
           board[i][2] == symbol)
            return true;

        if(board[0][i] == symbol &&
           board[1][i] == symbol &&
           board[2][i] == symbol)
            return true;
    }

    if(board[0][0] == symbol &&
       board[1][1] == symbol &&
       board[2][2] == symbol)
        return true;

    if(board[0][2] == symbol &&
       board[1][1] == symbol &&
       board[2][0] == symbol)
        return true;

    return false;
}

bool Game::isDraw()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == ' ')
                return false;
        }
    }

    return true;
}

void Game::startGame()
{
    Player *current = &player1;

    while(true)
    {
        displayBoard();

        int row, col;

        cout << current->getName()
             << " enter row and column (1-3): ";

        cin >> row >> col;

        row--;
        col--;

        if(makeMove(*current, row, col))
        {
            if(checkWinner(*current))
            {
                displayBoard();

                cout << current->getName()
                     << " wins!" << endl;

                current->addWin();

                if(current == &player1)
                    player2.addLoss();
                else
                    player1.addLoss();

                player1.showStats();
                player2.showStats();

                break;
            }

            if(isDraw())
            {
                displayBoard();

                cout << "Match Draw!" << endl;

                player1.addDraw();
                player2.addDraw();

                player1.showStats();
                player2.showStats();

                break;
            }

            if(current == &player1)
                current = &player2;
            else
                current = &player1;
        }
        else
        {
            cout << "Invalid move! Try again.\n";
        }
    }
}