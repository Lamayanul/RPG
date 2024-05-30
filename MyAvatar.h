#ifndef MYAVATAR_H_INCLUDED
#define MYAVATAR_H_INCLUDED
#include "Character.h"
class MyAvatar: public Character {
public:
    MyAvatar(const Character &character) : Character(character) {}
    void info() ;
    void schimbaArma(Arme a);
    bool isAlive();
    int evita(int speed);
    Arme getArma();

    int& getHealth();

    int& getMana();

    int& getSpeed();

    int& getNivel();

    int& getStrength();

};

#endif // MYAVATAR_H_INCLUDED
