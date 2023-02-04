#include <iostream>
#include <ctime>
using namespace std;

bool prost(int n) {
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main() {
	srand(time(NULL));
	int n;
	do
	{
		cout << "Unesite broj n, veci od 10 i manji od 1000: " << endl; cin >> n;
	} while (n<10||n>1000);
	float brojacProstih = 0;
	int slucajniUnos = 0;
	for (int i = 1; i <= n; i++)
	{
		slucajniUnos = rand() % 10 + 1;
		if (prost(slucajniUnos))
		{
			cout << slucajniUnos << endl;
			brojacProstih++;
		}
	}
	float procenat = brojacProstih / n;
	cout << "Procenat prostih brojeva je " << procenat*100 << " %";
}
