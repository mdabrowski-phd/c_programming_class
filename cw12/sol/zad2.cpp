#include <cstdlib>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class Histogram {
		const double lower,upper;
		vector <int> counts;
	public:
		Histogram (double lower,double upper,int number);
		void reset ();
		void insert (double value);
		int count () const;
		int count (int bin) const;
		ostream &print (ostream &stream) const;
};

Histogram::Histogram (double lower,double upper,int number): lower (lower),upper (upper),counts (number) {}

void Histogram::reset () {
	counts=vector <int> (counts.size ());
}

void Histogram::insert (double value) {
	if (lower<=value && value<upper)
	++counts [counts.size ()*(value-lower)/(upper-lower)];
}

int Histogram::count () const {
	int sum=0;
	for (int i=0;i!=counts.size ();++i)
		sum+=counts [i];
	return sum;
}

int Histogram::count (int bin) const {
	return counts [bin];
}

ostream &Histogram::print (ostream &stream) const {
	for (int i=0;i!=counts.size ();++i)
		stream<<i<<" "<<counts [i]<<endl;
	return stream;
}

int main () {
	Histogram histogram (0.,2.,100);
	for (int i=0;i!=100000;++i)
		histogram.insert ((double) random ()/RAND_MAX+(double) random ()/RAND_MAX);
	histogram.print (cout);
	return 0;
}
