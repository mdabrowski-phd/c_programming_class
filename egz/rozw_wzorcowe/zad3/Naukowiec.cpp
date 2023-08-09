/*klasa Naukowiec © Michal Dabrowski*/

#include <iostream>
#include "Naukowiec.h"
using namespace std;

Naukowiec::Naukowiec() {}

Naukowiec::Naukowiec (const string &name, int publikacje, int cytowania):
	_name (name), _publikacje (publikacje), _cytowania (cytowania) {}

double Naukowiec::indeks() {
	return double(_cytowania)/_publikacje;
}

void Naukowiec::publikuj (int n) {
	_publikacje += n;
}

Naukowiec &Naukowiec::operator ++ () {
	_cytowania++;
	return *this;
}

bool operator < (Naukowiec &first, Naukowiec &second) {
	return first.indeks() < second.indeks();
}

ostream &operator << (ostream &stream, const Naukowiec &naukowiec) {
	return stream << naukowiec._name <<' '<< naukowiec._publikacje <<' '<< naukowiec._cytowania;
}

istream &operator >> (istream &stream, Naukowiec &naukowiec) {
	return stream >> naukowiec._name >> naukowiec._publikacje >> naukowiec._cytowania;
}
