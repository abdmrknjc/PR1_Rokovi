#include <iostream>
using namespace std;

void rekurzijaFib(int*, int, int);
void ispis(int*, int);

void rekurzijaFib(int* niz, int vel, int brojac=0) {
	if (brojac==vel) {
		return;
	}
	if (brojac == 0) {
		*(niz + 0) = 1;
		*(niz + 1) = 1;
		brojac++;
	}
	else
	{
		int temp = *(niz + brojac - 1) + *(niz + brojac - 2);
		if (temp < 0)
			return;
		*(niz + brojac) = temp;
	}
	return rekurzijaFib(niz, vel, brojac+1);
}

void ispis(int* niz, int vel) {
	for (int i = 0; i < vel; i++)
	{
		cout << *(niz + i) << endl;
	}
}

int main() {
	int vel;
	cout << "Unesite velicinu 1d din niza: " << endl; cin >> vel;
	int* niz = new int[vel];
	rekurzijaFib(niz, vel);
	ispis(niz, vel);

	delete[]niz;
	niz = nullptr;
}