#include "MyAvatar.h"
#include "Character.h"
#include "Arme.h"
    void MyAvatar::info()
    {
        Character::info();
    }

    int MyAvatar::evita(int speed)
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

    void MyAvatar::schimbaArma(Arme a)
    {
        arma = a;
    }
    bool MyAvatar::isAlive()
    {
        return health>0;

    }
    Arme MyAvatar::getArma()
    {
        return arma;
    }
    int& MyAvatar::getHealth()
    {
        return health;
    }
    int& MyAvatar::getMana()
    {
        return mana;
    }
    int& MyAvatar::getSpeed()
    {
        return speed;
    }
    int& MyAvatar::getNivel()
    {
        return nivel;
    }



