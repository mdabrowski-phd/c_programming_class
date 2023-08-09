/*plik naglowkowy, klasa Naukowcy © Michal Dabrowski*/

#include <iostream>
#include <vector>
#include "Naukowiec.h"
using namespace std;

class Naukowcy {
        vector <Naukowiec> _vec;
		string _name;
		int _licz;
	public:
		Naukowcy();
		Naukowcy (const string &name);
		Naukowcy &operator += (const Naukowiec &naukowiec);
		double sredIndeks();
		Naukowiec &operator -- ();
		Naukowiec &operator ++ ();
		friend bool operator < (Naukowcy &first, Naukowcy &second);
		friend Naukowcy operator + (const Naukowcy &first, const Naukowcy &second);
		friend ostream &operator << (ostream &stream, const Naukowcy &naukowcy);
};
