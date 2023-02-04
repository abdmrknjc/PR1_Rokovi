#include <iostream>
using namespace std;

void rekurzija(int*, int,int);

void rekurzija(int* niz, int vel, int brojac = 0) {
	if (brojac==vel)
	{
		return;
	}
	if (brojac==0)
	{
		*(niz + brojac) = 2;
	}
	else
	{
		int temp = *(niz + brojac - 1) * 2;
		if (temp<0)
		{
			return;
		}
		else
		{
			*(niz + brojac) = temp;
		}
	}
	rekurzija(niz, vel, brojac + 1);
}

int main() {
	int vel;
	cout << "Unesite velicinu 1d din niza: " << endl; cin >> vel;
	int* niz = new int[vel];
	rekurzija(niz, vel);
	for (int i = 0; i < vel; i++) {
	cout << *(niz + i) << endl;
	}
}