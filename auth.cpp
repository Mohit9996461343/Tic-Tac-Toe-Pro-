#include "auth.h"
#include <fstream>


bool Auth::registerUser(string username, string password)
{
    ifstream checkFile("users.txt");

    string user;
    string pass;


    while(checkFile >> user >> pass)
    {
        if(user == username)
        {
            checkFile.close();
            return false;   // User already exists
        }
    }


    checkFile.close();



    ofstream file("users.txt", ios::app);


    if(file.is_open())
    {
        file << username << " "
             << password << endl;

        file.close();

        return true;
    }


    return false;
}





bool Auth::loginUser(string username, string password)
{
    ifstream file("users.txt");


    string user;
    string pass;



    while(file >> user >> pass)
    {
        if(user == username && pass == password)
        {
            file.close();
            return true;
        }
    }


    file.close();


    return false;
}