#include <string>
#include<iostream>
#ifndef STOCARE_H_INCLUDED
#define STOCARE_H_INCLUDED
using namespace std;
class Stocare
{
    private:
    string numeJucator;
public:
    Stocare() ;
    void setNumeJucator(string nume) ;
    string getNumeJucator() ;
    void salvarePoveste(string poveste);
};

#endif // STOCARE_H_INCLUDED
