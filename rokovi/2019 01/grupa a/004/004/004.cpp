#include <iostream>
#include <ctime>
using namespace std;

struct uposlenik
{
    char* ID;
    char* imePrezime;
    float* plata;

    uposlenik() {
        ID = new char[11];
        imePrezime = new char[26];
        plata = new float;
    }

    void unos() {
        /*cin.ignore();
        cout << "Unesite ID uposlenika: " << endl;
        cin.getline(ID, 11);
        cout << "Unesite ime i prezime uposlenika: " << endl;
        cin.getline(imePrezime, 26);
        cout << "Unesite platu uposlenika: " << endl;
        cin >> *plata;*/
        *plata = rand() % 3000 + 1500;
    }

    void ispis() {
        //cout << "ID: " << ID, 11; cout << endl;
        //cout << "Ime i prezime: " << imePrezime, 26; cout << endl;
        cout << "Plata: " << *plata << endl;
    }

    ~uposlenik() {
        delete[]ID;
        ID = nullptr;
        delete[]imePrezime;
        imePrezime = nullptr;
        delete plata;
        plata = nullptr;
    }
};

void unos(uposlenik**, int, int);
void ispis(uposlenik**, int, int);
void najOdjel(uposlenik**, int, int);
void dealokacija(uposlenik**&, int);

void unos(uposlenik** niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            (*(niz + i) + j)->unos();
        }
    }
}

void ispis(uposlenik** niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            (*(niz + i) + j)->ispis();
        }
    }
}

void najOdjel(uposlenik** niz, int red, int kolona) {
    float* najProsjek = new float[red] {};
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(najProsjek + i) += *(*(niz + i) + j)->plata;
        }
        *(najProsjek + i) /= kolona;
    }
    int indeks = 0;
    for (int i = 0; i < red; i++)
    {
        if (*(najProsjek + i) > *(najProsjek + indeks)) {
            indeks = i;
        }
    }
    cout << "Najbolji odjel je odjel sa indeksom: " << indeks << endl;
    cout << "Najbolji prosjek plate je: " << *(najProsjek + indeks) << endl;
}

void dealokacija(uposlenik**& niz, int red) {
    for (int i = 0; i < red; i++){
        delete[] * (niz + i);
        *(niz + i) = nullptr;
    }
    delete[] niz;
    niz = nullptr;
}


int main() {
    srand(time(NULL));
    int red, kolona;
    cout << "Unesite br redova: " << endl; cin >> red;
    cout << "Unesite br kolona: " << endl; cin >> kolona;
    uposlenik** niz = new uposlenik*[red];
    for (int i = 0; i < red; i++) {
        *(niz + i) = new uposlenik[kolona];
    }
    unos(niz, red, kolona);
    ispis(niz, red, kolona);
    najOdjel(niz, red, kolona);
    dealokacija(niz, red);
}