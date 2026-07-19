#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <string>
#include <vector>

using namespace std;


class Achievement
{

public:

    static vector<string> getAchievements(
        int wins,
        int losses,
        int draws,
        int points,
        int totalGames
    );


    static void saveAchievements(
        string username,
        vector<string> achievements
    );


    static vector<string> loadAchievements(
        string username
    );

};


#endif