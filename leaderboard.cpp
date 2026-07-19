#include "leaderboard.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct PlayerData
{
    string name;

    int wins;
    int draws;
    int losses;
    int points;
};





bool comparePlayers(PlayerData a, PlayerData b)
{
    if(a.points != b.points)
        return a.points > b.points;

    if(a.wins != b.wins)
        return a.wins > b.wins;

    int totalA = a.wins + a.draws + a.losses;
    int totalB = b.wins + b.draws + b.losses;

    double rateA = 0;
    double rateB = 0;

    if(totalA > 0)
        rateA = (double)a.wins * 100 / totalA;

    if(totalB > 0)
        rateB = (double)b.wins * 100 / totalB;

    return rateA > rateB;
}





string getRank(int points)
{
    if(points >= 200)
        return "Diamond";

    if(points >= 100)
        return "Platinum";

    if(points >= 50)
        return "Gold";

    if(points >= 20)
        return "Silver";

    return "Bronze";
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

    PlayerData p;

    while(file >> p.name
               >> p.wins
               >> p.draws
               >> p.losses
               >> p.points)
    {
        players.push_back(p);
    }

    file.close();

    sort(players.begin(), players.end(), comparePlayers);

    cout << "\n";
    cout << "=================================================================================\n";
    cout << "                               TIC TAC TOE LEADERBOARD\n";
    cout << "=================================================================================\n\n";

    cout << left
         << setw(6)  << "Rank"
         << setw(15) << "Player"
         << setw(10) << "Points"
         << setw(8)  << "Wins"
         << setw(8)  << "Loss"
         << setw(8)  << "Draw"
         << setw(10) << "Rate"
         << setw(12) << "League"
         << endl;

    cout << "---------------------------------------------------------------------------------\n";

    int position = 1;

    for(auto player : players)
    {
        int totalGames = player.wins + player.draws + player.losses;

        double winRate = 0;

        if(totalGames > 0)
            winRate = (double)player.wins * 100 / totalGames;

        cout << left
             << setw(6)  << position
             << setw(15) << player.name
             << setw(10) << player.points
             << setw(8)  << player.wins
             << setw(8)  << player.losses
             << setw(8)  << player.draws
             << setw(9)  << fixed << setprecision(1) << winRate
             << "%"
             << setw(11) << getRank(player.points)
             << endl;

        position++;

        if(position > 10)
            break;
    }

    cout << "\n=================================================================================\n";
}