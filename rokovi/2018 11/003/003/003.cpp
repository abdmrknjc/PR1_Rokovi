#include <iostream>
#include <ctime>
using namespace std;

void unos(int[8][8]);
void ispis(int[8][8]);
int najProsjek(int[8][8]);

void unos(int niz[8][8]) {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			
			if (i % 2 != 0)
			{
				do {
					niz[i][j]=rand()%9+1;
				} while (niz[i][j] % 2 != 0);
			}
			else
			{
				do {
					niz[i][j] = rand() % 9 + 1;
				} while (niz[i][j] % 2 == 0);
			}
		}
	}
}

void ispis(int niz[8][8]) {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << niz[i][j] << " ";
		}
		cout << endl;
	}
}

int najProsjek(int niz[8][8]) {
	int* najProsjekVar = new int[8] {};
	int indeksKolone = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			*(najProsjekVar+i) += niz[j][i];
		}
		cout << *(najProsjekVar + i) << endl;
		*(najProsjekVar + i) /= 8;
	}
	for (int j = 0; j < 8; j++)
	{
		if (*(najProsjekVar + j)<*(najProsjekVar+indeksKolone))
		{
			indeksKolone = j;
		}
	}
	cout << "Indeks kolone s najboljim prosjekom je: " << indeksKolone << endl;
	return indeksKolone;
}


int main() {
	srand(time(NULL));
	int niz[8][8] = {};
	unos(niz);
	ispis(niz);
	int index = najProsjek(niz);
	for (int i = 0; i < 8; i++)
	{
		cout << niz[i][index] << " ";
	}
}