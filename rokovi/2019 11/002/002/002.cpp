#include <iostream>
using namespace std;

int novi(int,int);
bool provjeraCifaraB(int,int);

int novi(int a,int b) {
	int cifra = 0;
	int noviBr = 0;
	while (a)
	{
		cifra = a % 10;
		if (!provjeraCifaraB(cifra,b))
		{
		noviBr = noviBr * 10 + cifra;
		a /= 10;
		}
		else
		{
			a /= 10;
		}
	}
	return noviBr;
}

bool provjeraCifaraB(int cifra,int B) {
	while (B)
	{
		if (cifra==B%10)
		{
			return true;
		}
		B /= 10;
	}
	return false;
}

int main() {
	int a; int b; int c;
	do
	{
		cout << "Unesite a, vece od 100000: " << endl; cin >> a;
		cout << "Unesite b, vece od 50000: " << endl; cin >> b;
	} while (a<100000||b<50000);
	c = novi(a, b);
	cout << "A: " << a << endl;
	cout << "B: " << b << endl;
	cout << "C: " << c << endl;
	cout << "A-C: " << a - c << endl;
}