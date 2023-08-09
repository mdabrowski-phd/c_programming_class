/*klasa Naukowcy © Michal Dabrowski*/

#include <iostream>
#include <vector>
#include "Naukowiec.h"
#include "Naukowcy.h"
using namespace std;

Naukowcy::Naukowcy() {}

Naukowcy::Naukowcy (const string &name):
	_name (name), _licz (0) {}

Naukowcy &Naukowcy::operator += (const Naukowiec &naukowiec) {
	_vec.push_back(naukowiec);
	_licz++;
	return *this;
}

double Naukowcy::sredIndeks() {
	double sredIndeks=0;
    for(int i=0; i<_licz; i++)
        sredIndeks+=_vec[i].indeks();
	return sredIndeks/_licz;
}

Naukowiec &Naukowcy::operator -- () {
	int idx=0;
    for(int i=1; i<_licz; i++) {
        if(_vec[i]<_vec[idx])
            idx=i;
    }
	return _vec[idx];
}

Naukowiec &Naukowcy::operator ++ () {
    int idx=0;
    for(int i=1; i<_licz; i++) {
        if(!(_vec[i]<_vec[idx]))
            idx=i;
    }
	return _vec[idx];
}

bool operator < (Naukowcy &first, Naukowcy &second) {
	return first.sredIndeks() < second.sredIndeks() ||
		(first.sredIndeks() == second.sredIndeks() && first._licz > second._licz );
}

Naukowcy operator + (const Naukowcy &first, const Naukowcy &second) {
    Naukowcy gr("supergrupa");
    for(int i=0; i<first._licz; i++)
        gr._vec.push_back(first._vec[i]);
    for(int i=0; i<second._licz; i++)
        gr._vec.push_back(second._vec[i]);
    gr._licz = first._licz + second._licz;
	return gr;
}

ostream &operator << (ostream &stream, const Naukowcy &naukowcy) {
    stream << naukowcy._name << " " << naukowcy._licz << endl;
    for(int i=0; i<naukowcy._licz; i++)
        stream << naukowcy._vec[i] << endl;
}
