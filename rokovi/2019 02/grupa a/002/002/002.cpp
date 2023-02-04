#include <iostream>
#include <ctime>
using namespace std;

void bacanje(int);

void bacanje(int n) {
	int brojbacanja = 0; int case1 = 0; int case2 = 0; int case3 = 0;
	int case4 = 0; int case5 = 0; int case6 = 0;
	while (n>brojbacanja)
	{
		int kocka = rand() % 6 + 1;
		switch (kocka)
		{
		case 1: {case1++; brojbacanja++; }; break;
		case 2: {case2++; brojbacanja++; }; break;
		case 3: {case3++; brojbacanja++; }; break;
		case 4: {case4++; brojbacanja++; }; break;
		case 5: {case5++; brojbacanja++; }; break;
		case 6: {case6++; brojbacanja++; }; break;
		default:
			break;
		}
	}
	cout << "Postotak bacanja sa ishodom 1 je: " << case1 * 100 / brojbacanja << " %." << endl;
	cout << "Postotak bacanja sa ishodom 2 je: " << case2 * 100 / brojbacanja << " %." << endl;
	cout << "Postotak bacanja sa ishodom 3 je: " << case3 * 100 / brojbacanja << " %." << endl;
	cout << "Postotak bacanja sa ishodom 4 je: " << case4 * 100 / brojbacanja << " %." << endl;
	cout << "Postotak bacanja sa ishodom 5 je: " << case5 * 100 / brojbacanja << " %." << endl;
	cout << "Postotak bacanja sa ishodom 6 je: " << case6 * 100 / brojbacanja << " %." << endl;
}

int main() {
	int n; 
	do
	{
	cout << "Unesite n, n=>10 i n<=1000: " << endl; cin >> n;
	} while (n<10||n>1000);
	bacanje(n);
}