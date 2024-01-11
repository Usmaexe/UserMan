#include <iostream>

using namespace std;

class Monster {
private :
    long id, id_opp;
    string monstrousName,type;
    int HP, MP;

public :
    void fangAttack(int damage);
    void roarAttack(int damage);
    void skinDefence(int damage);
    void takeDamage(int damage);
    string printMonsterState();
};
