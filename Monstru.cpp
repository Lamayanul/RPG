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
    int Monstru::evita(int speed)
    {
         float sansa = 0.0;
         if (speed >= 100)
         {
             sansa = 100.0;
         }
         else
         {
             sansa = speed / 4.0;
         }


    return (sansa < 100.0) ? sansa : 100.0;
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
