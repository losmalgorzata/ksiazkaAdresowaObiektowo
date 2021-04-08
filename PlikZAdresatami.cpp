#include "PlikZAdresatami.h"

bool PlikZAdresatami::czyPlikJestPusty()
{
    fstream plikTekstowy;
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty(plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    plikTekstowy.close();
    system("pause");
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += konwerjsaIntNaString(adresat.id) + '|';
    liniaZDanymiAdresata += konwerjsaIntNaString(adresat.idUzytkownika) + '|';
    liniaZDanymiAdresata += adresat.imie + '|';
    liniaZDanymiAdresata += adresat.nazwisko + '|';
    liniaZDanymiAdresata += adresat.numerTelefonu + '|';
    liniaZDanymiAdresata += adresat.email + '|';
    liniaZDanymiAdresata += adresat.adres + '|';

    return liniaZDanymiAdresata;
}








