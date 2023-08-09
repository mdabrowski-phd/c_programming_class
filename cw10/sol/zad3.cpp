#include <iostream>

using namespace std;

class Resistor {
		double r;
	public:
		void set (double r);
		friend double resistance (const Resistor &resistor);
		friend Resistor serial (const Resistor &first,const Resistor &second);
		friend Resistor parallel (const Resistor &first,const Resistor &second);
};

void Resistor::set (double r) {
	Resistor::r=r;
}

double resistance (const Resistor &resistor) {
	return resistor.r;
}

Resistor serial (const Resistor &first,const Resistor &second) {
	Resistor resistor;
	resistor.r=first.r+second.r;
	return resistor;
}

Resistor parallel (const Resistor &first,const Resistor &second) {
	Resistor resistor;
	resistor.r=1/(1/first.r+1/second.r);
	return resistor;
}

int main () {
	double r1,r2;
	cin>>r1>>r2;
	Resistor R1,R2;
	R1.set (r1);
	R2.set (r2);
	cout<<resistance (serial (R1,R2))<<" "<<resistance (parallel (R1,R2))<<endl;
	return 0;
}
