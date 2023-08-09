#include <iostream>
#include <cmath>

using namespace std;

class Sequence {
public:
virtual double operator [] (int n) const=0; };

class Arithmetic:public Sequence {
		const double first,delta;
	public:
		Arithmetic (double first,double delta);
		virtual double operator [] (int n) const;
};

Arithmetic::Arithmetic (double first,double delta): first (first),delta (delta) {}

double Arithmetic::operator [] (int n) const {
	return first+n*delta;
}

class Fibonacci:public Sequence {
	public:
		virtual double operator [] (int n) const; 
};

double Fibonacci::operator [] (int n) const {
	if (n<2)
		return n;
	double a=0,b=1,c;
	for (int k=2;k<n;k++) {
		c=b+a;
		a=b;
		b=c;
	}
	return b+a;
}

int main () {
	Sequence *arithmetic=new Arithmetic (2.,3.);
	Sequence *fibonacci=new Fibonacci;
	for (int n=0;n<10;n++)
		cout<<(*arithmetic) [n]<<" ";
	cout<<endl;
	for (int n=0;n<10;n++)
		cout<<(*fibonacci) [n]<<" ";
	cout<<endl;
	delete fibonacci;
	delete arithmetic;
	return 0;
}
