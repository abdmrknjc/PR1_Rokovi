#include <iostream>
using namespace std;

float rezultat(float);

float rezultat(float x) {
	float rjesenje = 1;
	char izbor;
	do
	{
		cout << "Unesite s za sin, c za cos: " << endl; cin >> izbor;
	} while (izbor!='s'&&izbor!='c');
	for (int i = 1; i <= x; i++)
	{
		if (izbor == 's')
		{
			rjesenje += i / (sin(x / i) + x);
		}
		else
		{
			rjesenje += i / (cos(x / i) + x);
		}
	}
	return rjesenje;
}

int main() {
	float x;
	cout << "Unesite realan broj x:" << endl; cin >> x;
	cout << "Rezultat je: " << rezultat(x);
}