#include<list>
#include "Character.h"
#include "Inventar.h"


    list<int>Inventar:: getViata()
    {
        return portiune_viata;
    }
    list<int>Inventar:: getMana()
    {
        return portiune_mana;
    }
    string Inventar::verifica_stare()
    {
        string stare;
        stare+="Bani: " + to_string(bani)+"\n";
        stare += "Viata: " + to_string(avatar.getHealth()) + "\n";
        stare += "Mana: " + to_string(avatar.getMana()) + "\n";
        cout<<"Detalii arma:\n ";
        avatar.getArma().info();

        stare += "Numar de portiuni de viata: \n";
        for (int viata : portiune_viata)
        {
            stare += to_string(viata) + " ";
        }
        stare += "\n";

        stare += "Numar de portiuni de mana: \n";
        for (int mana : portiune_mana)
        {
            stare += to_string(mana) + " ";
        }
        return stare;
    }

    int Inventar:: aplica_viata()
    {
    for (int numar : portiune_viata) {
        cout << numar << " ";
    }
    cout<<"\nCare portiune vrei sa o folosesti? \n";
    int raspuns3;
    cin>>raspuns3;
    auto it = portiune_viata.begin();
    advance(it, raspuns3-1);
    int viataInventar = *it;
    int& viataAvatar = avatar.getHealth();
    int viataNoua = viataAvatar + viataInventar;
    avatar.getHealth() = viataNoua;
    portiune_viata.erase(it);
    return avatar.getHealth();
    }

    int Inventar:: aplica_mana()
    {
    for (int numar : portiune_mana) {
          cout << numar << " ";
    }
    cout<<"\nCare portiune vrei sa o folosesti? \n";
    int raspuns4;
    cin>>raspuns4;
    auto it = portiune_mana.begin();
    advance(it, raspuns4-1);
    int ManaInventar = *it;
    int& ManaAvatar = avatar.getMana();
    int ManaNoua = ManaAvatar + ManaInventar;
    avatar.getMana() = ManaNoua;
    portiune_mana.erase(it);
    return avatar.getMana();
    }

