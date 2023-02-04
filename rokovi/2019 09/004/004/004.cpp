#include <iostream>
using namespace std;

struct fudbaler
{
	int* godRodjenja;
	int* brojIgraca;
	int* golovi;

	fudbaler() {
		godRodjenja = new int;
		brojIgraca = new int;
		golovi = new int;
	}
	void unos() {
		*godRodjenja = 1980 + rand() % ((2000 + 1) - 1980);
		*brojIgraca = rand() % 30 + 1;
		*golovi = rand() % 5;
	}

	void ispis() {
		cout << "Godina rodjenja: " << *godRodjenja << endl;
		cout << "Broj igraca: " << *brojIgraca << endl;
		cout << "Golovi: " << *golovi << endl;
	}

	~fudbaler() {
		delete godRodjenja; godRodjenja = nullptr;
		delete brojIgraca; brojIgraca = nullptr;
		delete golovi; golovi = nullptr;
	}
};

void unos(fudbaler**, int, int);
void ispis(fudbaler**, int, int);
void najTim(fudbaler**, int, int);
void najFudbalerNajgoregTima(fudbaler**, int, int);
void dealokacija(fudbaler**&, int);

void unos(fudbaler** niz, int red, int kolona) {
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			(*(niz + i) + j)->unos();
		}
	}
}
void ispis(fudbaler** niz, int red, int kolona) {
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			(*(niz + i) + j)->ispis();
		}
	}
}
void najTim(fudbaler** niz, int red, int kolona) {
	int* najTim = new int[red] {};
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			*(najTim + i) = *(*(niz + i) + j)->golovi;
		}
		*(najTim + i) /= kolona;
	}
	int indexNajTima = 0;
	for (int i = 0; i < red; i++)
	{
		if (*(najTim+i)>*(najTim+indexNajTima))
		{
			indexNajTima = i;
		}
	}
	cout << "Najbolji tim je tim sa indeksom: " << indexNajTima << endl;
	delete[] najTim;
	najTim = nullptr;
}
void najFudbalerNajgoregTima(fudbaler** niz, int red, int kolona) {
	int* najgoriTim = new int[red] {};
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			*(najgoriTim + i) = *(*(niz + i) + j)->golovi;
		}
		*(najgoriTim + i) /= kolona;
	}
	int indexNajgoregTima = 0;
	for (int i = 0; i < red; i++)
	{
		if (*(najgoriTim + i) > *(najgoriTim + indexNajgoregTima))
		{
			indexNajgoregTima = i;
		}
	}
	int najbolji = *(*(niz + indexNajgoregTima) + 0)->golovi;
	int indexNajboljegFudbalera = 0;
	for (int j = 0; j < kolona; j++)
	{
		if (*(*(niz + indexNajgoregTima) + j)->golovi > najbolji)
		{
			indexNajboljegFudbalera = j;
		}
	}
	cout << "Najbolji fudbaler u najgorem timu je sa podacima: " << endl;
	cout << "Godina rodjenja: " << *(*(niz + indexNajgoregTima) + indexNajboljegFudbalera)->godRodjenja << endl;
	cout << "Broj igraca: " << *(*(niz + indexNajgoregTima) + indexNajboljegFudbalera)->brojIgraca << endl;
	cout << "Broj golova: " << *(*(niz + indexNajgoregTima) + indexNajboljegFudbalera)->golovi << endl;
	delete[]najgoriTim;
	najgoriTim = nullptr;
}
void dealokacija(fudbaler**& niz, int red) {
	for (int i = 0; i < red; i++)
	{
		delete[] * (niz + i);
		* (niz + i)=nullptr;
	}
	delete[] niz;
	niz = nullptr;
}
int main() {
	int red, kolona;
	cout << "Unesite broj redova: " << endl; cin >> red;
	cout << "Unesite broj kolona: " << endl; cin >> kolona;
	fudbaler** niz = new fudbaler * [red];
	for (int i = 0; i < red; i++)
	{
		*(niz + i) = new fudbaler[kolona];
	}
	unos(niz, red, kolona);
	ispis(niz, red, kolona);
	najTim(niz, red, kolona);
	najFudbalerNajgoregTima(niz, red, kolona);
	dealokacija(niz, red);
}