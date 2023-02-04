#include <iostream>
using namespace std;

void rekurzija(int*,int, int, int);

void rekurzija(int* niz, int n, int vel, int brojac = 0) {
	if (n<0||brojac==vel){
		return; }
	else {
		cout << n << endl;
		*(niz + brojac) = n;
		return rekurzija(niz,n * 2, vel, brojac + 1); }
}

int main() {
	int n = 2;
	int vel;
	cout << "Unesite velicinu din niza: " << endl;  cin >> vel;
	int* niz = new int[vel];
	rekurzija(niz,n, vel);
	for (int i = 0; i < vel; i++) {
		cout << *(niz + i) << endl; }
	delete[] niz;
	niz = nullptr;
}