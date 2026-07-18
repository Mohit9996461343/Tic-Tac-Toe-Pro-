#ifndef AUTH_H
#define AUTH_H

#include <iostream>
#include <string>

using namespace std;


class Auth
{

public:

    static bool registerUser(string username, string password);

    static bool loginUser(string username, string password);

};


#endif