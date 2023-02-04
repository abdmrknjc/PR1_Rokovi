#include <iostream>
#include <ctime>
using namespace std;

struct figura
{
    int ID;
    char* nazivFigure;
    float* visinaFigure;

    figura() {
        ID = 0;
        nazivFigure = new char[11];
        visinaFigure = new float;
    }

    void unos() {
        /*cin.ignore();
        cout << "Unesite ID figure: " << endl;
        cin >> ID;
        cout << "Unesite naziv figure: " << endl;
        cin.getline(nazivFigure, 11);
        cout << "Unesite visinu figure: " << endl;*/
        *visinaFigure = rand() % 9 + 1;
    }

    void ispis() {
        /*cout << ID << endl;
        cout << (nazivFigure, 11) << endl;*/
        cout << *visinaFigure<<"   ";
    }

    ~figura() {
        delete nazivFigure;
        nazivFigure = nullptr;
        delete visinaFigure;
        visinaFigure = nullptr;
    }
};

void unos(figura**, int, int);
void ispis(figura**, int, int);
float* prosjecnaVisina(figura**, int, int);

void unos(figura** niz, int red, int kolona){
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            (*(niz + i) + j)->unos();
        }
    }
}
void ispis(figura** niz, int red, int kolona){
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            (*(niz + i) + j)->ispis();
        }
        cout << endl;
    }
}

float* prosjecnaVisina(figura** niz, int red, int kolona) {
    int zbiriij = 0;
    int brojacCrnih = 0;
    float prosjek = 0;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            if (i+j>7&&(i+j)%2==0)
            {
                prosjek += *(*(niz + i) + j)->visinaFigure;
                brojacCrnih++;
            }
        }
    }
    prosjek /= brojacCrnih;
    return new float(prosjek);
}

void dealokacija(figura** niz, int red){
    for (int i = 0; i < red; i++)
    {
        delete[] * (niz + i);
        *(niz + i) = nullptr;
    }
    delete[]niz;
    niz = nullptr;
}

int main() {
    srand(time(0));
    int red, kolona;
    cout << "Unesite br redova: " << endl; cin >> red;
    cout << "Unesite br kolona: " << endl; cin >> kolona;
    figura** niz = new figura * [red];
    for (int i = 0; i < red; i++)
    {
        *(niz + i) = new figura[red];
    }
    unos(niz, red, kolona);
    ispis(niz, red, kolona);
    cout << "Adresa sa prosjecnom visinom figura je: " << prosjecnaVisina(niz, red, kolona);
    dealokacija(niz, red);
}