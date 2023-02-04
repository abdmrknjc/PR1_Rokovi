#include <iostream>
using namespace std;

void rekurzijaFaktorijela(int*, int, int);

void rekurzijaFaktorijela(int* niz, int vel, int brojac = 0) {
	if (brojac==vel)
		return;
	if (brojac==0||brojac==1) {
		*(niz + brojac) = 1;
		return rekurzijaFaktorijela(niz, vel, brojac + 1);
	}
	int temp = brojac * *(niz + brojac - 1);
	if (temp<0){
		return;
	}
	else {
		*(niz + brojac) = temp;
		return rekurzijaFaktorijela(niz, vel, brojac + 1);
	}
}

int main() {
	int vel;
	cout << "Unesite velicinu 1d din niza: " << endl; cin >> vel;
	int* niz = new int[vel];
	rekurzijaFaktorijela(niz, vel);
	for (int i = 0; i < vel; i++) {
		cout << *(niz + i) << endl;
	}
	delete[] niz;
	niz = nullptr;
}