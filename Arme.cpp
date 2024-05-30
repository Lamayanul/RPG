#include "Arme.h"

void Arme::info()
    {
        cout << "Arma_initiala: " << arma_initiala << endl;
        cout << "Raritate: " << raritate << endl;
        cout << "Attack: " << attack << endl;
        cout << "Defensiva: " << defense << endl;
        cout << "Nivel_arma: " <<nivel_arma <<endl;
    }
void Arme::schimbaArma(string a, string r, int att, int d, int n)
    {
        arma_initiala = a;
        raritate = r;
        attack = att;
        defense = d;
        nivel_arma = n;
    }
int Arme::getAttack()
    {
        return attack;
    }
