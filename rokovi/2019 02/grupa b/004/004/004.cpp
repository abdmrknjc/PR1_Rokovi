#include <iostream>
#include <ctime>
using namespace std;

struct figura
{
    //int ID;
    //char *nazivFigure;
    float *visinaFigure;

    figura() {
        //ID = 0;
        //nazivFigure = new char[16];
        visinaFigure = new float;
    }

    void unos() {
        //cout << "Unesite ID figure: " << endl; cin >> ID; cin.ignore();
        //cout << "Unesite naziv figure: " << endl; cin.getline(nazivFigure, 16);
        //cout << "Unesite visinu figure: " << endl; 
        *visinaFigure=rand()%9+1.0f;
    }

    void ispis() {
        //cout << "ID: " << ID << endl;
        //cout << "Naziv figure: " << nazivFigure, 16; cout << endl;
       //cout << "Visina figure: " << *visinaFigure << endl;
    }

    ~figura() {
       // delete nazivFigure; nazivFigure = nullptr;
        delete visinaFigure; visinaFigure = nullptr;
    }
};

void unos(figura**, int);
void ispis(figura**, int);
float* simetrija(figura**, int);
void dealokacija(figura**, int);

void unos(figura** niz, int vel) {
    for (int i = 0; i < vel; i++)
    {
        for (int j = 0; j < vel; j++)
        {
            (*(niz + i) + j)->unos();
        }
    }
}

void ispis(figura** niz, int vel) {
    for (int i = 0; i < vel; i++)
    {
        for (int j = 0; j < vel; j++)
        {
            (*(niz + i) + j)->ispis();
        }
    }
}

float* simetrija(figura** niz, int vel) {
    float* zbir = new float(0);
    for (int i = 0; i < vel; i++)
    {
        for (int j = 0; j < vel; j++)
        {
            if ((i+j)%2!=0)
            {
                if (*(*(niz+i)+j)->visinaFigure == *(*(niz + j) + i)->visinaFigure)
                {
                    *zbir += *(*(niz + i) + j)->visinaFigure * 2;
                }
                else
                {
                    delete zbir;
                    return new float(-1);
                }
            }
        }
    }
    return zbir;
}

void dealokacija(figura** niz, int vel) {
    for (int i = 0; i < vel; i++)
    {
        delete[] * (niz + i);
        *(niz + i) = nullptr;
    }
    delete[] niz;
    niz = nullptr;
}


int main() {
    srand(time(NULL));
    int vel;
    cout << "Unesite velicinu redova i kolona: " << endl; cin >> vel;
    figura** niz = new figura * [vel];
    for (int i = 0; i < vel; i++) {
        *(niz + i) = new figura[vel];
    }
    unos(niz, vel);
    ispis(niz, vel);
    float* zbir = simetrija(niz, vel);
    cout << "Adresa u kojoj je upisan zbir visina figura: " << zbir;
    dealokacija(niz, vel);
    delete zbir;
}
