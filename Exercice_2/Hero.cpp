#include "Hero.h"

void Hero::swordAttack(int damage){
    //Diminish the hp of the hero by 5%
    this->takeDamage(damage);
}

void Hero::fireBulletAttack(int damage){

    this->HP-=2*damage;
}

void Hero::shieldDefence(int damage){
    this->HP-=0.2*damage;

}

void Hero::takeDamage(int damage){
    this->HP-=damage;
}


string Hero::printHeroState(){
    return "Hero " + std::to_string(this->id) + ":\nName : " + this->HeroicName + "\nHP : " + std::to_string(this->HP) + "\nMP : " + std::to_string(this->MP);
}
