#include <iostream>

using namespace std;

class Car{
    private :
        string brand;
        int year;
        string licenseNumb;
    public :
        Car(string brand,int year,string licenseNumb);
        string turnOn();
        string turnOff();
        string moveForward();
        string stop();
};
