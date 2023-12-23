#include "UserDetails.h"

string UserDetails::encryptPassword(string password,int key){
    string encPass;int letter;int notLetter;char current;
    key %= 26;
    for(unsigned int i = 0 ; i < password.length() ; i++){
        //Iterating over each letter
        current = password.at(i);
        //Verifing if its an upper letter or lower
        //condition for uper-case characters
        if(isupper(current)){
            //Then if the letter excedes out of the range its up to this condition
            //To start from the first letter and do addtion
            if((int)current+key>90){
                letter = ((int)'A'+((int)current+key)-((int)'Z'))-1;
                encPass.append(1,(char)letter);
                continue;
            }
            //Once the condtion is verified the loop is breaked and it moves to the next iteration
        }
        //Same condtion but for lower_case characters
        else if(islower(current)){

            if((int)current+key>122){
                letter = ((int)'a'+((int)current+key)-((int)'z'))-1;
                encPass.append(1,(char)letter);
                continue;
            }
        }
        //Letters within the range, other symboles

        notLetter = (int)current + key;
        encPass.append(1,(char)notLetter);
    }
    return encPass;
}

string UserDetails::decryptPassword(string cryptedPassword,int key){
    string decPass;int letter;int notLetter;char current;
    key %= 26;
    for(unsigned int i = 0 ; i < cryptedPassword.length() ; i++){
        //Iterating over each letter
        current = cryptedPassword.at(i);
        //Verifing if its an upper letter or lower
        //condition for uper-case characters
        if(isupper(current)){

            if((int)current-key<65){
                letter = ((int)current-key)+26;
                decPass.append(1,(char)letter);
                continue;
            }
            //Once the condtion is verified the loop is breaked and it moves to the next iteration
        }
        //Same condtion but for lower_case characters
        else if(islower(current)){

            if((int)current-key<97){
                letter = ((int)current-key)+26;
                decPass.append(1,(char)letter);
                continue;
            }
        }
        //Letters within the range, other symboles
        notLetter = (int)current - key;
        decPass.append(1,(char)notLetter);
    }
    return decPass;
}
