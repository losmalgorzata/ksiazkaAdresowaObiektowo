#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    for (int i=0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
    for (int i=0; i < uzytkownicy.size(); i++)
    {
        cout << (uzytkownicy[i].pobierzId()) << endl;
        cout << (uzytkownicy[i].pobierzLogin()) << endl;
        cout << (uzytkownicy[i].pobierzHaslo()) << endl;
    }
}

int UzytkownikMenedzer::logowanieUzytkownika()
{
    string login="", haslo="";
    cout << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    for (int i = 0; i < uzytkownicy.size(); i++) {
        if (uzytkownicy[i].pobierzLogin() == login){
            for (int p = 0; p < 3; p++)
            {
                cout << "Podaj haslo. Pozostalo prob " << 3-p << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();
                if (uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    cout << "Zalogowales sie" << endl;
                    Sleep(1000);
                    idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                    return idZalogowanegoUzytkownika;
                }
            }
            cout << "Podales 3 razy bledne haslo" << endl;
            Sleep(1500);
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl;
    Sleep(1500);
    return 0;
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
}

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany()
{
    if(idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (int i=0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione" << endl;
            Sleep(1500);
        }
    }

    zapiszWszystkichUzytkownikowDoPliku();
}

void UzytkownikMenedzer::zapiszWszystkichUzytkownikowDoPliku()
{   fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    vector<string> uzytkownicyPoZmianie;

    for (int i=0; i<uzytkownicy.size(); i++) {
        liniaZDanymiUzytkownika = to_string(uzytkownicy[i].pobierzId())+"|"+uzytkownicy[i].pobierzLogin()+"|"+uzytkownicy[i].pobierzHaslo()+"|";
        uzytkownicyPoZmianie.push_back(liniaZDanymiUzytkownika);
    }

    //plikTekstowy.open(plikZUzytkownikami.pobierzNazwePlikuZUzytkownikami(), ios::out);
    plikTekstowy.open(plikZUzytkownikami.pobierzNazwePliku(), ios::out);
    if (plikTekstowy.good() == true)
    {
        for(vector<string>::const_iterator i = uzytkownicyPoZmianie.begin(); i != uzytkownicyPoZmianie.end(); ++i) {
            plikTekstowy << *i << '\n';
        }
    }
    else
    {
        //cout << "Nie mozna otworzyc pliku " << plikZUzytkownikami.pobierzNazwePlikuZUzytkownikami() << endl;
        cout << "Nie mozna otworzyc pliku " << plikZUzytkownikami.pobierzNazwePliku() << endl;
    }
    plikTekstowy.close();
}
