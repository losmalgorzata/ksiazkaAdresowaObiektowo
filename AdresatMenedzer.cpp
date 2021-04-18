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

int AdresatMenedzer::zwrocNumerLiniiSzukanegoAdresata(int idAdresata)
{
    bool czyIstniejeAdresat = false;
    int numerLiniiWPlikuTekstowym = 1;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    fstream plikTekstowy;
    plikTekstowy.open(plikZAdresatami.pobierzNazwePlikuZAdresatami(), ios::in);

    if (plikTekstowy.good() == true && idAdresata != 0)
    {
        while(getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idAdresata == plikZAdresatami.pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                czyIstniejeAdresat = true;
                plikTekstowy.close();
                return numerLiniiWPlikuTekstowym;
            }
            else
                numerLiniiWPlikuTekstowym++;
        }
        if (czyIstniejeAdresat = false)
        {
            plikTekstowy.close();
            return 0;
        }
    }
    return 0;
}

void AdresatMenedzer::edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string nazwaTymczasowegoPlikuZAdresatami = "tymczasowy.txt";
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;

    odczytywanyPlikTekstowy.open(plikZAdresatami.pobierzNazwePlikuZAdresatami(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true)
    {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            if (numerWczytanejLinii == numerEdytowanejLinii)
            {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << liniaZDanymiAdresataOddzielonePionowymiKreskami;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << liniaZDanymiAdresataOddzielonePionowymiKreskami;
            }
            else
            {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;
            }
            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(plikZAdresatami.pobierzNazwePlikuZAdresatami());
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, plikZAdresatami.pobierzNazwePlikuZAdresatami());
    }
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

void AdresatMenedzer::zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata)
{
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    numerLiniiEdytowanegoAdresata = zwrocNumerLiniiSzukanegoAdresata(idEdytowanegoAdresata);
    liniaZDanymiAdresata = plikZAdresatami.zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    edytujWybranaLinieWPliku(numerLiniiEdytowanegoAdresata, liniaZDanymiAdresata);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
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
                    zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                    break;
                }
            case '2':
                {
                    string nazwisko;
                    cout << "Podaj nowe nazwisko: ";
                    nazwisko = MetodyPomocnicze::wczytajLinie();
                    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
                    adresaci[i].ustawNazwisko(nazwisko);
                    zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                    break;
                }
            case '3':
                {
                    string numerTelefonu;
                    cout << "Podaj nowy numer telefonu: ";
                    numerTelefonu = MetodyPomocnicze::wczytajLinie();
                    adresaci[i].ustawNumerTelefonu(numerTelefonu);
                    zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                    break;
                }
            case '4':
                {
                    string email;
                    cout << "Podaj nowy email: ";
                    email = MetodyPomocnicze::wczytajLinie();
                    adresaci[i].ustawEmail(email);
                    zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                    break;
                }
            case '5':
                {
                    string adres;
                    cout << "Podaj nowy adres zamieszkania: ";
                    adres = MetodyPomocnicze::wczytajLinie();
                    adresaci[i].ustawAdres(adres);
                    zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
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
