#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "ksiazkaPoKonwersji.txt");
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    //logging and setting user's id
    ksiazkaAdresowa.ustawIdZalogowanegoUzytkownika(ksiazkaAdresowa.logowanieUzytkownika());
    int idZalogowanegoUzytkownika = ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika();
    //cout << "user id: " << idZalogowanegoUzytkownika << endl;

    //password change
    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    system("pause");

    //read contacts
    ksiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
    ksiazkaAdresowa.ustawIdOstatniegoAdresata(ksiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika));
    int idOstatniegoAdresata = ksiazkaAdresowa.pobierzIdOstatniegoAdresata();
    //cout << "ostatnie id: " << idOstatniegoAdresata << endl;
    system("pause");

    //display all contacts
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();

     //logging out - DODAJ adresaci.clear!!!
    ksiazkaAdresowa.ustawIdZalogowanegoUzytkownika(0);
    idZalogowanegoUzytkownika = ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika();
    //cout << "user id: " << idZalogowanegoUzytkownika << endl;




    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    return 0;
}
