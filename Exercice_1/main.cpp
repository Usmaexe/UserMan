#include <iostream>
#include "UserDetails.h"
#include "UserManagement.h"
#include "User.h"

///COPY PASTE SECTION :
#ifdef WIN32
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

void SetStdinEcho (bool enable = true)
{
#ifdef WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);

    if( !enable )
        mode &= ~ENABLE_ECHO_INPUT;
    else
        mode |= ENABLE_ECHO_INPUT;

    SetConsoleMode(hStdin, mode );

#else
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if( !enable )
        tty.c_lflag &= ~ECHO;
    else
        tty.c_lflag |= ECHO;

    (void) tcsetattr(STDIN_FILENO, TCSANOW, &tty);
#endif
}

int main()
{

    ///FIRST CLASS
    //Creation of Variables and Objects
    string password,cfpassword,oldPassword,newPassword,newPasswordRep;int key;
    string newUsername;//used for username Update

    srand(time(0));
    key = rand()%10;//random value between 0 and 10
    UserDetails details;
    ///ALL THE METHODS ARE APPLIED TO THIS USER OBJECT CALLED MOHAMED
    User mainUser("username",details.encryptPassword("Olympiade14Inpt@/;@",key),"Mimit","Anou", "miitos@gmail.com","Iallaten-Nador","active");

    cout<<"Email :" << mainUser.getHiddenEmail()<<endl<<endl;
    cout<<"Current Password : \n" << mainUser.getPassword()<<endl;

    do{
        cout<<"\nEnter New Password : ";
        SetStdinEcho(false);
        cin>>password;
        SetStdinEcho(true);
        cout<<"\nConfirm New Password : ";
        SetStdinEcho(true);
        SetStdinEcho(false);
        cin>>cfpassword;

    }while(password!=cfpassword);

    //Here the UserDetails's function (encrypt password) is used to make sure that the password will be encrypted
    mainUser.setPassword(details.encryptPassword(password,key));

    cout<<"\n\nYour Updated Password is : " << details.decryptPassword(details.encryptPassword("suxqaAZzaxwd",key),key)<<endl<<endl;
    system("pause");
    cout<<endl;

    cout<<"----Users List----\n" << mainUser.printUserDetails()<<endl<<endl;
    system("pause");
    cout<<endl;


    ///Users's Management and a testing user are created :
    UserManagement userManagement;

    //test is created with the same username to test the adding method when entering already existing data
    User test("username",details.encryptPassword("Olympiade14Inpt@/;@",key),"Mimit","Anou", "miitos@gmail.com","Iallaten-Nador","active");


    ///ADDING AND DELETING A TEST USER
    mainUser = userManagement.addUser(mainUser);
    test = userManagement.addUser(test);
    cout<<"----Users List After Adding the test user----\n"<<userManagement.printAllUsers()<<endl;
    userManagement.deleteUser(test);
    cout<<"----Users List After Deleting the test user----\n"<<userManagement.printAllUsers()<<endl;

    ///UPDATING THE PASSWORD for the user mohamed
    unsigned int t=0;
    do{
        if(t!=0){
            cout<<"\nError in updating your password ! Try again."<<endl<<endl;
        }
        cout<<mainUser.getUserName()<<"["<<mainUser.getEmail()<<"] Enter :"<<endl<<"Old Password : ";
        cin>>oldPassword;
        oldPassword = details.encryptPassword(oldPassword,key);
        do{
            cout<<"New Password : ";
            cin>>newPassword;
            cout<<"Confirm New Password : ";
            cin>>newPasswordRep;
        }while(newPassword!=newPasswordRep);
        newPassword = details.encryptPassword(newPassword,key);
        t++;
    }while(!userManagement.setNewPassword(mainUser.getUserName(),oldPassword,newPassword));
    cout<<"----Users List After Updating main user's password----\n"<<userManagement.printAllUsers()<<endl;


    ///UPDATING THE USERNAME FOR A SPECIFIED USER
    cout<<"Change the username for user["<< mainUser.getEmail() <<"]"<<endl;
    cout<<"Enter a new username : ";
    cin>>newUsername;
    do{
        cout<<"Enter Password : ";
        cin >> password;
        password = details.encryptPassword(password,key);
    }while(!userManagement.setNewUsername(userManagement.getRandomUser(),newUsername,password));
    //A random password is selected randomly to change its password
    cout<<"----Users List After Updating username for a random user----\n"<<userManagement.printAllUsers()<<endl;


    ///LOGIN AND LOGOUT
    mainUser = userManagement.login(newUsername,password);
    cout<<"----Users List After Opening the session for the main user ---\n"<<userManagement.printAllUsers()<<endl;
    mainUser = userManagement.logout(newUsername);
    cout<<"----Users List After Closing  the session for the main user ---\n"<<userManagement.printAllUsers()<<endl;

    cout<<endl;
    system("pause");
    return 0;
}
