#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if(plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << "Nowy adresat zosta³ dodany" << endl;
    else
        cout << "Blad. Adresat nie zostal dodany" << endl;
    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;
    string imie, nazwisko, numerTelefonu, email, adres;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    imie = MetodyPomocnicze::wczytajLinie();
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    adresat.ustawImie(imie);

    cout << "Podaj nazwisko: ";
    nazwisko = MetodyPomocnicze::wczytajLinie();
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    adresat.ustawNazwisko(nazwisko);

    cout << "Podaj numer telefonu: ";
    numerTelefonu = MetodyPomocnicze::wczytajLinie();
    adresat.ustawNumerTelefonu(numerTelefonu);

    cout << "Podaj email: ";
    email = MetodyPomocnicze::wczytajLinie();
    adresat.ustawEmail(email);

    cout << "Podaj adres: ";
    adres = MetodyPomocnicze::wczytajLinie();
    adresat.ustawAdres(adres);

    return adresat;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatMenedzer::wyszukajPoImieniu()
{
    string imieDoWyszukania;
    cout << "Podaj imie do wyszukania: " << endl;
    imieDoWyszukania = MetodyPomocnicze::wczytajLinie();
    imieDoWyszukania = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imieDoWyszukania);
    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzImie() == imieDoWyszukania)
        {
            wyswietlDanePojedynczejOsoby(adresaci[i]);
        }
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyszukajPoNazwisku()
{
    string nazwiskoDoWyszukania;
    cout << "Podaj nazwisko do wyszukania: " << endl;
    nazwiskoDoWyszukania = MetodyPomocnicze::wczytajLinie();
    nazwiskoDoWyszukania = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoDoWyszukania);
    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzNazwisko() == nazwiskoDoWyszukania)
        {
            wyswietlDanePojedynczejOsoby(adresaci[i]);
        }
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyswietlDanePojedynczejOsoby(Adresat adresat){
    cout << adresat.pobierzId() << "|" << adresat.pobierzImie() << "|" << adresat.pobierzNazwisko() << "|";
    cout << adresat.pobierzNumerTelefonu() << "|" << adresat.pobierzEmail() << "|" << adresat.pobierzAdres() << endl;
}

int AdresatMenedzer::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

char AdresatMenedzer::wybierzOpcjeZMenuEdycja()
{
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

void AdresatMenedzer::usunPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void AdresatMenedzer::zmienNazwePliku(string staraNazwa, string nowaNazwa)
{
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

void AdresatMenedzer::edytujAdresata()
{
    system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                {
                    string imie;
                    cout << "Podaj nowe imie: ";
                    imie = MetodyPomocnicze::wczytajLinie();
                    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
                    adresaci[i].ustawImie(imie);
                    edytujWybranegoAdresataWPliku(adresaci[i]);
                    break;
                }
            case '2':
                {
                    string nazwisko;
                    cout << "Podaj nowe nazwisko: ";
                    nazwisko = MetodyPomocnicze::wczytajLinie();
                    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
                    adresaci[i].ustawNazwisko(nazwisko);
                    edytujWybranegoAdresataWPliku(adresaci[i]);
                    break;
                }
            case '3':
                {
                    string numerTelefonu;
                    cout << "Podaj nowy numer telefonu: ";
                    numerTelefonu = MetodyPomocnicze::wczytajLinie();
                    adresaci[i].ustawNumerTelefonu(numerTelefonu);
                    edytujWybranegoAdresataWPliku(adresaci[i]);
                    break;
                }
            case '4':
                {
                    string email;
                    cout << "Podaj nowy email: ";
                    email = MetodyPomocnicze::wczytajLinie();
                    adresaci[i].ustawEmail(email);
                    edytujWybranegoAdresataWPliku(adresaci[i]);
                    break;
                }
            case '5':
                {
                    string adres;
                    cout << "Podaj nowy adres zamieszkania: ";
                    adres = MetodyPomocnicze::wczytajLinie();
                    adresaci[i].ustawAdres(adres);
                    edytujWybranegoAdresataWPliku(adresaci[i]);
                    break;
                }
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");

}

int AdresatMenedzer::usunAdresata()
{
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;
    int idOstatniegoAdresata = plikZAdresatami.pobierzIdOstatniegoAdresata();

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> pobierzId() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't')
            {
                usunWybranegoAdresataZPliku(idUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                if(idOstatniegoAdresata == idUsuwanegoAdresata)
                {
                    idOstatniegoAdresata--;
                }
                plikZAdresatami.ustawIdOstatniegoAdresata(idOstatniegoAdresata);
                cout << "idOstatniegoAdresata " << idOstatniegoAdresata << endl;
                return idOstatniegoAdresata;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return idOstatniegoAdresata;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
        return idOstatniegoAdresata;
    }
    return idOstatniegoAdresata;
}

void AdresatMenedzer::usunWybranegoAdresataZPliku(int idUsuwanegoAdresata)
{
    int numerLiniiWPlikuTekstowym = 1;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";

    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string nazwaTymczasowegoPlikuZAdresatami = "tymczasowy.txt";

    odczytywanyPlikTekstowy.open(plikZAdresatami.pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    int idAdresata = 0;

    if (odczytywanyPlikTekstowy.good() == true && idUsuwanegoAdresata != 0)
    {
        while(getline(odczytywanyPlikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            idAdresata = plikZAdresatami.pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami);

            if(idUsuwanegoAdresata != idAdresata)
            {
                if(numerLiniiWPlikuTekstowym!=1)
                {
                    tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;
                    numerLiniiWPlikuTekstowym++;
                }
                else
                {
                    tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
                    numerLiniiWPlikuTekstowym++;
                }
            }
            else
                numerLiniiWPlikuTekstowym++;
        }
    }
    odczytywanyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();
    usunPlik(plikZAdresatami.pobierzNazwePliku());
    zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, plikZAdresatami.pobierzNazwePliku());
}

void AdresatMenedzer::edytujWybranegoAdresataWPliku(Adresat adresat)
{
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    int numerLiniiWPlikuTekstowym = 1;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    fstream plikTekstowy, tymczasowyPlikTekstowy;
    string nazwaTymczasowegoPlikuZAdresatami = "tymczasowy.txt";

    plikTekstowy.open(plikZAdresatami.pobierzNazwePliku(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true && adresat.pobierzId() != 0)
    {
        while(getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(adresat.pobierzId() == plikZAdresatami.pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                liniaZDanymiAdresata = plikZAdresatami.zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

                if(numerLiniiWPlikuTekstowym!=1)
                {
                    tymczasowyPlikTekstowy << endl << liniaZDanymiAdresata;
                    numerLiniiWPlikuTekstowym++;
                }
                else
                {
                    tymczasowyPlikTekstowy << liniaZDanymiAdresata;
                    numerLiniiWPlikuTekstowym++;
                }
            }
            else
            {
                if(numerLiniiWPlikuTekstowym!=1)
                {
                    liniaZDanymiAdresata = daneJednegoAdresataOddzielonePionowymiKreskami;
                    tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;
                    numerLiniiWPlikuTekstowym++;
                }
                else
                {
                    liniaZDanymiAdresata = daneJednegoAdresataOddzielonePionowymiKreskami;
                    tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
                    numerLiniiWPlikuTekstowym++;
                }
            }
        }
    }

    plikTekstowy.close();
    tymczasowyPlikTekstowy.close();
    usunPlik(plikZAdresatami.pobierzNazwePliku());
    zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, plikZAdresatami.pobierzNazwePliku());

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}
