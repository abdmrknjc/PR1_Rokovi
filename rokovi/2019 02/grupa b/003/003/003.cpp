#include <iostream>
#include <ctime>
using namespace std;

void rekurzija(int*, int, int);

void rekurzija(int* niz, int vel, int brojac = 0) {
	int temp = rand() % 100 + 1;
	if (brojac==vel)
	{
		return;
	}
	else if (temp==*(niz+brojac-1)&&temp==*(niz+brojac-2))
	{
		return;
	}
	else
	{
		*(niz + brojac) = temp;
		rekurzija(niz, vel, brojac + 1);
	}
}

int main() {
	int vel;
	cout << "Unesite velicinu 1d din niza: " << endl; cin >> vel;
	int* niz = new int[vel];
	rekurzija(niz, vel);
	for (int i = 0; i < vel; i++)
	{
		cout << *(niz + i) << endl;
	}
	delete[] niz;
	niz = nullptr;
}