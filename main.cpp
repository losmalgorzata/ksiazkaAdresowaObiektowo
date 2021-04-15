#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "ksiazkaPoKonwersji.txt");

    char wybor;
    int idZalogowanegoUzytkownika=0;
    int idOstatniegoAdresata=0;
    ksiazkaAdresowa.ustawIdZalogowanegoUzytkownika(0);

    while(true){
        if (ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika() == 0){
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();
            switch(wybor){
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                idZalogowanegoUzytkownika = ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika();
                ksiazkaAdresowa.ustawIdOstatniegoAdresata(ksiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika));
                idOstatniegoAdresata = ksiazkaAdresowa.pobierzIdOstatniegoAdresata();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu" << endl << endl;
                system("pause");
                break;
            }
        } else {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();
            switch(wybor){
            case '1':
                ksiazkaAdresowa.ustawIdOstatniegoAdresata(ksiazkaAdresowa.dodajAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata));
                idOstatniegoAdresata = ksiazkaAdresowa.pobierzIdOstatniegoAdresata();
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                break;
            case '6':
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.ustawIdZalogowanegoUzytkownika(0);
                idZalogowanegoUzytkownika = ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu" << endl << endl;
                system("pause");
                break;
            }
        }
    }

    return 0;
}
