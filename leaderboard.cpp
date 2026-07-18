#include "leaderboard.h"
#include <fstream>
#include <vector>
#include <algorithm>


struct PlayerData
{
    string name;

    int wins;
    int draws;
    int losses;
};





bool compareWins(PlayerData a, PlayerData b)
{
    return a.wins > b.wins;
}






void Leaderboard::showLeaderboard()
{

    ifstream file("players.txt");


    if(!file.is_open())
    {
        cout << "\nNo player data found.\n";
        return;
    }



    vector<PlayerData> players;



    string name;

    int wins;
    int draws;
    int losses;




    while(file >> name >> wins >> draws >> losses)
    {

        PlayerData p;


        p.name = name;
        p.wins = wins;
        p.draws = draws;
        p.losses = losses;



        players.push_back(p);

    }



    file.close();



    sort(players.begin(), players.end(), compareWins);



    cout << "\n============================\n";
    cout << "        LEADERBOARD\n";
    cout << "============================\n";


    cout << "Rank\tPlayer\tWins\n";



    int rank = 1;


    for(auto p : players)
    {

        cout << rank
             << "\t"
             << p.name
             << "\t"
             << p.wins
             << endl;


        rank++;


        if(rank > 10)
            break;
    }



    cout << "============================\n";

}