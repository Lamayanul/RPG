#include "Arme.h"

void Arme::info()
    {
        cout << "arma_initiala: " << arma_initiala << endl;
        cout << "raritate: " << raritate << endl;
        cout << "attack: " << attack << endl;
        cout << "defense: " << defense << endl;
        cout << "nivel_arma: " <<nivel_arma <<endl;
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
