#include <iostream>

using namespace std;

class Hero{
private :
    long id, id_opp;
    string HeroicName;
    //HP : Health Points, MP : Magical Points
    int HP, MP;

public:
    void swordAttack(int damage);
    void fireBulletAttack(int damage);
    void shieldDefence(int damage);
    void takeDamage(int damage);
    string printHeroState();
};
