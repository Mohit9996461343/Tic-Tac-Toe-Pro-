#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <string>

using namespace std;


class Tournament
{

public:

    static void startTournament();

    static void tournamentMenu();

    static void showTournamentHistory();

    static void saveTournamentResult(
        string champion,
        string runnerUp
    );

    static void showHallOfFame();

};

#endif