#include <iostream>

using namespace std;

int &max (int &x,int &y) {
	return x>y ? x : y;
}

int main () {
	int a=3,b=7;
	max (a,b)=0;
	cout<<a<<" "<<b<<endl;
	return 0;
}
