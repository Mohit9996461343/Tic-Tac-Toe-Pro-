#include <iostream>
#include "game.h"
#include "history.h"

using namespace std;


void showInstructions()
{
    cout << "\n============================\n";
    cout << "        HOW TO PLAY\n";
    cout << "============================\n";

    cout << "1. Choose game mode.\n";
    cout << "2. Enter row and column numbers (1-3).\n";
    cout << "3. Make three symbols in a row to win.\n";
    cout << "4. Computer plays as O in AI mode.\n";

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

        cout << "1. Two Player Game\n";
        cout << "2. Play Against Computer\n";
        cout << "3. How to Play\n";
        cout << "4. View Game History\n";
        cout << "5. Exit\n";


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


            Game game(player1, player2, false);


            game.startGame();


            player1.saveProfile();
            player2.saveProfile();


            cout << "\nGame data saved successfully!\n";
        }



        else if(choice == 2)
        {
            string name;
            int level;


            cout << "\nEnter your name: ";
            cin >> name;


            cout << "\nSelect Difficulty:\n";
            cout << "1. Easy\n";
            cout << "2. Medium\n";
            cout << "3. Hard (coming soon)\n";


            cout << "Enter level: ";
            cin >> level;



            Player player(name, 'X');
            Player computer("Computer", 'O');


            player.loadProfile();



            Game game(player, computer, true, level);


            game.startGame();



            player.saveProfile();


            cout << "\nGame data saved successfully!\n";
        }



        else if(choice == 3)
        {
            showInstructions();
        }



        else if(choice == 4)
        {
            History::showHistory();
        }



        else if(choice == 5)
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