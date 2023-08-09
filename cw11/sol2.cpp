#include <iostream>
#include <cmath>

using namespace std;

class Function {
	public:
		virtual double operator () (double x,int n=0) const=0;
};

class Exponential: public Function {
		const double alpha;
	public:
		Exponential (double alpha);
		virtual double operator () (double x,int n=0) const;
};
		
Exponential::Exponential (double alpha): alpha (alpha) {}

double Exponential::operator () (double x,int n) const {
	return pow (alpha,n)*exp (alpha*x);
}

class Sine: public Function {
		const double omega;
	public:
		Sine (double omega);
		virtual double operator () (double x,int n=0) const;
};

Sine::Sine (double omega): omega (omega) {}

double Sine::operator () (double x,int n) const {
	return pow (omega,n)*(n%2 ? (2-n%4)*cos (omega*x) : (1-n%4)*sin (omega*x));
}

int main () {
	Exponential exponential (2.);
	Sine sine (3.);
	Function &expo=exponential;
	Function &sinus=sine;
	cout<<expo (1.)<<endl;
	cout<<sinus (2.,1)<<endl;
	return 0;
}
