#ifndef INVENTAR_H_INCLUDED
#define INVENTAR_H_INCLUDED
#include<iostream>
#include<string>
#include "Character.h"
#include "MyAvatar.h"
extern int bani;
using namespace std;
class Inventar
{
    public:
    list<int> portiune_viata = {1,2,4};
    list<int> portiune_mana={2,2,2};
    int numar_arme=1;
    MyAvatar &avatar;

    Inventar(MyAvatar &a) : avatar(a){}
    list<int> getViata();

    list<int> getMana();

    string verifica_stare();


    int aplica_viata();
    int aplica_mana();

};



#endif // INVENTAR_H_INCLUDED
