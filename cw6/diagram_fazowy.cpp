/*kolokwium 1, rozwiazanie zadania z diagramem fazowym (autor: M. Dabrowski)
-> rozwiazanie o zlozonosci czasowej O(n) - mozna skorzystac z wyszukiwania binarnego (tablica jest wstepnie
posortowana) o zlozonosci O(log n), jednak wczytywanie danych powoduje, ze ostatecznie konczymy w O(n)
-> w przypadku gdy nie istnieje prosta ograniczajaca punkt z gory lub z dolu, nadajemy jej numer (-1)*/

#include <iostream>

using namespace std;

int main() {
	int n;
	double x0, y0;
	cout << "Podaj n: ";
	cin >> n;
	cout << "Podaj punkt (x0,y0): ";
	cin >> x0 >> y0;
	double y[n];
	double a, b;
	for(int i=0; i<n; i++) {
		cout << "Podaj parametry a" << i << " oraz b" << i <<" : ";
		cin >> a >> b;
		y[i]=a*x0+b;	
	}
	int min, max;
	for(min=0; min<n && y[min]<=y0 ; min++);
	for(max=n-1; max>=0 && y[max]>=y0 ; max--);
	cout << "Dolna prosta nr " << min-1 << ", gorna prosta nr " << max+1 << endl;
	return 0;
}
