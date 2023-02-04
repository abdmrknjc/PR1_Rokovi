#include <iostream>
using namespace std;

int noviBr(int& n) {
	int novi = 0;
	int cifra = 0;
	while (n)
	{
		cifra = n % 10;
		if (cifra%2!=0) {
			n /= 10;
		}
		else
		{
			novi = novi * 10 + cifra;
			n /= 10;
		}
	}
	return novi;
}

int main() {
	int n;
	do
	{
		cout << "Unesite broj n,veci od 50 a manji od 5 miliona: " << endl; cin >> n;
	} while (n<50||n>5000000);
	cout << noviBr(n);
}