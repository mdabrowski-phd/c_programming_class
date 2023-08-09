#include <iostream>
using namespace std;

class Naukowiec {
		string _name;
		int _publikacje, _cytowania;
	public:
		Naukowiec();
		Naukowiec (const string &name, int publikacje, int cytowania);
		double indeks();
		void publikuj (int n);
		Naukowiec &operator ++ ();
		friend bool operator < (Naukowiec &first, Naukowiec &second);
		friend ostream &operator << (ostream &stream, const Naukowiec &naukowiec);
		friend istream &operator >> (istream &stream, Naukowiec &naukowiec);
};

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
	return first._cytowania < second._cytowania ||
		(first._cytowania == second._cytowania && first.indeks() < second.indeks() );
}
	
ostream &operator << (ostream &stream, const Naukowiec &naukowiec) {
	return stream << naukowiec._name <<' '<< naukowiec._publikacje <<' '<< naukowiec._cytowania;
}

istream &operator >> (istream &stream, Naukowiec &naukowiec) {
	return stream >> naukowiec._name >> naukowiec._publikacje >> naukowiec._cytowania;
}

int main () {
	Naukowiec Bogdan("Bogdan",50,300), Czeslaw;
	cin >> Czeslaw;
	cout << Czeslaw.indeks() << endl;
	Bogdan.publikuj(3);
	if(Bogdan < ++Czeslaw)
		cout << Czeslaw << endl;
	else
		cout << Bogdan << endl;
}
