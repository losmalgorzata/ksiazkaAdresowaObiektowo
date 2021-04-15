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
    const string NAZWA_PLIKU_Z_ADRESATAMI;

    private:
    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);

    public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : NAZWA_PLIKU_Z_ADRESATAMI(NAZWAPLIKUZADRESATAMI){};
    string pobierzNazwePlikuZAdresatami();
    void dopiszAdresataDoPliku(Adresat adresat);
};

#endif

