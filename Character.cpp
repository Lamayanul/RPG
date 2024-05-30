#include "Character.h"
void Character::info()
    {
        cout << "Viata: " << health << endl;
        cout << "Mana: " << mana << endl;
        cout << "Puterea: " << strength << endl;
        cout << "Viteza: " << speed << endl;
        cout << "Nivel: " <<nivel <<endl;


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
int& Character::getStrength()
{
    return strength;
}
