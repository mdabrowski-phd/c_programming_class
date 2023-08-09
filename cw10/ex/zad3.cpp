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

//tu definicje metod klasy Resistor

int main () {
	double r1,r2;
	cin>>r1>>r2;
	Resistor R1,R2;
	R1.set (r1);
	R2.set (r2);
	cout<<resistance (serial (R1,R2))<<" "<<resistance (parallel (R1,R2))<<endl;
	return 0;
}
