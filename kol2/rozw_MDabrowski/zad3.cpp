#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Statystyka {
		vector <double> _vec;
		double _srednia, _sigma, _mediana;
	public:
		Statystyka();
		void dodaj (double x);
		double srednia();
		double sigma();
		double mediana();
		void zeruj();
};

Statystyka::Statystyka(): _srednia (0), _sigma (0), _mediana (0) {}

void Statystyka::dodaj (double x) {
	_vec.push_back(x);
}

double Statystyka::srednia() {
	_srednia=0;
	for(int i=0; i<_vec.size(); i++)
		_srednia+=_vec[i];
	return _srednia/=_vec.size();
}

double Statystyka::sigma() {
	_sigma=0;
	for(int i=0; i<_vec.size(); i++)
		_sigma+=( _vec[i]-_srednia )*( _vec[i]-_srednia );
	return _sigma=sqrt( _sigma/( _vec.size()-1 ) );
}

double Statystyka::mediana() {
	sort ( _vec.begin(), _vec.end() );
	if(_vec.size()%2==1)
		return _mediana=_vec[(_vec.size()-1)/2+1];
	else
		return _mediana=(_vec[_vec.size()-1]+_vec[_vec.size()])/2;
}

void Statystyka::zeruj() {
	_vec.clear();
}

int main (int argc, char *argv []) {
	int N=atoi(argv[1]), k=atoi(argv[2]);
	srand(time(NULL));
	Statystyka stat;
	for (int i = 0; i<N; i++)
		stat.dodaj( 2*k*(double)rand()/RAND_MAX-k );
	cout << stat.srednia() <<' '<< stat.sigma() <<' '<< stat.mediana();
	stat.zeruj();
}
