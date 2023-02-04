#include <iostream>
using namespace std;

int faktorijel(int);

int faktorijel(int broj) {
	int fakt = 1;
	for (int i = 1; i <= broj; i++)
	{
		fakt *= i;
	}
	return fakt;
}

int main() {
	int n, X;
	while (cout << "Unesite broj A: ", cin >> n, n <= 10);
	while (cout << "Unesite broj B: ", cin >> X, X < 1);

	double S = 0;
	for (int i = 0; i < n; i++)
	{
		S += pow(-1, i) * i / pow(X, i);
	}

	cout << S;
	return 0;
}