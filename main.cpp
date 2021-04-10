#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    //logging and setting user's id
    ksiazkaAdresowa.ustawIdZalogowanegoUzytkownika(ksiazkaAdresowa.logowanieUzytkownika());

    //password change
    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    //logging out - DODAJ adresaci.clear!!!
    ksiazkaAdresowa.ustawIdZalogowanegoUzytkownika(0);
    //cout << ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika();







    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    return 0;
}
