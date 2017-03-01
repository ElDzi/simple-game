#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <algorithm>
#ifdef _WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

using namespace std;
const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");
int main()
{
    srand( time( NULL ) );
    string potwor;
    string bron;
    int pieniadze;
    bool started= false;
    int sec = 0;
    int ileZabil = 0;
    int ileZginal = 0;

    while(!started)
    {
        cout<<"losowanie pieniedzy"<<endl;
        do
        {
            sec++;
            pieniadze += ( std::rand() % 500 ) + 50;
            cout<<red<<"Posiadasz "<<yellow<<pieniadze<<"$"<<endl;
            Sleep(500);
        }
        while(sec<=5);
        cout<<red<<"Posiadasz "<<yellow<<pieniadze<<reset<<endl;
        started = true;
    }
    bool unlockedSpecial = false;
    bool gunSelected = false;
    bool startBattle = false;
    while(started)
    {
        if(!gunSelected)
        {
            if(ileZabil >0)
            {
                int rand = ( std::rand() % 100 ) + 1;
                if(rand <=20)
                {
                    cout<<"Udalo Ci sie odblokowac bron"<<endl;
                    unlockedSpecial = true;
                }
                cout<<"Zabiles juz "<<ileZabil<<" potworow!"<<endl;
                cout<<"Zginales "<<ileZginal<<" razy"<<endl;
            }
            cout<<green<<"Wybierz swoja bron:"<<endl;
            cout<<"1. Miecz (200$)"<<endl;
            cout<<"2. Lustro (250$)"<<endl;
            cout<<"3. Pierscien (500$)"<<endl;
            cout<<"4. Luk (700$)"<<endl;
            if(unlockedSpecial)
            {
                cout<<"5. Bomba wodorowa (1000$)"<<endl;
            }
            cin>>bron;
            if(bron == "miecz")
            {
                if(pieniadze >= 200)
                {
                    pieniadze -= 200;
                    cout<<cyan<<"Kupiles miecz! Pozostalo Ci "<<pieniadze << "$"<<endl;
                    gunSelected = true;

                }
                else
                {
                    int rand = ( std::rand() % 100 ) + 1;
                    if(rand <=50)
                    {
                        cout<<magenta<<"Nie masz pieniedzy, ale bank udzieli Ci pozyczki! Otrzymujesz 400$"<<endl;
                        startBattle = false;
                        gunSelected = false;
                        pieniadze +=400;
                    }
                    else
                    {
                        cout<<red<<"Nie masz tyle pieniedzy! Gra skonczona!"<<endl;
                        startBattle = false;
                        gunSelected = false;
                        started = false;
                    }
                }
            }
            else if(bron == "lustro")
            {
                if(pieniadze >= 250)
                {
                    pieniadze -= 250;
                    cout<<cyan<<"Kupiles lustro! Pozostalo Ci "<<pieniadze << "$"<<endl;
                    gunSelected = true;
                }
                else
                {
                    cout<<red<<"Nie masz tyle pieniedzy! Mozesz kupic jedynie miecz!"<<endl;

                }
            }

            else if(bron == "pierscien")
            {
                if(pieniadze >= 500)
                {
                    pieniadze -= 500;
                    cout<<cyan<<"Kupiles pierscien! Pozostalo Ci "<<pieniadze << "$"<<endl;
                    gunSelected = true;
                }
                else
                {
                    cout<<red<<"Nie masz tyle pieniedzy! Mozesz kupic jedynie miecz i lustro!"<<endl;

                }

            }
            else if(bron == "luk")
            {
                if(pieniadze >= 700)
                {
                    pieniadze -= 700;
                    cout<<cyan<<"Kupiles luk! Pozostalo Ci "<<pieniadze << "$"<<endl;
                    gunSelected = true;

                }
                else
                {
                    cout<<red<<"Nie masz tyle pieniedzy! Mozesz kupic jedynie miecz, lustro i pierscien!"<<endl;

                }
            }
            else if(bron == "bomba")
            {
                if(pieniadze >= 1000)
                {
                    pieniadze -= 1000;
                    cout<<cyan<<"Kupiles bombe! Pozostalo Ci "<<pieniadze << "$"<<endl;
                    gunSelected = true;

                }
                else
                {
                    cout<<red<<"Nie masz tyle pieniedzy! Mozesz kupic jedynie miecz, lustro, pierscien i luk!"<<endl;

                }
            }
            else
            {
                cout<<red<<"Nie wybrales poprawnie broni! Wybierz jeszcze raz!"<<endl;
            }


        }

        if(gunSelected && !startBattle)
        {
            int rand = ( std::rand() % 4 ) + 1;
            switch(rand)
            {
            case 1:
            {
                potwor = "hydra";
                cout<<green<<"Wylosowales hydre"<<endl;
                startBattle = true;
                break;
            }
            case 2:
            {
                potwor = "bazyliszek";
                cout<<green<<"Wylosowales bazyliszka"<<endl;
                startBattle = true;
                break;
            }
            case 3:
            {
                potwor = "ork";
                cout<<green<<"Wylosowales orke"<<endl;
                startBattle = true;
                break;
            }
            case 4:
            {
                potwor = "goblin";
                cout<<green<<"Wylosowales goblina"<<endl;
                startBattle = true;
                break;
            }
            }
        }

        if(startBattle)
        {
            if(bron == "miecz")
            {
                if(potwor == "hydra")
                {
                    cout<<yellow<<"Udalo Ci sie zabic potwora!"<<endl;
                    pieniadze += 400;
                    ileZabil++;
                    gunSelected = false;
                    startBattle = false;
                }
                else
                {
                    cout<<red<<"Zostales zabity. Zacznij ponownie!"<<endl;
                    startBattle = false;
                    gunSelected = false;
                    ileZginal++;

                }
            }
            else if(bron == "lustro")
            {
                if(potwor == "bazyliszek")
                {
                    cout<<yellow<<"Udalo Ci sie zabic potwora!"<<endl;
                    pieniadze += 500;
                    ileZabil++;
                    gunSelected = false;
                    startBattle = false;
                }
                else
                {
                    cout<<red<<"Zostales zabity. Zacznij ponownie!"<<endl;
                    startBattle = false;
                    gunSelected = false;
                    ileZginal++;
                }
            }
            else if(bron == "pierscien")
            {
                if(potwor == "ork")
                {
                    cout<<yellow<<"Udalo Ci sie zabic potwora!"<<endl;
                    pieniadze += 1000;
                    startBattle = false;
                    gunSelected = false;
                    ileZabil++;
                }
                else
                {
                    cout<<red<<"Zostales zabity. Zacznij ponownie!"<<endl;
                    startBattle = false;
                    gunSelected = false;
                    ileZginal++;
                }
            }
            else if(bron == "luk")
            {
                if(potwor == "goblin")
                {
                    cout<<yellow<<"Udalo Ci sie zabic potwora!"<<endl;
                    pieniadze += 1400;
                    ileZabil++;
                    gunSelected = false;
                    startBattle = false;
                }
                else
                {
                    cout<<red<<"Zostales zabity. Zacznij ponownie!"<<endl;
                    startBattle = false;
                    gunSelected = false;
                    ileZginal++;
                }
            }
            else if(bron == "bomba")
            {
                cout<<yellow<<"Udalo Ci sie zabic potwora!"<<endl;
                pieniadze += 1400;
                ileZabil++;
                gunSelected = false;
                startBattle = false;
            }



        }
    }
}
