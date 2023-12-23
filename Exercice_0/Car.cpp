#include <iostream>
#include "Car.h"

Car::Car(string brand, int year, string lsnb){
    this->brand = brand;
    this->year = year;
    this->licenseNumb = lsnb;
}
//This is just an example to test if the code that was written is correct or not
string Car::moveForward(){
    return "Go Digital with " + this->brand;
}
