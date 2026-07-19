#include "achievement.h"
#include <fstream>
#include <vector>

using namespace std;




vector<string> Achievement::getAchievements(
        int wins,
        int losses,
        int draws,
        int points,
        int totalGames)
{

    vector<string> achievements;



    if(wins >= 1)
        achievements.push_back("First_Victory");



    if(wins >= 3)
        achievements.push_back("Winning_Streak");



    if(totalGames >= 10)
        achievements.push_back("Experienced_Player");



    if(points >= 100)
        achievements.push_back("Champion");



    if(losses == 0 && wins >= 5)
        achievements.push_back("Unbeaten_Player");



    return achievements;
}







void Achievement::saveAchievements(
        string username,
        vector<string> achievements)
{

    vector<pair<string,string>> data;



    ifstream inFile("achievements.txt");



    string user;
    string achievement;



    while(inFile >> user >> achievement)
    {
        data.push_back({user,achievement});
    }



    inFile.close();





    // Remove old achievements of same player

    vector<pair<string,string>> updated;



    for(auto item : data)
    {

        if(item.first != username)
        {
            updated.push_back(item);
        }

    }







    // Add new achievements

    for(string a : achievements)
    {

        updated.push_back(
            {username,a}
        );

    }







    ofstream outFile("achievements.txt");



    for(auto item : updated)
    {

        outFile << item.first
                << " "
                << item.second
                << endl;

    }



    outFile.close();

}









vector<string> Achievement::loadAchievements(
        string username)
{

    vector<string> result;



    ifstream file("achievements.txt");



    string user;
    string achievement;



    while(file >> user >> achievement)
    {

        if(user == username)
        {
            result.push_back(achievement);
        }

    }



    file.close();



    return result;
}