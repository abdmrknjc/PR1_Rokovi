#include <iostream>
using namespace std;

int obrni(int);
int sumaCifara(int);

int obrni(int n){
	int novi = 0; int cifra = 0;
	while (n)
	{
		cifra = n % 10;
		novi = novi * 10 + cifra;
		n /= 10;
	}
	return novi;
}

int sumaCifara(int n) {
	int suma = 0; int cifra = 0;
	while (n)
	{
		cifra = n % 10;
		suma += cifra;
		n /= 10;
	}
	return suma;
}

int main() {
	int x, y;
	do {
	cout << "Unesite x: " << endl; cin >> x;
	cout << "Unesite y: " << endl; cin >> y;
	} while (x<10||x>5000||y<10||y>5000);
	for (int i = x; i <= y; i++)
	{
		if (obrni(i)%sumaCifara(i)==0)
		{
			cout << i << endl;
		}
	}
}