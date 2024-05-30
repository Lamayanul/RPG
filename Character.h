#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include<iostream>
#include<string>
#include "Arme.h"
using namespace std;
class Character {
protected:
    int health;
    int mana;
    int strength;
    int speed;
    int nivel;
    Arme arma;
public:
    Character(string w, int h, int m, int s, int ss,int n,Arme a) : health(h), mana(m), strength(s), speed(ss),nivel(n),arma(a) {}

    void info();
    int& getHealth();

    int& getMana();

    int& getSpeed();

    int& getNivel();

    int& getStrength();


};



#endif // CHARACTER_H_INCLUDED
