#include <iostream>
using namespace std;
bool isProst(int);
bool isPalindrom(int);

bool isProst(int broj) {
	for (int i = 2; i < broj; i++)
	{
		if (broj%i==0)
		{
			return false;
		}
	}
	return true;
}

bool isPalindrom(int broj) {
	int temp = broj; int cifra = 0; int novi = 0;
	while (broj)
	{
		cifra = broj % 10;
		novi = novi * 10 + cifra;
		broj /= 10;
	}
	if (novi==temp)
	{
		return true;
	}
	return false;
}

int main(){
	int broj; 
	do {
	cout << "Unesite broj veci od 100: " << endl; cin >> broj;
	} while (broj<100);
	if (isProst(broj)&&isPalindrom(broj)) {
		cout << "Broj "<< broj<< " je u isto vrijeme i prost i palindrom." << endl;
	}
	else
	{
		cout << "Broj " << broj << " nije u isto vrijeme i prost i palindrom." << endl;
	}
}