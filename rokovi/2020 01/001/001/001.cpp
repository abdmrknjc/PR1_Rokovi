#include <iostream>
using namespace std;

int main() {
	int novi=0; int cifra;
	while (cout << "Unesite cifru: " << endl,cin>>cifra,cifra>0&&cifra<9) {
		novi = novi * 10 + cifra;
	}
	cout << "Broj sastavljen od zadanih cifara je: " << novi;
}