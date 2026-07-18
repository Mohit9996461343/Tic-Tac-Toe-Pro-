#include <iostream>
#include "game.h"

using namespace std;

void showInstructions()
{
    cout << "\n===== HOW TO PLAY =====\n";
    cout << "1. Player X starts the game.\n";
    cout << "2. Enter row and column numbers (1-3).\n";
    cout << "3. First player to make 3 symbols in a row wins.\n";
    cout << "4. Have fun!\n\n";
}

int main()
{
    int choice;

    while(true)
    {
        cout << "\n============================\n";
        cout << "       TIC TAC TOE PRO       \n";
        cout << "============================\n";

        cout << "1. Start New Game\n";
        cout << "2. How to Play\n";
        cout << "3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1)
        {
            string name1, name2;

            cout << "\nEnter Player 1 name: ";
            cin >> name1;

            cout << "Enter Player 2 name: ";
            cin >> name2;

            Player player1(name1, 'X');
            Player player2(name2, 'O');

            Game game(player1, player2);

            game.startGame();
        }
        else if(choice == 2)
        {
            showInstructions();
        }
        else if(choice == 3)
        {
            cout << "Thanks for playing!\n";
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}