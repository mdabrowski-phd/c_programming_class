#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main () {
	double x=1;
	for (int i=0;i<15;i++) {
		cout<<i<<" "<<x<<endl;
		x*=M_PI;
	}
	cout<<endl;
	x=1;
	cout<<setprecision (3);
	for (int i=0;i<15;i++) {
		cout<<i<<" "<<x<<endl;
		x*=M_PI;
	}
	cout<<endl;
	x=1;
	cout<<fixed<<setprecision (3);
	for (int i=0;i<15;i++) {
		cout<<setw (2)<<i<<" "<<setw (11)<<x<<endl;
		x*=M_PI;
	}
	cout<<endl;
	x=1;
	cout<<scientific<<setprecision(2);
	for (int i=0;i<15;i++) {
		cout<<setw(2)<<i<<" "<<setw(9)<<x<<endl;
		x*=M_PI;
	}
	return 0;
}
