#include <iostream>

using namespace std;

int main () {
	int a=2,b=7;
	cout<<a<<" "<<b<<endl;
	int *p=&a;
	cout<<p<<" "<<*p<<endl;
	*p+=b;
	cout<<p<<" "<<*p<<endl;
	p=&b;
	cout<<p<<" "<<*p<<endl;
	cout<<a<<" "<<b<<endl;
	return 0;
}
