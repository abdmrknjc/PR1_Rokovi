#include <iostream>
using namespace std;

int napraviNovi(int);
int obrni(int);

int napraviNovi(int n) {
	int novi = 0;
	int cifra = 0;
	while (n)
	{
		cifra = n % 10;
		if (cifra%2==0)
		{
			cifra = 5;
			novi = novi * 10 + cifra;
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

int obrni(int novi) {
	int obrnuti = 0;
	int cifra = 0;
	while (novi)
	{
		cifra = novi % 10;
		obrnuti = obrnuti * 10 + cifra;
		novi /= 10;
	}
	return obrnuti;
}

int main() {
	int n;
	do {
	cout << "Unesite pozitivan broj n: " << endl; cin>>n;
	} while (n<1);
	int novi = napraviNovi(n);
	cout << "Broj dobiven nakon operacija je: " << obrni(novi);
}