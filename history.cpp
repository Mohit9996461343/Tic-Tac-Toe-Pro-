#include "history.h"
#include <fstream>


void History::showHistory()
{
    ifstream file("game_history.txt");


    if(!file.is_open())
    {
        cout << "\nNo game history found.\n";
        return;
    }



    cout << "\n============================\n";
    cout << "        GAME HISTORY\n";
    cout << "============================\n\n";


    string line;


    while(getline(file, line))
    {
        cout << line << endl;
    }


    file.close();


    cout << "\n============================\n";
}