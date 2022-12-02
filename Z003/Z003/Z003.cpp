#include <iostream>
using namespace std;

/*Postujuci sve faze procesa programiranja, napisati program koji korisniku omogucava unos cijelog broja N,
te izracunava vrijednost sume faktorijela neparnih brojeva u intervalu [1, N].
Suma faktorijela prikazana je sljedecom formulom: S = 1! + 3! + 5! + ... + N!
*/

int unosn() {
	int n;
	do{
		cout << "Unesite cijeli broj N: " << endl;
		cin >> n;
	} while (n < 1);
	return n;
}

int faktorijel(int n) {
	int f = 1;
	for (int i = 2; i <= n; i++)
	{
		f = f * i;
	}
	return f;
}

int main() {
	int n = unosn();
	int suma = 0;
	for (int i = 1; i <= n; i+=2)
	{
		suma += faktorijel(i);
	}
	cout << "Suma je: " << suma;
	return 0;

}