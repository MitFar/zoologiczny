#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
using namespace std;
enum menu{dodanie, usuniecie, zmiana,zamien,odczyt, wyszukanie,bledny_znak};
enum umarszczenie{Sniade, Wilczaste, Rude, Jednolite,Dzicze};
struct zwierze 
{
    string gatunek, rasa, umarszczenie, uwagi, plec; 
    int liczba_sztuk, data_dostawy;
    double cena;

};

zwierze wpisz()
{
    zwierze tmp;
    string k;
    
    cout << "Wprowadz gatunek zwierzecia: " << endl;
    cin >> tmp.gatunek;
    cout << "Wprowadz rase zwierzecia: " << endl;
    cin >> tmp.rasa;
    cout << "Uzupelnij plec zwierzecia:\n (1)Samiec - kliknij M\n (2)Samica - kliknij K \n";
    cin >> k;
    if (k == "M" ||k=="K")
    {
        tmp.plec = k;
    }
    else
    {
        cout << "Wpisales niepoprawny znak!" << endl;
    }
    //umarszczenie operacja;
    cout << "Umarszczenie: \n 1.Sniade\n 2.Wilczaste \n 3.Rude\n 4.Jednolite\n 5.Dzicze" << endl;
    unsigned int n;
    cin >> n;
    if (n >= 1 && n <= 5)
    {
        
        
        switch (n)
        {
        case 1: tmp.umarszczenie = "Sniade";
            break;
        case 2: tmp.umarszczenie="Wilczaste";
            break;
        case 3: tmp.umarszczenie="Rude";
            break;
        case 4: tmp.umarszczenie="Jednolite";
            break;
        case 5: tmp.umarszczenie = "Dzicze";
            break;
       
        }
    }
    else
    {
        cout << "Podano bledny znak!" << endl;
    }
    cout << "Podaj liczbe sztuk: " << endl;
    cin>>tmp.liczba_sztuk;
    cout << "Podaj cene: " << endl;
    cin >> tmp.cena;
    cout << "Czas dostawy (podaj w godzinach): " << endl;
    cin >> tmp.data_dostawy;
    cout << "Uwagi:(; konczy wpisywanie) " << endl;
    getline(cin, tmp.uwagi, ';');
    



    
    return tmp;
}
void do_vektora(vector<zwierze> &baza)
{
    baza.push_back(wpisz());
}
void wyswietl(vector<zwierze> &baza)
{
    for (size_t i = 0; i < baza.size(); i++)
    {
        cout << baza[i].gatunek << baza[i].rasa << baza[i].plec << baza[i].umarszczenie << baza[i].liczba_sztuk << baza[i].cena << baza[i].data_dostawy << baza[i].uwagi;
    }
    
}
void zapis_do_pliku(vector<zwierze> &baza)
{
    
    fstream plik;
    plik.open("zoologiczny.txt",ios::out|ios::app);
    for (size_t i = 0; i < baza.size(); i++)
    {
        plik <<i+1<<".Gatunek:"<< baza[i].gatunek <<", rasa:"<< baza[i].rasa<<", plec:"<< baza[i].plec <<", umarszczenie:"<<baza[i].umarszczenie<<", liczba sztuk:"<<baza[i].liczba_sztuk<<", cena jedostkowa[pln]:"<<baza[i].cena<<", data dostawy[h]"<<baza[i].data_dostawy<<", Uwagi: "<<baza[i].uwagi<< endl;
    }
    plik.close();
    
}
void wczytaj_plik(vector<zwierze>& baza)
{
    /* string linia;
    int numer_linii;
    fstream plik;
    plik.open("zoologiczny.txt", ios::in);
    if (plik.good() == false) cout << "Nie mozna odtworzyc pliku.";
    while (getline(plik, linia))
    baza = linia;

    plik.close();
    cout <<linia;
    */
}

void kasuj_wiersz(const string zoologiczny, const size_t wiersz)
{
    vector < string > vec;
    ifstream in(zoologiczny.c_str());
    string tmp;
    while (getline(in, tmp)) vec.push_back(tmp);

    in.close();
    ofstream out(zoologiczny.c_str());
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i + 1 != wiersz) out << vec[i] << endl;

    }
    out.close();
    cout << "Wiersz zostal usuniety!" << endl;
}
string znajdz(vector<zwierze> &baza,string x)
{
    cout << "Po jakiej kategorii chcesz szukac:\n1-gatunek\n2-rasa\n3-plci" << endl;
        int szukana;
        cin >> szukana;
        switch (szukana)
        {
        case '1':
            for (size_t i = 0; i <= baza.size(); i++)
            {
                if (x == baza[i].gatunek)
                {
                    ifstream odczyt("zoologiczny.txt");

                    if (odczyt.is_open())
                    {
                        char wiersz[10000];
                        while (odczyt.getline(wiersz, 10000))
                        {
                            cout << wiersz << endl;
                        }
                    }
                    else
                        cout << "Nie udalo sie otworzyc pliku";

                    break;
                }
            }
            break;
        case'2':

            break;
        case '3':

            break;
        
        }
        return 0;
}
void wczytaj_baze(vector<zwierze> &baza)
{
    cout << "Pokazuje baze!" << endl;
    ifstream odczyt("zoologiczny.txt");

    if (odczyt.is_open())
    {
        char wiersz[10000];
        while (odczyt.getline(wiersz, 10000))
        {
            cout << wiersz << endl;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku";
    odczyt.close();
}

int main()
{
    vector<zwierze> baza;
    //menu operacja;
    cout << "Witaj w sklepie zoologicznym, co chcialbys wykonac?\n"
        "(1) - Dodanie zwierzecia \n"
        "(2) - Usuniecie zwierzecia \n"
        "(3) - Zmiane danych zwierzecia \n"
        "(4) - Wyszukanie \n"
        "(5) - Zapis do pliku \n"
        "(6) - Wyswietla baze \n"
        "(7) - Wszytanie calego pliku \n"
        "(8) - Koniec \n"

        << flush;
    char wybor;
   
    string linia;
    string slowo;
    
    vector<zwierze> zwierz(1);
    zwierze z1;
    while (true) {
        
        
            cin >> wybor;
            switch (wybor)
            {
            case '1': do_vektora(baza); break;
            case '2':
                int x;
                cout << "Wprowadz numer wiersza ktory chcesz usunac: ";
                cin >> x;
                kasuj_wiersz("zoologiczny.txt", x); break;
            case '3':
                cout << "Podaj jaki atrybut chcesz zmienic:\n1-gatunek\n2-rasa\n3-plec\n4-umarszczenie\n5-liczba_sztuk\n6-cena_jednostkowa\n7-data dostawy\n8-uwagi" << endl;
                int wybor2;
                cin >> wybor2;
                if (wybor2 == 1)
                {
                    cout << "Wpisz nowy gatunek:" << endl;
                    cin >> baza[0].gatunek;
                    cout << "Dane zostaly zmienione!" << endl;
                }
                else if (wybor2 == 2)
                {
                    cout << "Wpisz nowa rase:" << endl;
                    cin >> baza[0].rasa;
                    cout << "Dane zostaly zmienione!" << endl;
                }
                else if (wybor2 == 3)
                {
                    cout << "Wpisz nowa plec:" << endl;
                    cin >> baza[0].plec;
                    cout << "Dane zostaly zmienione!" << endl;
                }
                else if (wybor2 == 4)
                {
                    cout << "Wpisz nowe umarszczeie:" << endl;
                    cin >> baza[0].umarszczenie;
                    cout << "Dane zostaly zmienione!" << endl;
                }
                else if (wybor2 == 5)
                {
                    cout << "Wpisz nowa liczbe sztuk:" << endl;
                    cin >> baza[0].liczba_sztuk;
                    cout << "Dane zostaly zmienione!" << endl;
                }
                else if (wybor2 == 6)
                {
                    cout << "Wpisz nowa cene:" << endl;
                    cin >> baza[0].cena;
                    cout << "Dane zostaly zmienione!" << endl;
                }
                else if (wybor2 == 7)
                {
                    cout << "Wpisz nowa date dostwy:" << endl;
                    cin >> baza[0].data_dostawy;
                    cout << "Dane zostaly zmienione!" << endl;
                }
                else if (wybor2 == 8)
                {
                    cin >> baza[0].uwagi;
                    cout << "Dane zostaly zmienione!" << endl;
                }
                else
                {
                    cout << "zly znak" << endl;

                }
                break;
            case '4':

                cout << "podaj szukany wyraz" << endl;
                cin >> slowo;
                cout << znajdz(baza, slowo);
                break;
            case '5': zapis_do_pliku(baza); break;
            case '6': wyswietl(baza); break;
                case '7':
                    wczytaj_baze(baza);
                    /*
                    ifstream odczyt("zoologiczny.txt");

                    if (odczyt.is_open())
                    {
                        char wiersz[10000];
                        while (odczyt.getline(wiersz, 10000))
                        {
                            cout << wiersz << endl;
                        }
                    }
                    else
                        cout << "Nie udalo sie otworzyc pliku";

                        */
                    break;
            case '8': return 0; break;

                if (wybor >= 9)
                {
            default: cout << "bledny znak" << endl;
                }

            }
           // wczytaj_baze(baza);
        /* ifstream odczyt("zoologiczny.txt");

            if (odczyt.is_open())
            {
                char wiersz[10000];
                while (odczyt.getline(wiersz, 10000))
                {
                    cout << wiersz << endl;
                }
            }
            else
                cout << "Nie udalo sie otworzyc pliku";*/
       


           
        
        /*if (operacja = wyszukanie)
        {
            cout << "Kaplica" << endl;
        }
        /*if (operacja == odczyt)
        {
            ifstream odczyt("zoologiczny.txt");

            if (odczyt.is_open())
            {
                char wiersz[10000];
                while (odczyt.getline(wiersz, 10000))
                {
                    cout << wiersz << endl;
                }
            }
            else
                cout << "Nie udalo sie otworzyc pliku";
        }
        */
    }
	return 0;
}