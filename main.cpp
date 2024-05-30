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

class NumeInvalidException : public exception {
public:
    const char* what() const noexcept override {
        return "NouVenit";
    }
};

class Animale
{
    string tip;
    int marime;
public:
    Animale( string _tip, int _marime) : tip(_tip), marime(_marime) {}
     Animale operator+(const Animale& animal) {
        string tipNou = tip + " " + animal.tip;
        int marimeNoua = marime + animal.marime;
        return Animale( tipNou, marimeNoua);
    }

    Animale operator-(const Animale& animal) {
        string tipNou = tip;
        int marimeNoua = marime - animal.marime;
        return Animale(tipNou, marimeNoua);
    }

    bool operator==(const Animale& animal) const {
        return ( tip == animal.tip && marime == animal.marime);
    }

    bool operator<(const Animale& animal) const {
        return marime < animal.marime;
    }

    bool operator>(const Animale& animal) const {
        return marime > animal.marime;
    }

    friend ostream& operator<<(ostream& output, const Animale& animal) {
        output << "Tip: " << animal.tip << ", Marime: " << animal.marime;
        return output;
    }
};





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

    static int totalBaniCheltuiti;
    bool iesire= false;
public:
    Market(Inventar &a):inv(a){}

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
                   totalBaniCheltuiti += pvmica;
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
                   totalBaniCheltuiti += pvmare;
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
                   totalBaniCheltuiti += pmmica;
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
                   totalBaniCheltuiti += pmmare;
                }
              }
           }
          else if (raspuns7 == "n") {
                    cout << "Nu ai cumparat nimic.\n";
         }

        }

                return 0;


    }

};
class gameplay
    {

    Inventar inv;
    MyAvatar &avatar;
    Monstru monstru;
    int primaAbilitate=25;
    int douaAbilitate=50;
    int Speciala=100;
    int& mana= avatar.getMana();
    public:
        gameplay(Inventar& inventar,MyAvatar& _avatar,Monstru& _monstru) : inv(inventar),avatar(_avatar),monstru(_monstru) {}
        void rundaLuptei() {
        bool randulAvatarului = true;

        while (avatar.isAlive() && monstru.isAlive())
            {
            int random = rand() % 100 ;
            int random1 = rand() % 100  ;
            if (randulAvatarului)
            {
                cout<<"-------------\n";
                cout<<"Stat-uri monstru: \n";
                cout<<"-------------\n";
                monstru.info();
                getchar();
                if(monstru.evita(monstru.getSpeed())<=random1)
                       {


                            int optiune;
                            cout<<"1.Atac simplu\n";
                            cout<<"2.Atac puternic\n";
                            cout<<"3.Atac special\n";
                            cin>>optiune;
                            switch(optiune)
                            {
                                case 1:
                                {
                                     monstru.getHealth()=monstru.getHealth()-monstru.getArma().getAttack()/2;
                                     mana = mana+20;
                                }
                                break;
                                case 2:
                                     if(mana>=douaAbilitate)
                                      {
                                        monstru.getHealth()=monstru.getHealth()-monstru.getArma().getAttack();
                                        mana= mana- douaAbilitate;
                                       }
                                      else
                                       {
                                        cout<<"Nu e destula mana\n";
                                         }
                                      break;
                                case 3:
                                  {
                                     if(mana>=Speciala)
                                 {
                                       monstru.getHealth()=monstru.getHealth()-monstru.getArma().getAttack()*3;
                                       mana = mana - Speciala;
                                       }
                                       else
                                     {
                                      cout<<"Nu e destula mana\n";
                                    }
                                       break;
                                      }
                                   }

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
                exit(0);
                break;

            }

            randulAvatarului = !randulAvatarului;

            getchar();
        }

    }

};
 int Market::totalBaniCheltuiti = 0;

int main() {
    Stocare stocare;
    Reguli regula;
    bool erouSelectat = false;
    string poveste;
    MyAvatar myAvatar(Character("", 0, 0, 0, 0,0, Arme("", "", 0, 0, 0)));
    cout<<"*********************************************************************************************************************************************************\n";
    cout << "Bine ai venit in lumea jocului de rol!\n";

    regula.info();
    cout<<"*********************************************************************************************************************************************************\n";
    cout <<"Introdu un nume: ";
    string nume;

    try {
        getline(cin, nume);
        if (nume.empty()) {
            throw NumeInvalidException();

        }

        cout << "Numele introdus este: " << nume << endl;
        poveste = nume;
        stocare.salvarePoveste(poveste);
    } catch (const NumeInvalidException& e) {
        cerr << "Nume: " << e.what() << endl;
        poveste ="NouVenit\n";
        stocare.salvarePoveste(poveste);
        stocare.setNumeJucator("NouVenit\n");
    }
    stocare.setNumeJucator(nume);

    Inventar inventar(myAvatar);
    while(!erouSelectat)
    {
        cout<<"---------------------------------------------------------------------------------------\n";
        cout<<"Alege avatar: \n";
        cout<<"1. Cavaler \n";
        cout<<"2. Arcas \n";
        cout<<"3. Vrajitor \n";

        cout<<"----------------------------------------------------------------------------------------\n";
        int optiune;
        string raspuns;
        cin >> optiune;

        switch(optiune) {
            case 1: {
                Character warrior("cavaler", 100, 20, 70, 40,1,Arme("sabie", "comun", 20, 0, 1));
                warrior.info();
                cout<<"Selectezi acest character? (y/n)";
                string raspuns;
                cin >> raspuns;
                if(raspuns == "y") {
                     myAvatar=MyAvatar(warrior);
                     poveste = "cavaler\n";
                     stocare.salvarePoveste(poveste);
                     erouSelectat = true;
                }
                break;
            }
            case 2: {
                Character archer("arcas", 100, 50, 60, 60,1,Arme("sabie", "comun", 20, 0, 1));
                archer.info();
                cout<<"Selectezi acest character? (y/n)";
                string raspuns;
                cin >> raspuns;
                if(raspuns == "y") {
                     myAvatar=MyAvatar(archer);
                     poveste = "arcas\n";
                     stocare.salvarePoveste(poveste);
                     erouSelectat = true;
                }
                break;
            }
            case 3: {
                Character wizard("vrajitor", 100, 90, 30, 40,1,Arme("toiag", "comun", 30, 1, 1));

                wizard.info();
                cout<<"Selectezi acest character? (y/n)";
                string raspuns;
                cin >> raspuns;
                if(raspuns == "y") {
                     myAvatar=MyAvatar(wizard);
                     poveste = "vrajitor\n";
                     stocare.salvarePoveste(poveste);
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
                            cout<<"Inchideti inventarul?(y/n)";
                            cin>>raspuns2;
                            if(raspuns2=="y")
                                exit=true;
                            break;
                        }
                    case 2:
                        {
                            inventar.aplica_viata();
                            cout<<"Inchideti inventarul?(y/n)";
                            cin>>raspuns2;
                            if(raspuns2=="y")
                                exit=true;
                            break;
                        }
                    case 3:
                        {
                            inventar.aplica_mana();
                            cout<<"Inchideti inventarul?(y/n)";
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
        cout<<"Arma noua gasita. O luati?(y/n)";
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
                poveste ="Padure\n";
                cout<<poveste;
                stocare.salvarePoveste(poveste);
                poveste ="Selectezi padurea?(y/n)\n ";
                cout<<poveste;
                stocare.salvarePoveste(poveste);
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
                sigur=true;
                }
                if(raspuns == "n")
                {
                    poveste ="Vrei sa selectezi altceva?(y/n)";
                    cout<<poveste;
                    stocare.salvarePoveste(poveste);
                    cin>>raspuns;
                    if(raspuns == "y")
                    {
                poveste = "A aparut un monstru\n";
                cout<<poveste;
                stocare.salvarePoveste(poveste);
                Monstru monstru("orc",90,0,15,10,2,Arme("secure","comun",15,1,1));
                gameplay primaRunda(inventar,myAvatar,monstru);
                primaRunda.rundaLuptei();
                sigur=true;
                    }
                    else
                    {
                        sigur=true;
                    }
                }
                break;
            }
        case 2:
            {
                poveste = "Drum laturalnic\n";
                cout<<poveste;
                stocare.salvarePoveste(poveste);
                poveste = "Selectezi drum laturalnic?(y/n)\n ";
                cout<<poveste;
                stocare.salvarePoveste(poveste);
                bool exit=false;
                string raspuns;
                cin>>raspuns;
                if(raspuns == "y")
                {
                poveste ="Se vede in departare un market... \n";
                cout<<poveste;
                stocare.salvarePoveste(poveste);
                while(!exit)
                {
                Market marc(inventar);

                marc.Cumpara();
                poveste ="Vrei sa iesi din magazin?(y/n)\n";
                cout<<poveste;
                stocare.salvarePoveste(poveste);
                cin>>raspuns;
                if(raspuns=="y")
                    exit=true;
                }
                }
                if(raspuns == "n")
                {
                    poveste ="Vrei sa selectezi altceva?(y/n)\n";
                    cout<<poveste;
                    stocare.salvarePoveste(poveste);
                    cin>>raspuns;
                    if(raspuns == "y")
                    {
                poveste ="Se vede in departare un market... \n";
                cout<<poveste;
                stocare.salvarePoveste(poveste);
                while(!exit)
                {
                Market marc(inventar);

                marc.Cumpara();
                poveste ="Vrei sa iesi din magazin?(y/n)\n";
                cout<<poveste;
                stocare.salvarePoveste(poveste);
                cin>>raspuns;
                if(raspuns=="y")
                    exit=true;
                }
                    }
                    else
                    {
                        sigur=true;
                    }
                }
                sigur=true;
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
              poveste ="Pe drumul tau, observi o pestera ascunsa in spatele unei cascade. ";
              cout<<poveste;
              stocare.salvarePoveste(poveste);
              poveste ="Alegi sa intri?\n";
              cout<<poveste;
              stocare.salvarePoveste(poveste);
              string raspuns5;
              cin>>raspuns5;
              if(raspuns5=="y")
              {
                  poveste ="Ai intrat in pestera, iar din fata se aude un strigat puternic, inaintezi?(y/n)\n";
                  cout<<poveste;
                  stocare.salvarePoveste(poveste);
                  cin>>raspuns5;
                  if(raspuns5=="y")
                  {
                      poveste ="Dupa un timp scurt de mers, ai ajuns intr-o zona din pestera luminata, dar nu auzi sursa zgomotului.\n";
                      cout<<poveste;
                      stocare.salvarePoveste(poveste);
                      poveste ="Dar lumina se prelinge pe un cufar inchis, care nu pare de mult folosit. Pe o pancarta scrie ca este blestemat, il deschideti?\n";
                      cout<<poveste;
                      stocare.salvarePoveste(poveste);
                      cin>>raspuns5;
                      if(raspuns5=="y")
                      {
                          poveste ="Cufarul este incuiat, ai nevoie de strength = 30 ca sa il deschizi, deschideti?(y/n)\n";
                          cout<<poveste;
                          stocare.salvarePoveste(poveste);
                          cin>>raspuns5;
                          if(raspuns5=="y" && myAvatar.getStrength()>=30)
                          {
                              poveste ="Ai gasit 100 de banuti.\n";
                              cout<<poveste;
                              stocare.salvarePoveste(poveste);
                              bani = bani +100;
                          }
                          poveste ="Te-ai catarat pana sus la iesire, si observi ca ai ajuns pe acelasi drum.\n";
                          cout<<poveste;
                          stocare.salvarePoveste(poveste);
                      }
                  }
              }
              else
              {
                poveste ="Continua pe drum.\n";
                cout<<poveste;
                stocare.salvarePoveste(poveste);
              }


        }
        poveste ="Ai ajuns la o fantana magica, care se zice ca reface viata si mana oricum bea din ea.\n";
        cout<<poveste;
        stocare.salvarePoveste(poveste);
        poveste ="Fantana este pazita de un baiat care iti cere 20 de banuti ca sa o folosesti, accepti?(y/n)";
        cout<<poveste;
        stocare.salvarePoveste(poveste);
        string raspuns6;
        cin>>raspuns6;
        if(raspuns6=="y")
        {
            bani= bani-20;
            myAvatar.getHealth()=100;
            myAvatar.getMana()+100;
            cout <<"Ai ramas cu "<<bani<<"banuti\n";
            poveste = "Ai ramas cu banuti\n";
            stocare.salvarePoveste(poveste);
        }
        else
        {
            poveste ="Iti vezi de drum";
            cout<<poveste;
            stocare.salvarePoveste(poveste);
            poveste ="Te indepartezi tot mai mult de fantana";
            cout<<poveste;
            stocare.salvarePoveste(poveste);
            poveste ="Mergand, observi ca se innopteaza si pe drum dai de un han. Taxa pe noapte este de 30 de banuti. Langa han mai este un hambar, unde poti sta pe noapte, dar fara confort.";
            cout<<poveste;
            stocare.salvarePoveste(poveste);
            poveste ="Unde alegi sa stai pe noapte?\n";
            cout<<poveste;
            stocare.salvarePoveste(poveste);
            cout<<"1.Han\n";
            cout<<"2.Hambar\n";
            int optiune2;
            cin>>optiune2;
            switch(optiune2)
            {
            case 1:
                {
                poveste ="Ai ales hanul\n";
                cout<<poveste;
                stocare.salvarePoveste(poveste);
                bani = bani -30;
                myAvatar.getSpeed()+=5;
                myAvatar.getMana()+=20;
                myAvatar.getHealth()=100;
                poveste ="Ai primit 5 puncte pe viteza, 20 pe mana si viata este refacuta\n";
                cout<<poveste;
                stocare.salvarePoveste(poveste);
                }
                break;

            case 2:
                {
                poveste ="Ai ales sa dormi in hambar\n";
                cout<<poveste;
                stocare.salvarePoveste(poveste);
                if(myAvatar.getHealth()<75)
                {
                    myAvatar.getHealth()=75;
                    myAvatar.getMana()+=20;
                    myAvatar.getSpeed()-=5;
                    poveste ="Viteza a scazut cu 5 puncte\n";
                    cout<<poveste;
                    stocare.salvarePoveste(poveste);
                }
                    poveste = "Din cauza mediului in care doarme avatarul, acesta are un vis ciudat cu animale.\n";
                    cout<<poveste;
                    stocare.salvarePoveste(poveste);
                    Animale animal1("Oita", 10);
                    Animale animal2("Capra", 9);

                    Animale animalCombinat = animal1 + animal2;
                    cout<< "Animal combinat: " << animalCombinat << endl;
                    poveste =" Animal combinat : ";
                    stocare.salvarePoveste(poveste);

                    Animale animalScos = animalCombinat - animal2;
                    cout<< "Animal scos: " << animalScos << endl;
                    poveste= "Animal scos: ";
                    stocare.salvarePoveste(poveste);

                    cout<< "Animal1 este egal cu Animal2: " << (animal1 == animal2) << endl;
                    poveste="Animal1 este egal cu Animal2: ";
                    stocare.salvarePoveste(poveste);
                    cout<<"Animal1 este mai mic decat Animal2: " << (animal1 < animal2) << endl;
                    poveste="Animal1 este mai mic decat Animal2: ";
                    stocare.salvarePoveste(poveste);
                    cout<< "Animal1 este mai mare decat Animal2: " << (animal1 > animal2) << endl;
                    poveste= "Animal1 este mai mare decat Animal2: ";
                    stocare.salvarePoveste(poveste);

                }
                break;

        }
    }
    poveste ="S-a facut dimineata\n";
    cout<<poveste;
    stocare.salvarePoveste(poveste);
    poveste ="Fiind pe langa han, proprietarul cladirii iti propune sa faci niste treburi pentru a obtine bani,fiecare iti aduce cate 15 banuti, accepti?(y/n)\n";
    cout<<poveste;
    stocare.salvarePoveste(poveste);
    string raspuns7;
    cin>>raspuns7;
    list<int*> sarcini;

    if (raspuns7 == "y")
        {
        poveste = "Prima sarcina este mulsul animalelor, o faci? (y/n)\n";
        cout<<poveste;
        stocare.salvarePoveste(poveste);
        cin >> raspuns7;
        if (raspuns7 == "y") {
                bani=bani+15;
            int* ptr_int = new int;
            *ptr_int = 1;
            sarcini.push_back(ptr_int);
        }

        cout<<poveste; "A doua este taiatul de lemne, o faci? (y/n)\n";
        cout<<poveste;
        stocare.salvarePoveste(poveste);
        cin >> raspuns7;
        if (raspuns7 == "y") {
                   bani=bani+15;
            int* ptr_int = new int;
            *ptr_int = 1;
            sarcini.push_back(ptr_int);
        }

        poveste =  "A treia este perierea cailor, o faci? (y/n)\n";
        cout<<poveste;
        stocare.salvarePoveste(poveste);
        cin >> raspuns7;
        if (raspuns7 == "y") {
                   bani=bani+15;
            int* ptr_int = new int;
            *ptr_int = 1;
            sarcini.push_back(ptr_int);
        }

        poveste = "A patra este aprovizionarea depozitului, o faci? (y/n)\n";
        cout<<poveste;
        stocare.salvarePoveste(poveste);
        cin >> raspuns7;
        if (raspuns7 == "y") {
               bani=bani+15;
            int* ptr_int = new int;
            *ptr_int = 1;
            sarcini.push_back(ptr_int);
        }

        poveste = "Ultima este curatarea hambarului, o faci? (y/n)\n";
        cout<<poveste;
        stocare.salvarePoveste(poveste);
        cin >> raspuns7;
        if (raspuns7 == "y") {
               bani=bani+15;
            int* ptr_int = new int;
            *ptr_int = 1;
            sarcini.push_back(ptr_int);
        }

        cout << "Ai facut " << sarcini.size() << " sarcini.\n";
        poveste ="Ai facut sarcini";
        stocare.salvarePoveste(poveste);
        cout << "Ai facut " << 15 * sarcini.size() <<" banuti.\n";
        poveste = "Ai facut banuti";
        stocare.salvarePoveste(poveste);

        for (int* ptr : sarcini) {
            delete ptr;
        }
    }
    poveste ="Ai plecat de han, si mergi de 3 ore pe drum. \n";
    cout<<poveste;
    stocare.salvarePoveste(poveste);
    poveste ="Ajungi la o rascruce. Alegi drumul din stanga sau cel din dreapta? (y/n)\n";
    cout<<poveste;
    stocare.salvarePoveste(poveste);
    cout<<"1.Stanga\n ";
    cout<<"2.Dreapta\n ";
    int optiune3;
    cin>>optiune3;
    switch(optiune3)
    {
    case 1:
        {
        poveste ="Drumul te-a la un rau. Inotul nu este prea sigur, deci singura optiune este gasirea unui pod. ";
        cout<<poveste;
        stocare.salvarePoveste(poveste);
        poveste ="La cativa metri vezi un pod care este pazit de un goblin. ";
        cout<<poveste;
        stocare.salvarePoveste(poveste);
        poveste ="Goblinul iti cere 50 de banuti ca sa traversezi, alegi sa platesti?(y/n)\n";
        cout<<poveste;
        stocare.salvarePoveste(poveste);
        string raspuns8;
        cin >>raspuns8;
        if(raspuns8=="y")
        {
            bani = bani - 50;
        }
        else
        {
            poveste ="Din cauza ca nu vrei sa platesti, goblinul te provoaca la lupta.\n";
            cout<<poveste;
            stocare.salvarePoveste(poveste);
            Monstru monstru("goblin",60,0,10,8,2,Arme("buzdugan","comun",10,1,1));
            gameplay primaRunda(inventar,myAvatar,monstru);
            primaRunda.rundaLuptei();
            poveste ="Goblinul a fost invins si a picat in apa. Arma acestuia a cazut pe pod, o iei? (y/n)\n";
            cout<<poveste;
            stocare.salvarePoveste(poveste);
            Arme buzdugan("buzdugan","comun",10,1,1);
            buzdugan.info();
            string raspuns;
            cin>>raspuns;
            if(raspuns=="y")
            {
                myAvatar.schimbaArma(buzdugan);
            }
            else
            {
                poveste ="Arma este prea slaba si ai aruncat-o in apa. \n";
                cout<<poveste;
                stocare.salvarePoveste(poveste);
            }
         }
        }
        break;
    case 2:
        {
            poveste ="Ai luat-o la dreapta. Ai mers pana ai intalnit o femeie care iti cere niste bani. \n";
            cout<<poveste;
            stocare.salvarePoveste(poveste);
            poveste ="Cat timp erai concentrat la femeie, pe la spate se apropie o peroana care incearca sa te loveasca. \n";
            cout<<poveste;
            stocare.salvarePoveste(poveste);
            poveste ="Din cauza ca ai reflexe bune, reusesti sa te feresti la timp, si observi ca acea persoana este un bandit, si era sa fi jefuit. \n";
            cout<<poveste;
            stocare.salvarePoveste(poveste);
            poveste ="Trebuie sa invingi banditul pentru a continua. \n";
            cout<<poveste;
            stocare.salvarePoveste(poveste);
            Monstru monstru("bandit",85,0,20,8,2,Arme("pumnal","rar",20,1,2));
            gameplay primaRunda(inventar,myAvatar,monstru);
            primaRunda.rundaLuptei();
            poveste ="Banditul a fost invins si cu toata putearea a fugit. Arma acestuia a ramas pe pamant, o iei? (y/n)\n";
            cout<<poveste;
            stocare.salvarePoveste(poveste);
            Arme buzdugan("buzdugan","comun",10,1,1);
            buzdugan.info();
            string raspuns;
            cin>>raspuns;
            if(raspuns=="y")
            {
                myAvatar.schimbaArma(buzdugan);
            }
            break;
        }
    }
    poveste = "Apare un portal, in care esti atras. Te trezesti din senin cu adversarul pe care il cautai inca de la inceput. Incepe lupta finala.\n";
    cout<<poveste;
    stocare.salvarePoveste(poveste);
    Monstru monstru("Lordul Mortii",200,0,20,8,2,Arme("sabie","epic",40,1,5));
    gameplay primaRunda(inventar,myAvatar,monstru);
    primaRunda.rundaLuptei();
    cout<<"Felicitari ai terminat jocul!\n";
}

