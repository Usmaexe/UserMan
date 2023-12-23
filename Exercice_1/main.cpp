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

    srand(time(0));
    key = rand()%10;//random value between 0 and 10
    UserDetails details;
    User mohamed("username",details.encryptPassword("Olympiade14Inpt@/;@",key),"Mimit","Anou", "miitos@gmail.com","Iallaten-Nador","active");
    /*
    cout<<"Email :" << mohamed.getHiddenEmail()<<endl<<endl;
    cout<<"Current Password : \n" << mohamed.getPassword()<<endl;

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
    mohamed.setPassword(details.encryptPassword(password,key));
    key=29;
    cout<<details.encryptPassword("sud",key)<<endl;
    cout<<"\n\nYour Updated Password is : " << details.decryptPassword(details.encryptPassword("suxqaAZzaxwd",key),key)<<endl<<endl;
    system("pause");
    cout<<endl;
    */
    cout<<"----Users List----\n" << mohamed.printUserDetails()<<endl<<endl;
    system("pause");
    cout<<endl;

    ///Users's Management and a testing user are created :
    UserManagement userManagement;
    User test("username",details.encryptPassword("Olympiade14Inpt@/;@",key),"Mimit","Anou", "miitos@gmail.com","Iallaten-Nador","active");


    ///ADDING AND DELETING A TEST USER
    mohamed = userManagement.addUser(mohamed);
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
        cout<<mohamed.getUserName()<<"["<<mohamed.getEmail()<<"] Enter :"<<endl<<"Old Password : ";
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
    }while(!userManagement.setNewPassword(mohamed.getUserName(),oldPassword,newPassword));
    //mohamed.setPassword(newPassword);
    //the mohamed user in the list(users) of userManagment is updated,
    //But the object mohamed is not
    cout<<"----Users List After Updating mohamed's password----\n"<<userManagement.printAllUsers()<<endl;


    ///UPDATING THE USERNAME FOR A SPECIFIED USER
    cout<<"Change the username for user["<< mohamed.getEmail() <<"]"<<endl;
    do{
        cout<<"Enter Password : ";
        cin >> password;
        password = details.encryptPassword(password,key);
        cout<<password<<endl;
    }while(!userManagement.setNewUsername(userManagement.getRandomUser(),"issem jadidd",password));


    cout<<endl;
    system("pause");
    return 0;
}
