#include <iostream>
#include <ctime>
using namespace std;

struct kosarkas
{
    char* ID;
    char* imePrezime;
    int* postignutiKosevi;

    kosarkas() {
        ID = new char[11];
        imePrezime = new char[26];
        postignutiKosevi = new int;
    }

    void unos() {
        cin.ignore();
        cout << "Unesite ID: " << endl;
        cin.getline(ID, 11);
        cout << "Unesite ime i prezime: " << endl;
        cin.getline(imePrezime, 26);
        cout << "Unesite broj postignutih koseva: " << endl;
        cin >> *postignutiKosevi;
    }

    void ispis() {
        cout << "ID: " << ID, 6; cout << endl;
        cout << "Ime i prezime: " << endl;
        cout << "Kosevi: " << *postignutiKosevi << endl;
    }

    ~kosarkas() {
        delete ID;
        ID = nullptr;
        delete imePrezime;
        imePrezime = nullptr;
        delete postignutiKosevi;
        postignutiKosevi = nullptr;
    }
};

void unos(kosarkas**, int, int);
void ispis(kosarkas**, int, int);
int* najKlub(kosarkas**, int, int);
void dealokacija(kosarkas**&, int);

void unos(kosarkas** niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            (*(niz + i) + j)->unos();
        }
    }
}

void ispis(kosarkas** niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            (*(niz + i) + j)->ispis();
        }
    }
}

int* najKlub(kosarkas** niz, int red, int kolona) {
    int* nizKlubova = new int[kolona] {};
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(nizKlubova + i) += *(*(niz + j) + i)->postignutiKosevi;
        }
    }
    int indeksKluba = 0;
    for (int i = 0; i < kolona; i++)
    {
        if (*(nizKlubova+i)>*(nizKlubova+indeksKluba))
        {
            indeksKluba = i;
        }
    }
    cout << "Najklub je klub sa indeksom " << indeksKluba << endl;
    int* najKosarkas = new int[red];
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(najKosarkas + i) = *(*(niz + i) + indeksKluba)->postignutiKosevi;
        }
    }
    int indexKosarkasa = 0;
    for (int i = 0; i < red; i++)
    {
        if (*(najKosarkas+i)>*(najKosarkas+indexKosarkasa))
        {
            indexKosarkasa = i;
        }
    }
    cout << "Najbolji kosarkas najboljeg je kosarkas sa IDom: " << *(*(niz + indexKosarkasa) + indeksKluba)->ID << endl;
    int najbolji = *(*(niz + indexKosarkasa) + indeksKluba)->postignutiKosevi;
    int* najgoriKosarkas = new int[red];
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(najgoriKosarkas + i) += *(*(niz + i) + j)->postignutiKosevi;
        }
    }
    int indexNajgoregKosarkasa = 0;
    for (int i = 0; i < red; i++)
    {
        if (*(najgoriKosarkas + i) > *(najgoriKosarkas + indexNajgoregKosarkasa))
        {
            indexNajgoregKosarkasa = i;
        }
    }
    int najgori = *(najgoriKosarkas + indexNajgoregKosarkasa);
    int razlikaKosarkasa = abs(najbolji - najgori);
    cout << "Razlika kosarkasa: " << razlikaKosarkasa << endl;
    delete[] nizKlubova;
    nizKlubova = nullptr;
    delete[] najKosarkas;
    najKosarkas = nullptr;
    delete[] najgoriKosarkas;
    najgoriKosarkas = nullptr;
    return new int(razlikaKosarkasa);
}

void dealokacija(kosarkas**& niz, int red) {
    for (int i = 0; i < red; i++)
    {
        delete[] * (niz + i);
        *(niz + i) = nullptr;
    }
    delete[]niz;
    niz = nullptr;
}


int main() {
    int red, kolona;
    cout << "Unesite br redova: " << endl; cin >> red;
    cout << "Unesite br kolona: " << endl; cin >> kolona;
    kosarkas** niz = new kosarkas * [red];
    for (int i = 0; i < red; i++)
    {
        *(niz + i) = new kosarkas[kolona];
    }
    unos(niz, red, kolona);
    ispis(niz, red, kolona);
    najKlub(niz, red, kolona);
    dealokacija(niz, red);
}