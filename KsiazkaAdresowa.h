#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    //AdresatMenedzer adresatMenedzer;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami)
    {
        //cout << "wszedlem" << endl;
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
        //cout << "mam uzytkownikow" << endl;
        //adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
        //cout << "mam adresatow" << endl;
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    int ustawIdZalogowanegoUzytkownika(int NoweIdZalogowanegoUzytkownika);
    //void wyswietlWszystkichAdresatow();
};
