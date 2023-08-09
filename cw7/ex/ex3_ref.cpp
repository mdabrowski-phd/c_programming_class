#include <iostream>

using namespace std;

int main () {
	int a=5,&r=a;
	cout<<a<<' '<<r<<endl;
	a=7;
	cout<<a<<' '<<r<<endl;
	r=9;
	cout<<a<<' '<<r<<endl;
	return 0;
}
