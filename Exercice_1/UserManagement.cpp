#include "UserManagement.h"
#include "UserDetails.h"

///CONSTRUCTOR
UserManagement::UserManagement(){
    this->users = new User[200];
    this->usersNumber=0;
}

///Add New User
User UserManagement::addUser(User user){
    string email,username;
    ///NOTE : THIS CAN BE WRAPED INTO A FUNCTION
    for(unsigned int  i = 0 ; i < this->usersNumber ; i++){
        if(this->users[i].getEmail()==user.getEmail()||this->users[i].getUserName()==user.getUserName()){
                cout<<"Invalid Email Or Username."<<endl;
                do{
                    cout<<"Email : ";
                    cin>>email;
                    cout<<"Username : ";
                    cin>>username;
                }while(this->users[i].getEmail()==email||this->users[i].getUserName()==username);
                user.setUserName(username);
                user.setEmail(email);
                //If the user entered a values of username or email that exist in the next iteration
                //it will be detected by the condition above and it will be demanded to enter new values
        }
    }
    //Adding the new user and incrementing the number of users
    this->users[usersNumber] = user;
    usersNumber++;
    cout<<endl;
    return user;
}

void ordering(int pos,size_t len,User *users){
    for(unsigned int i = pos ; i < len-1 ; i++){
        users[i] = users[i+1];
    }
}
///DELETE A SPECIFIED USER
User UserManagement::deleteUser(User user){
    for(unsigned int i = 0 ; i < this->usersNumber ; i++){
        if(this->users[i].getUserName()==user.getUserName()){
            //function to delete a user from the dynamic array 'users'
            ordering(i,this->usersNumber,this->users);
            this->usersNumber--;
            break;
        }
    }
    return user;
}

///SETTER FOR A NEW PASSWORD
bool UserManagement::setNewPassword(string username, string oldPassword, string newPassword){
    for(unsigned int i = 0 ; i < this->usersNumber; i++){
        if(this->users[i].getUserName()==username){
            //Old password should be matched otherwise the function returns false
            if(this->users[i].getPassword()==oldPassword){
                this->users[i].setPassword(newPassword);
                cout<<endl<<"Password was updated succefully"<<endl<<endl;
                return true;
            }
        }
    }
    return false;

}

///SETTER FOR A NEW USERNAME
bool UserManagement::setNewUsername(User user,string username,string password){
    int userIndex = -1;
    if(password==user.getPassword()){
        for(unsigned int  i = 0 ; i < this->usersNumber ; i++){
            if(this->users[i].getUserName()==username){
                    cout<<"Invalid Username."<<endl;
                    do{
                        cout<<"Username : ";
                        cin>>username;
                    }while(this->users[i].getUserName()==username);
            }
            if(user.getUserName()==this->users[i].getUserName()){
                userIndex = i;
            }

        }
        //catching error when index is out of range
        this->users[userIndex].setUserName(username);
        user.setUserName(username);
        cout<<endl<<"Username was updated succefully"<<endl<<endl;
        return true;
    }


    return false;

}

///GET A RANDOM USER
User UserManagement::getRandomUser(){
    srand(time(0));
    int randomIndex = rand()%this->usersNumber;
    return this->users[randomIndex];
}

///LOGIN AND LOGOUT
User UserManagement::login(string username, string password){
    for (unsigned int i = 0 ; i < this->usersNumber ; i++){
        //testing Lines
        //cout<<"What is all this about : "<<username<<" "<<password<<endl;
        if(this->users[i].getUserName()==username&&this->users[i].getPassword()==password){
            this->users[i].setSession("OPEN");
            return this->users[i];
        }
    }
    cout<<"Username or password invalid !"<<endl;
    return this->users[199];
}

User UserManagement::logout(string username){
    for (unsigned int i = 0 ; i < this->usersNumber ; i++){
        //testing Lines
        //cout<<"What is all this about : "<<username<<" "<<password<<endl;
        if(this->users[i].getUserName()==username){
            this->users[i].setSession("CLOSED");
            return this->users[i];
        }
    }
    cout<<"Username or password invalid !"<<endl;
    return this->users[199];
}

///PRINT ALL USERS[]
string UserManagement::printAllUsers(){
    string usersInfo;
    for(unsigned int  i = 0 ; i < this->usersNumber ; i++){
        usersInfo += this->users[i].printUserDetails()+"\n\n";
    }
    return usersInfo;
}
///DECONSTRUCTOR
UserManagement::~UserManagement(){
    delete[] this->users;
}
