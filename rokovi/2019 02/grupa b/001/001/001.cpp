#include <iostream>
#include <iomanip>
using namespace std;

float sredina(int);

float sredina(int n) {
	float gSredina = 1;
	int brojac = 0;
	for (int i = 0; i <= n; i++)
	{
		if (i%5!=0)
		{
		gSredina *= i;
		brojac++;
		}
	}
	return pow(gSredina, 1 / brojac);
}

int main() {
	int n;
	cout << "Unesite cijeli broj n:" << endl; cin >> n;
	cout << "Geometrijska sredina je: " << setprecision(3) << sredina(n);
}