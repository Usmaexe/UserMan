#include <iostream>
#include <string>
#include <cctype>
#include <time.h>

using namespace std;

#ifndef USERDETAILS_H
    #define USERDETAILS_H

    class UserDetails{
        public :
            string encryptPassword(string password, int key);
            string decryptPassword(string cryptedPassword, int key);
    };

#endif // UserDetails
