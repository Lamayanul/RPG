#include "Stocare.h"
#include <fstream>

Stocare::Stocare()
    {
        numeJucator = "";
    }

void Stocare::setNumeJucator(string nume)
    {
        numeJucator = nume;
    }
string Stocare:: getNumeJucator()
    {
        return numeJucator;
    }
void Stocare::salvarePoveste(string poveste)
    {
        ofstream fisier("poveste.txt",std::ios::app);
        fisier<<poveste;
        fisier.close();
    }
