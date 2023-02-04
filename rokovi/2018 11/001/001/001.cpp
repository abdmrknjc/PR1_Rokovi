#include <iostream>
using namespace std;

int faktorijel(int n) {
	int faktorijel = 1;
	for (int i = 1; i <= n; i++) {
		faktorijel *= i;
	}
	return faktorijel;
}
int main() {
	int n;
	do
	{
		cout << "Unesite cijeli broj n: " << endl; cin >> n;
	} while (n<0);
	int suma = 0;
	for (int i = 1; i <= n; i+=2)
	{
		suma+=faktorijel(i);
	}
	cout << "Suma faktorijela od 1 do " << n << " je: " << suma << endl;
}