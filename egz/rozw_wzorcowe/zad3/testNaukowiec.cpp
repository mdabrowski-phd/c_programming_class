/*testowanie, klasa Naukowiec © Michal Dabrowski*/

#include <iostream>
#include "Naukowiec.h"
using namespace std;

int main () {
	Naukowiec Bogdan("Bogdan",50,300), Czeslaw; //tworzenie Naukowcow Bogdan i Czeslaw
	cin >> Czeslaw; //wczytujemy informacje o Naukowcu Czeslaw
	cout << Czeslaw.indeks() << endl; //obliczamy indeks dla Naukowiec Czeslaw
	Bogdan.publikuj(3); //dodajemy trzy publikacje dla Naukowiec Bogdan
	if(Bogdan < ++Czeslaw) //jezeli Naukowiec Bogdan gorszy niz Naukowiec Czeslaw po dodaniu jednego cytowania, to ...
		cout << Czeslaw << endl; //... lepszy jest Naukowiec Czzeslaw
	else
		cout << Bogdan << endl; //... lepszy jest Naukowiec Bogdan
}
