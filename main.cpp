#include <iostream>
#include "game.h"

using namespace std;

int main()
{
    cout << "============================\n";
    cout << "       TIC TAC TOE PRO       \n";
    cout << "============================\n\n";

    string name1, name2;

    cout << "Enter Player 1 name: ";
    cin >> name1;

    cout << "Enter Player 2 name: ";
    cin >> name2;

    Player player1(name1, 'X');
    Player player2(name2, 'O');

    Game game(player1, player2);

    game.startGame();

    return 0;
}