#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "UzytkownikMenedzer.h"

class PlikZAdresatami
{
    const string nazwaPlikuZAdresatami;
    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);

    public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI){};
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    string pobierzNazwePlikuZAdresatami();
    //void dopiszAdresataDoPliku(Adresat adresat);

};

#endif

