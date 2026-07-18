#include <iostream>
#include "game.h"
#include "history.h"
#include "auth.h"

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



void gameMenu(string username)
{
    int choice;


    while(true)
    {
        cout << "\n============================\n";
        cout << "       TIC TAC TOE PRO\n";
        cout << " Welcome, " << username << endl;
        cout << "============================\n";


        cout << "1. Two Player Game\n";
        cout << "2. Play Against Computer\n";
        cout << "3. How to Play\n";
        cout << "4. View Game History\n";
        cout << "5. Logout\n";


        cout << "Enter your choice: ";
        cin >> choice;



        if(choice == 1)
        {
            string name1, name2;


            cout << "\nEnter Player 1 name: ";
            cin >> name1;


            cout << "Enter Player 2 name: ";
            cin >> name2;



            Player player1(name1,'X');
            Player player2(name2,'O');


            player1.loadProfile();
            player2.loadProfile();



            Game game(player1,player2,false);


            game.startGame();



            player1.saveProfile();
            player2.saveProfile();
        }




        else if(choice == 2)
        {
            int level;


            cout << "\nSelect Difficulty:\n";
            cout << "1. Easy\n";
            cout << "2. Medium\n";
            cout << "3. Hard\n";


            cout << "Enter level: ";
            cin >> level;



            Player player(username,'X');

            Player computer("Computer",'O');



            player.loadProfile();



            Game game(player,computer,true,level);



            game.startGame();



            player.saveProfile();
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
            cout << "Logging out...\n";
            break;
        }





        else
        {
            cout << "Invalid choice!\n";
        }

    }
}





int main()
{
    int choice;


    while(true)
    {
        cout << "\n============================\n";
        cout << "       TIC TAC TOE PRO\n";
        cout << "============================\n";


        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";


        cout << "Enter your choice: ";
        cin >> choice;



        if(choice == 1)
        {
            string username;
            string password;


            cout << "Create username: ";
            cin >> username;


            cout << "Create password: ";
            cin >> password;



            if(Auth::registerUser(username,password))
            {
                cout << "Registration successful!\n";
            }
            else
            {
                cout << "Username already exists!\n";
            }

        }




        else if(choice == 2)
        {
            string username;
            string password;



            cout << "Username: ";
            cin >> username;


            cout << "Password: ";
            cin >> password;



            if(Auth::loginUser(username,password))
            {
                cout << "Login successful!\n";


                gameMenu(username);
            }

            else
            {
                cout << "Invalid username or password!\n";
            }
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