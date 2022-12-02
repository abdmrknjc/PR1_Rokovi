#include <iostream>
using namespace std;

// 30.01.2021.

/*Napisati program koji korisniku omogucava unos realnog broja x
i odabir funkcije za proracun datog izraza. Korisnik bira funkciju unosom sljedecih karaktera 's' (sin), 'c' (cos).
U slucaju da korisnik unese karakter koji ne odgovara niti jednoj od predefinisanih vrijednosti ispisati odgovarajucu poruku i ponoviti odabir.

Za odabranu funkciju sin izraz je:

f(x,m)=1 + 1/((sin(x) + x) + 2/(sin(x/2)) + x + ... + m/(sin(x/m)) + x

*/

float unosBroja() {
	float broj;
	cout << "Unesite realan broj x: " << endl;
	cin >> broj;
	return broj;
}


float izracun(float broj) {
	char izbor;
	while (cout << "Izaberte funkciju s - sin, c - cos: ", cin >> izbor, izbor != 's' && izbor != 'c')
		cout << "Odabrali ste nepostojucu funkciju" << endl;

	float rezultat = 0;
	if (izbor == 's')
		for (int i = 1; i <= broj; i++) rezultat += i / (sin(broj / i) + broj);
	else
		for (int i = 1; i <= broj; i++) rezultat += i / (cos(broj / i) + broj);

	return rezultat;

}

int main() {
	float x = unosBroja();
	cout << "Rezultat je: " << izracun(x);

	return 0;
}