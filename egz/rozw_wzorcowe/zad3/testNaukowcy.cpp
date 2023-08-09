/*testowanie, klasa Naukowcy © Michal Dabrowski*/

#include <iostream>
#include "Naukowiec.h"
#include "Naukowcy.h"
using namespace std;

int main () {
	Naukowiec Bogdan("Bogdan",30,200), Czeslaw("Czeslaw",100,700), Iwo("Iwo",200,3000), Kazik("Kazik",150,1500);
	Naukowcy gr1("FUW"), gr2("CFT"), gr3;
	gr1+=Bogdan;
	gr1+=Czeslaw;
	gr2+=Iwo;
	gr2+=Kazik;
	gr3 = gr1 + gr2;
	cout << "Grupa pierwsza: " << gr1;
	cout << "\nNajlepszy naukowiec: ";
    cout << ++gr1 << endl;
	cout << endl << "Grupa druga: " << gr2;
	cout << "\nNajgorszy naukowiec: ";
	cout << --gr2 << endl;
	cout << "\nSrednie indeksy grup:\n" << gr1.sredIndeks() << "\n" << gr2.sredIndeks() << endl;
	cout << "\nLepsza grupa to: ";
	if(gr1 < gr2)
		cout << gr2;
	else
		cout << gr1;
    cout << "\nPolaczone grupy: ";
    cout << gr3;
    cout << "\nIndeks grupy polaczonej: " << gr3.sredIndeks();
}
