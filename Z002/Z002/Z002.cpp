#include <iostream>
#include <ctime>
using namespace std;

/*Napisati program koji simulira bacanje 3 kockice (jedna kockica ima 6 strana i na tim stranama su brojevi 1 - 6).
Simuliranje bacanja svake kockice ostvariti funkcijom rand() % 6 + 1.
Simulirati konstantno bacanje sve tri kockice dok se u dva uzastopna bacanja ne desi da se dobiju
isti brojevi na sve tri kockice (npr. u šestom bacanju se dobiju brojevi 2, 2, 2 a u sedmom 4,4,4 na sve tri kockice).
Ispisati koliko je ukupno bilo bacanja dok se nije ispunio navedeni uslov. Nije potrebno tražiti bilo kakav unos od korisnika.
*/



int main() {
	int kocka1, kocka2, kocka3;
	int brojac = 0;
	int bacanje = 0;
	srand(time(NULL));
	do
	{
		kocka1 = rand() % 6 + 1;
		kocka2 = rand() % 6 + 1;
		kocka3 = rand() % 6 + 1;
		if (kocka1==kocka2 && kocka1==kocka3)
		{
			brojac++;
		}
		else
		{
			brojac = 0;
		}
		bacanje++;

	} while (brojac<2);
	cout << "Broj bacanja je: " << bacanje;
}