#include <iostream>
#include <string.h>
using namespace std;

#ifndef USER_H
    #define USER_H

class User{
    private :
        string username;
        string password;
        string firstName;
        string lastName;
        string email;
        string address;
        string session;

    public :
        //Constructor
        User();
        User(string username,string password, string firstName, string lastName, string email, string adress, string session);

        string getHiddenEmail();
        string getEmail();
        string getUserName();//Not in the class attributs
        string getSession();//Not in the class attributs
        void setPassword(string password);
        void setUserName(string username);//Not in the class attributs
        void setEmail(string email);//Not in the class attributs
        void setSession(string email);//Not in the class attributs
        string getPassword();
        string printUserDetails();
        void exist();
        //Deconstructor
        //its used if we are allocating dynamic memory, in this case it will not be defined
        //~User();

};

#endif // User
