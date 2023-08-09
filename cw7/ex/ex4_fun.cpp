#include <iostream>

using namespace std;

int &function (int &r) {
	return ++r;
}

int main () {
	int a=7;
	cout<<a<<endl;
	cout<<function (a)<<endl;
	cout<<a<<endl;
	cout<<(function (a)=3)<<endl;
	cout<<a<<endl;
	return 0;
}
