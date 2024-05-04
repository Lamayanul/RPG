#ifndef ARME_H_INCLUDED
#define ARME_H_INCLUDED
#include<iostream>
#include<string>
using namespace std;
class Arme
{
    string arma_initiala;
    string raritate;
    int attack;
    int defense;
    int nivel_arma;
public:
    Arme(string a,string r,int att, int d,int n) : arma_initiala(a),raritate(r),attack(att),defense(d),nivel_arma(n){};
    void info() ;
    void schimbaArma(string a, string r, int att, int d, int n) ;
    int getAttack();
};


#endif // ARME_H_INCLUDED
