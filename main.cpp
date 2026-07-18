#include <iostream>
#include "game.h"
#include "history.h"

using namespace std;


void showInstructions()
{
    cout << "\n============================\n";
    cout << "        HOW TO PLAY\n";
    cout << "============================\n";

    cout << "1. Player X starts the game.\n";
    cout << "2. Enter row and column numbers (1-3).\n";
    cout << "3. Make three symbols in a row to win.\n";
    cout << "4. The game saves your statistics automatically.\n";

    cout << "============================\n\n";
}



int main()
{
    int choice;


    while(true)
    {
        cout << "\n============================\n";
        cout << "       TIC TAC TOE PRO\n";
        cout << "============================\n";

        cout << "1. Start New Game\n";
        cout << "2. How to Play\n";
        cout << "3. View Game History\n";
        cout << "4. Exit\n";


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


            player1.loadProfile();
            player2.loadProfile();



            Game game(player1, player2);


            game.startGame();



            player1.saveProfile();
            player2.saveProfile();


            cout << "\nGame data saved successfully!\n";
        }



        else if(choice == 2)
        {
            showInstructions();
        }



        else if(choice == 3)
        {
            History::showHistory();
        }



        else if(choice == 4)
        {
            cout << "\nThanks for playing Tic Tac Toe Pro!\n";
            break;
        }



        else
        {
            cout << "\nInvalid choice! Try again.\n";
        }

    }


    return 0;
}