#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), adresatMenedzer(nazwaPlikuZAdresatami)
    {
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    int ustawIdZalogowanegoUzytkownika(int NoweIdZalogowanegoUzytkownika);
    int pobierzIdZalogowanegoUzytkownika();

    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();
    int pobierzIdOstatniegoAdresata();
    int ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata);
    int dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
};

