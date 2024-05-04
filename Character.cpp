#include "Character.h"
void Character::info()
    {
        cout << "health: " << health << endl;
        cout << "mana: " << mana << endl;
        cout << "strength: " << strength << endl;
        cout << "speed: " << speed << endl;
        cout << "nivel: " <<nivel <<endl;


    }
int& Character::getHealth()
    {
        return health;
    }
int& Character::getMana()
    {
        return mana;
    }
int& Character::getSpeed()
    {
        return speed;
    }
int& Character::getNivel()
    {
        return nivel;
    }
