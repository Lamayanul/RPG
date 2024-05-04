#include "MyAvatar.h"
#include "Character.h"
#include "Arme.h"
    void MyAvatar::info()
    {
        Character::info();
    }
    void MyAvatar::schimbaArma(Arme a) {
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



