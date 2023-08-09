/*plik naglowkowy, klasa Naukowiec © Michal Dabrowski*/

#include <iostream>
using namespace std;

class Naukowiec {
		string _name;
		int _publikacje, _cytowania; //nazwisko, liczba publikacji i cytowan
	public:
		Naukowiec(); //konstruktor bezargumentowy (dla porzadku)
		Naukowiec (const string &name, int publikacje, int cytowania); //konstruktor trzyargumentowy
		double indeks(); //zwraca indeks=double(_cytowania/_publikacje)
		void publikuj (int n); //dodaje n publikacji dla danego Naukowca
		Naukowiec &operator ++ (); //dodaje jedno cytowanie dla danego Naukowca
		friend bool operator < (Naukowiec &first, Naukowiec &second); /*operator porownywania dwoch Naukowcow
		lepszy jest Naukowiec z wieksza liczba cytowan; jezeli liczba cytowan jest identyczna, lepszy jest Naukowiec majacy wiekszy indeks*/
		friend ostream &operator << (ostream &stream, const Naukowiec &naukowiec); //wypisywanie danych o Naukowcu: (_name, _publikacje, _cytowania)
		friend istream &operator >> (istream &stream, Naukowiec &naukowiec); //wczytywanie danych o Naukowcu: (_name, _publikacje, _cytowania)
};
