#include <iostream>
#include "UserDetails.h"
#include "User.h"

using namespace std;
#ifndef USERMANAGEMENT_H
    #define USERMANAGEMENT_H

//This class uses only dynamic memory allocation to intialize an array of users,
//,b : Which is not good if you want to scale up our application
class UserManagement{
    private :

        User *users;
        UserDetails userDetails;
        size_t usersNumber;
    public :
        UserManagement();
        ~UserManagement();
        User addUser(User user);
        User deleteUser(User user);
        User getRandomUser();//Not in the class attributs
        bool setNewPassword(string username, string oldPassword, string newPassword);
        bool setNewUsername(User user,string username, string password);
        User login(string username, string password);
        User logout(string username);
        string printAllUsers();

};

#endif // USERMANAGEMENT
