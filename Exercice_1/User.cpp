#include "User.h"

User::User(){
    this->username = "user.default";
    this->password = "123456789_Defau!t";
}

User::User(string username,string password, string firstName, string lastName, string email, string adress, string session){
    this->username = username;
    this->password = password;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->address = adress;
    this->session = session;
}


string User::getHiddenEmail(){
    //append function takes the number of occurence that second arg(char) should be repeated
    string em;
    em.append(1,((this->email).at(0)));
    for(unsigned int i = 1 ; i < (this->email).length() ; i++){//unsigned int cause length is of that type
        if(i<4||i>=this->email.length()-4){
            em+=(this->email).at(i);
        }
        else{
            em+="*";
        }
    }
    return em;
}

///GETTERS :
string User::getEmail(){
    return this->email;
}

string User::getUserName(){
    return this->username;
}

string User::getPassword(){
    return this->password;
}

///SETTERS :
void User::setPassword(string password){
    this->password = password;
}

void User::setUserName(string username){
    this->username=username;
}

void User::setEmail(string email){
    this->email=email;
}
string User::printUserDetails(){
    //string username,string password, string firstName, string lastName, string email, string adress, string session
    return "Username : "  + this->username + "\nPassword(crypted) : "  + this->getPassword() + "\nFirst name : "  + this->firstName + "\nLast Name : "  + this->lastName + "\nemail : "  + this->email + "\naddress : "  + this->address + "\nsession : "  + this->session;

}

void User::exist(){
    cout<<"I " + this->username + " exist"<<endl;
}
