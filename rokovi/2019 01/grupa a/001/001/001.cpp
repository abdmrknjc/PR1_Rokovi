#include <iostream>
using namespace std;

int makeNumber() {
	int novi = 0;
	int cifra;
	do
	{
		cout << "Unesite cifru: " << endl;
		cin >> cifra;
		if (cifra>0&&cifra<9)
		{
			novi = novi * 10 + cifra;
		}
	} while (cifra>0&&cifra<9);
	return novi;
}

int main() {
	cout << "Broj sastavljen od zadanih cifara je: " << makeNumber();
}