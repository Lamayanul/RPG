#ifndef MONSTRU_H_INCLUDED
#define MONSTRU_H_INCLUDED
#include<iostream>
#include<string>
using namespace std;
class Monstru
{
    protected:
    string nume;
    int health;
    int mana;
    int strength;
    int speed;
    int nivel;
    Arme arma;

public:
    Monstru(string nu, int h, int m, int s, int ss,int n,Arme a) :nume(nu), health(h), mana(m), strength(s), speed(ss),nivel(n),arma(a) {}

    void info();

    int evita(int speed);

    bool isAlive();

    Arme getArma() ;

    int& getHealth();

    int& getMana();

    int& getSpeed();

    int& getNivel();

};


#endif // MONSTRU_H_INCLUDED
