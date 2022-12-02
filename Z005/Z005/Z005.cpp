#include <iostream>
using namespace std;

/*Napisati program u kojem je potrebno unijeti odabrani broj cifara
pocevsi od cifre najvece tezinske vrijednosti,pa od njih sastaviti i ispisati prirodni broj.
Unos cifara se prekida kada se unese broj manji od 0 ili veci od 9. Ispis neka bude oblika:

Upisi cifru: 2
Upisi cifru: 8
Upisi cifru: -1
Broj sastavljen od zadanih cifara je 28.
*/

int unos() {
	int broj = 0;
	int cifra = 0;
	while (1)
	{
		cout << "Upisi cifru: " << endl;
		cin >> cifra;
		if (cifra < 0 || cifra > 9) {
			break;
		}
		else
		{
			broj = broj * 10 + cifra;
		}
	}
	return broj;
}

int main() {
	cout << "Broj sastavljen od zadanih cifara je: " << unos();
	return 0;
}