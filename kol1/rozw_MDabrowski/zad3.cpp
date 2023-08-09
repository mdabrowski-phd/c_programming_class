#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Podaj dlugosc ciagu n prowadzacego: ";
	cin >> n;
	int m, sum_p=0, sum_s=0;
	cout << "Ciag prowadzacego cwiczenia: ";
	for(int i=0; i<n; i++) {
		cin >> m;
		sum_p+=m;
	}
	cout << "Ciag niesfornego studenta: ";
	for(int i=0; i<n-1; i++) {
		cin >> m;
		sum_s+=m;
	}
	cout << "Niesforny student zmazal liczbe " << sum_p-sum_s << "."; 
}
