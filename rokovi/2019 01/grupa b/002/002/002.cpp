#include <iostream>
using namespace std;

bool prost(int);
bool palindrom(int);
bool provjera(int);

bool prost(int x) {
	for (int i = 2; i < x; i++) {
		if (x%i==0) {
			return false;
		}
	}
	return true;
}

bool palindrom(int x) {
	int temp = 0; int cifra = 0; int pricuvna = x;
	while (x>0) {
		cifra = x % 10;
		temp = temp * 10 + cifra;
		x /= 10;
	}
	if (pricuvna==temp) {
		return true;
	}
	else 
		return false;
}

bool provjera(int x) {
	if (prost(x)&&palindrom(x)) {
		return true;
	}
	return false;
}


int main() {
	int x;
	do {
		cout << "Unesite x,vece od 100: " << endl; cin >> x;
	} while (x < 100);
	if (provjera(x)) {
		cout << "Broj " << x << " je u isto vrijeme i prost i palindrom. " << endl;
	}
	else {
		cout << "Broj nije i prost i palindrom" << endl;
	}
}