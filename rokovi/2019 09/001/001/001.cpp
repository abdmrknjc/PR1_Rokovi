#include <iostream>
using namespace std;

int main() {
	int n;
	do {
	cout << "Unesite prirodan broj n: " << endl; cin >> n;
	} while (n<1);
	double suma = 0;
	for (int i = 1; i <= n; i++)
	{
		suma += 1 / pow((2 * i) + 1, 2);
	}
	cout << "Rezultat: " << suma;
}