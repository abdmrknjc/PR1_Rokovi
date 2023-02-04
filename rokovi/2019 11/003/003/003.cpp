#include <iostream>
#include <ctime>
using namespace std;

void unos(int**, int);
void ispis(int**, int);

void unos(int** niz, int vel) {
	for (int i = 0; i < vel; i++)
	{
	int unos; 
	//cout << "Unesite broj: " << endl; 
	unos=rand() % 9 + 1;
	int temp = unos;
	int brojac = 0;
	while (unos)
	{
		brojac++;
		unos /= 10;
	}
		for (int j = 0; j < vel; j++)
		{
			if ((i + j) % 2 == 0 && temp % 2 == 0 && brojac % 2 != 0)
			{
				*(*(niz + i) + j)=temp;
			}
			else if ((i + j) % 2 != 0 && temp % 2 != 0 && brojac % 2 == 0)
			{
				*(*(niz + i) + j) = temp;
			}
		}
	}
}

void ispis(int** niz, int vel) {
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			cout << *(*(niz + i) + j) << " ";
		}
		cout << endl;
	}
}

int main() {
	srand(time(NULL));
	int vel = 8;
	int** niz = new int* [vel];
	for (int i = 0; i < vel; i++)
	{
		*(niz + i) = new int[vel];
	}
	unos(niz, vel);
	ispis(niz, vel);
}