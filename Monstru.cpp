#include "Stocare.h"
#include "Arme.h"
#include "Monstru.h"
void Monstru::info()
    {
        cout << "health: " << health << endl;
        cout << "mana: " << mana << endl;
        cout << "strength: " << strength << endl;
        cout << "speed: " << speed << endl;
        cout << "nivel: " <<nivel <<endl;
    }
bool Monstru::isAlive()
    {
        return health>0;
    }
Arme Monstru::getArma()
    {
        return arma;
    }
int& Monstru::getHealth()
    {
        return health;
    }
int& Monstru::getMana()
    {
        return mana;
    }
int& Monstru::getSpeed()
    {
        return speed;
    }
int& Monstru::getNivel()
    {
        return nivel;
    }
