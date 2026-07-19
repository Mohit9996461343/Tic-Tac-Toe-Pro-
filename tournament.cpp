#include "tournament.h"
#include "player.h"
#include "game.h"

#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;



void Tournament::tournamentMenu()
{
    int choice;


    while(true)
    {
        cout << "\n============================\n";
        cout << "       TOURNAMENT MENU\n";
        cout << "============================\n";


        cout << "1. Start Tournament\n";
        cout << "2. View Tournament History\n";
        cout << "3. Hall of Fame\n";
        cout << "4. Back\n";


        cout << "Enter choice: ";
        cin >> choice;



        if(choice == 1)
        {
            startTournament();
        }


        else if(choice == 2)
        {
            showTournamentHistory();
        }


        else if(choice == 3)
        {
            showHallOfFame();
        }


        else if(choice == 4)
        {
            break;
        }


        else
        {
            cout << "Invalid choice!\n";
        }

    }
}







void Tournament::saveTournamentResult(
        string champion,
        string runnerUp)
{

    ofstream file(
        "tournament_history.txt",
        ios::app
    );


    if(file.is_open())
    {

        time_t now = time(0);


        file << "Champion: "
             << champion
             << endl;


        file << "Runner Up: "
             << runnerUp
             << endl;


        file << "Date: "
             << ctime(&now);


        file << "--------------------------------\n";


        file.close();

    }

}







void Tournament::showTournamentHistory()
{

    ifstream file(
        "tournament_history.txt"
    );


    if(!file.is_open())
    {
        cout << "\nNo tournament history found.\n";
        return;
    }



    cout << "\n============================\n";
    cout << "     TOURNAMENT HISTORY\n";
    cout << "============================\n\n";



    string line;


    while(getline(file,line))
    {
        cout << line << endl;
    }



    cout << "============================\n";


    file.close();

}







void Tournament::showHallOfFame()
{

    ifstream file("players.txt");


    if(!file.is_open())
    {
        cout << "\nNo player data found.\n";
        return;
    }



    struct Champion
    {
        string name;
        int points;
        int trophies;
    };



    vector<Champion> players;



    string name;

    int wins;
    int draws;
    int losses;
    int points;
    int trophies;



    while(file >> name
              >> wins
              >> draws
              >> losses
              >> points
              >> trophies)
    {

        Champion p;

        p.name = name;
        p.points = points;
        p.trophies = trophies;


        players.push_back(p);

    }



    file.close();





    sort(
        players.begin(),
        players.end(),

        [](Champion a, Champion b)
        {

            if(a.trophies != b.trophies)
                return a.trophies > b.trophies;


            return a.points > b.points;

        }
    );





    cout << "\n============================\n";
    cout << "          HALL OF FAME\n";
    cout << "============================\n\n";


    cout << left
         << setw(8) << "Rank"
         << setw(15) << "Player"
         << setw(12) << "Trophy"
         << setw(12) << "Points"
         << endl;



    cout << "-----------------------------------\n";


    int rank = 1;



    for(auto player : players)
    {

        cout << left
             << setw(8) << rank
             << setw(15) << player.name
             << setw(12) << player.trophies
             << setw(12) << player.points
             << endl;


        rank++;


        if(rank > 10)
            break;

    }


    cout << "============================\n";

}









void Tournament::startTournament()
{

    cout << "\n============================\n";
    cout << "      TOURNAMENT MODE\n";
    cout << "============================\n";



    string p1Name,p2Name,p3Name,p4Name;



    cout << "Player 1 : ";
    cin >> p1Name;


    cout << "Player 2 : ";
    cin >> p2Name;


    cout << "Player 3 : ";
    cin >> p3Name;


    cout << "Player 4 : ";
    cin >> p4Name;





    Player p1(p1Name,'X');
    Player p2(p2Name,'O');

    Player p3(p3Name,'X');
    Player p4(p4Name,'O');



    p1.loadProfile();
    p2.loadProfile();
    p3.loadProfile();
    p4.loadProfile();





    cout << "\n============================\n";
    cout << "       SEMI FINAL 1\n";
    cout << "============================\n";



    Game semi1(p1,p2,false,0);



    Player *winner1 = semi1.playGame();




    if(winner1 == nullptr)
    {
        cout << "Match Draw. No winner.\n";
        return;
    }





    cout << "\nWinner of Semi Final 1: "
         << winner1->getName()
         << endl;







    cout << "\n============================\n";
    cout << "       SEMI FINAL 2\n";
    cout << "============================\n";



    Game semi2(p3,p4,false,0);



    Player *winner2 = semi2.playGame();




    if(winner2 == nullptr)
    {
        cout << "Match Draw. No winner.\n";
        return;
    }





    cout << "\nWinner of Semi Final 2: "
         << winner2->getName()
         << endl;







    cout << "\n============================\n";
    cout << "          FINAL\n";
    cout << "============================\n";



    Game finalMatch(
        *winner1,
        *winner2,
        false,
        0
    );



    Player *champion = finalMatch.playGame();





    if(champion == nullptr)
    {

        cout << "\nFinal Match Draw!\n";

    }

    else
    {

        string runnerUp;



        if(champion == winner1)
            runnerUp = winner2->getName();

        else
            runnerUp = winner1->getName();





        cout << "\n============================\n";
        cout << "       CHAMPION\n";
        cout << "============================\n";


        cout << "Winner: "
             << champion->getName()
             << endl;


        cout << "Runner Up: "
             << runnerUp
             << endl;



        cout << "Congratulations! 🏆\n";



        champion->addTrophy();



        champion->saveProfile();



        saveTournamentResult(
            champion->getName(),
            runnerUp
        );

    }

}