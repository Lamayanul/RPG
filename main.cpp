#include <iostream>
#include <fstream>
#include <list>
#include <cstdlib>
#include "Stocare.h"
#include "Arme.h"
#include "Monstru.h"
#include "Reguli.h"
#include "Character.h"
#include "Inventar.h"
#include "MyAvatar.h"
using namespace std;









int bani = 50;



class Market
{
    int pvmica=20;
    int pvmare=40;
    int pmmica=20;
    int pmmare=40;
    Inventar& inv;
    list<int> pv={50,100,50};
    list<int> pm={100,50,100};


    public :Market(Inventar &a):inv(a){}

    int Cumpara()
    {

        string raspuns5;
        cout<<"Vrei sa cumperi portiune viata? \n";
        cin>>raspuns5;
        if(raspuns5 == "y")
        {
            for(int numar : pv)
            {
                cout << numar << " ";
            }
            cout<<"Care o cumperi? \n";
            int raspuns6;
            cin>>raspuns6;
            auto it = pv.begin();
            advance(it, raspuns6-1);
            int opt=*it;
            if(opt == 50)
            {

                if(bani<pvmica)
                {
                    cout<<"Nu ai bani suficienti!\n";
                }
                else
                {
                   bani=bani-pvmica;
                   inv.portiune_viata.push_back(opt);
                }
            }
            else
            {
                if(bani<pvmare)
                {
                    cout<<"Nu ai bani suficienti!\n";
                }
                else
                {
                   bani=bani-pvmare;
                   inv.portiune_viata.push_back(opt);
                }
            }

        }
        else if(raspuns5 == "n")
        {
            cout<<"Vrei portiune de mana? \n";
            string raspuns7;
            cin>>raspuns7;
            if(raspuns7=="y")
            {
            for(int numar : pm)
            {
                cout << numar << " ";
            }
            cout<<"Care o cumperi? \n";
            int raspuns6;
            cin>>raspuns6;
            auto it = pm.begin();
            advance(it, raspuns6-1);
            int opt=*it;
            if(opt == 50)
            {

                if(bani<pmmica)
                {
                    cout<<"Nu ai bani suficienti!\n";
                }
                else
                {
                   bani=bani-pmmica;
                   inv.portiune_mana.push_back(opt);
                }
            }
            else
            {
                if(bani<pmmare)
                {
                    cout<<"Nu ai bani suficienti!\n";
                }
                else
                {
                   bani=bani-pmmare;
                   inv.portiune_mana.push_back(opt);
                }
              }
           }
        }
        else if(raspuns5 =="n")
        {
            cout<<"Nu vreau nimic\n";
        }
    }

};
class gameplay
    {

    Inventar inv;
    MyAvatar avatar;
    Monstru monstru;
    public:
        gameplay(Inventar& inventar,MyAvatar& _avatar,Monstru& _monstru) : inv(inventar),avatar(_avatar),monstru(_monstru) {}
        void rundaLuptei() {
        bool randulAvatarului = true;

        while (avatar.isAlive() && monstru.isAlive())
            {
            int random = rand() % 100 + 1;
            int random1 = rand() % 100 + 1;
            if (randulAvatarului)
            {
                cout<<"-------------\n";
                cout<<"Stat-uri monstru: \n";
                cout<<"-------------\n";
                monstru.info();
                getchar();
                if(monstru.evita(monstru.getSpeed())<=random1)
                {
                monstru.getHealth()=monstru.getHealth()-monstru.getArma().getAttack();
                }
                else
                {
                cout<<"Monstrul a evitat atacul.\n";
                }
            }
            else
            {
                cout<<"-------------\n";
                cout<<"Stat-uri erou: \n";
                cout<<"-------------\n";
                avatar.info();
                getchar();
                if(avatar.evita(avatar.getSpeed())<=random)
                {
                avatar.getHealth()-=monstru.getArma().getAttack();
                }
                else
                {
                cout<<"Eroul a evitat atacul.\n";
                }
                cout<<"Deschizi inventarul?";
            string raspuns;
            cin>>raspuns;
            if(raspuns=="y")
            {
                {
                bool exit=false;
                while(!exit)
                {
                    cout<<"1.Afiseaza parametrii jucator\n";
                    cout<<"2.Foloseste portiuni de viata\n";
                    cout<<"3.Foloseste portiuni de mana\n";
                    int optiune2;
                    cin>>optiune2;
                    string raspuns2;
                    switch(optiune2)
                    {
                    case 1:
                        {
                            cout<<inv.verifica_stare();
                            cout<<"\nnInchideti inventarul?";
                            cin>>raspuns2;
                            if(raspuns2=="y")
                                exit=true;
                            break;
                        }
                    case 2:
                        {
                            inv.aplica_viata();
                            cout<<"\nInchideti inventarul?";
                            cin>>raspuns2;
                            if(raspuns2=="y")
                                exit=true;
                            break;
                        }
                    case 3:
                        {
                            inv.aplica_mana();
                            cout<<"\nInchideti inventarul?";
                            cin>>raspuns2;
                            if(raspuns2=="y")
                                exit=true;
                            break;
                      }
                    }
                  }
                }
            }

            }


            if (!monstru.isAlive()) {
                cout << "Monstrul a fost invins!" << endl;
                break;
            } else if (!avatar.isAlive()) {
                cout << "Avatarul a fost invins!" << endl;
                break;

            }

            randulAvatarului = !randulAvatarului;

            getchar();
        }
    }
};

int main() {
    Stocare stocare;
    Reguli regula;
    bool erouSelectat = false;
    string poveste;
    MyAvatar myAvatar(Character("", 0, 0, 0, 0,0, Arme("", "", 0, 0, 0)));
    cout<<"*******************************************************************************************\n";
    cout << "Bine ai venit in lumea jocului de rol!\n";

    regula.info();
    cout<<"*******************************************************************************************\n";
    cout <<"Introdu un nume: ";
    string nume;
    cin >> nume;
    stocare.setNumeJucator(nume);

    Inventar inventar(myAvatar);
    while(!erouSelectat)
    {
        cout<<"---------------------------------------------------------------------------------------\n";
        cout<<"Alege avatar: \n";
        cout<<"1. Warrior \n";
        cout<<"2. Archer \n";
        cout<<"3. Wizard \n";
        cout<<"4. Inventar\n";
        cout<<"----------------------------------------------------------------------------------------\n";
        int optiune;
        string raspuns;
        cin >> optiune;

        switch(optiune) {
            case 1: {
                Character warrior("warrior", 100, 20, 70, 40,1,Arme("sabie", "comun", 20, 0, 1));
                warrior.info();
                cout<<"Selectezi acest character? (y/n)";
                string raspuns;
                cin >> raspuns;
                if(raspuns == "y") {
                     myAvatar=MyAvatar(warrior);
                     erouSelectat = true;
                }
                break;
            }
            case 2: {
                Character archer("archer", 100, 50, 60, 60,1,Arme("sabie", "comun", 20, 0, 1));
                archer.info();
                cout<<"Selectezi acest character? (y/n)";
                string raspuns;
                cin >> raspuns;
                if(raspuns == "y") {
                     myAvatar=MyAvatar(archer);
                     erouSelectat = true;
                }
                break;
            }
            case 3: {
                Character wizard("wizard", 100, 90, 30, 40,1,Arme("toiag", "comun", 30, 1, 1));

                wizard.info();
                cout<<"Selectezi acest character? (y/n)";
                string raspuns;
                cin >> raspuns;
                if(raspuns == "y") {
                     myAvatar=MyAvatar(wizard);
                     erouSelectat = true;
                }
                break;
            }
            case 4:
                {
                bool exit=false;
                while(!exit)
                {
                    cout<<"1.Afiseaza parametrii jucator\n";
                    cout<<"2.Foloseste portiuni de viata\n";
                    cout<<"3.Foloseste portiuni de mana\n";

                    cin>>optiune;
                    string raspuns2;
                    switch(optiune)
                    {
                    case 1:
                        {
                            inventar.verifica_stare();
                            cout<<"Inchideti inventarul?";
                            cin>>raspuns2;
                            if(raspuns2=="y")
                                exit=true;
                            break;
                        }
                    case 2:
                        {
                            inventar.aplica_viata();
                            cout<<"Inchideti inventarul?";
                            cin>>raspuns2;
                            if(raspuns2=="y")
                                exit=true;
                            break;
                        }
                    case 3:
                        {
                            inventar.aplica_mana();
                            cout<<"Inchideti inventarul?";
                            cin>>raspuns2;
                            if(raspuns2=="y")
                                exit=true;
                            break;
                        }
                    }
                }
            }
        }
    }
        myAvatar.info();
        printf("Bugetul initial este de %d: de bani\n",bani);
        Arme sabie("sabie","comun",20,0,1);
        Arme arc("arc","comun",30,1,1);
        Arme toiag("toiag","comun",30,1,1);
        cout<<"Arma noua gasita. O luati?";
        Arme secera("secera","uncomon",24,0,2);
        string raspuns;
        cin>>raspuns;
        if(raspuns=="y")
        {
            myAvatar.schimbaArma(secera);
            secera.info();
        }
        bool sigur = false;
        while(!sigur)
        {
        int optiune1;
        cout<<"Alege ruta care-ti place: \n";
        cout<<"1. Padure \n";
        cout<<"2. Drum laturalnic \n";
        cout<<"3. Inventar\n";
        cin>>optiune1;
        switch(optiune1)
        {
        case 1:
            {
                cout<<"Padure\n";
                cout<<"Selectezi pudurea? ";
                string raspuns;
                cin>>raspuns;
               if(raspuns=="y")
                {
                poveste = "A aparut un monstru\n";
                cout<<poveste;
                stocare.salvarePoveste(poveste);
                Monstru monstru("orc",90,0,15,10,2,Arme("secure","comun",15,1,1));
                gameplay primaRunda(inventar,myAvatar,monstru);
                primaRunda.rundaLuptei();
                }

                break;
            }
        case 2:
            {
                poveste = "Drum laturalnic\n";
                stocare.salvarePoveste(poveste);
                cout<<poveste;
                cout<<"Selectezi drum laturalnic?\n ";
                bool exit=false;
                string raspuns;
                cin>>raspuns;
                if(raspuns == "y")
                {
                    cout<<"Se vede in departare un market... \n";
                while(!exit)
                {


                /*if(raspuns=="y")
                {
                    sigur=true;
                }*/
                Market marc(inventar);

                marc.Cumpara();
                cout<<"Vrei sa iesi din magazin?\n";
                cin>>raspuns;
                if(raspuns=="y")
                    exit=true;
                }
                }

                break;
            }
            case 3:
                {
                bool exit=false;
                while(!exit)
                {
                    cout<<"1.Afiseaza parametrii jucator\n";
                    cout<<"2.Foloseste portiuni de viata\n";
                    cout<<"3.Foloseste portiuni de mana\n";
                    int optiune2;
                    cin>>optiune2;
                    string raspuns2;
                    switch(optiune2)
                    {
                    case 1:
                        {
                            cout<<inventar.verifica_stare();
                            cout<<"Inchideti inventarul?";
                            cin>>raspuns2;
                            if(raspuns2=="y")
                                exit=true;
                            break;
                        }
                    case 2:
                        {
                            inventar.aplica_viata();
                            cout<<"Inchideti inventarul?";
                            cin>>raspuns2;
                            if(raspuns2=="y")
                                exit=true;
                            break;
                        }
                    case 3:
                        {
                            inventar.aplica_mana();
                            cout<<"Inchideti inventarul?";
                            cin>>raspuns2;
                            if(raspuns2=="y")
                                exit=true;
                            break;
                      }

                    }
                  }
                }
              }
              cout<<"Te-a prins Ana!";
            }
          }



