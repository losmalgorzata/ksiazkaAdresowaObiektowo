#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    vector <Adresat> adresaci;

private:
    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata();
    int pobierzZPlikuIdOstatniegoAdresata();
    PlikZAdresatami plikZAdresatami;

public:
    int dodajAdresata();
    void wyswietlWszystkichAdresatow();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();


    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami){};
};

#endif
