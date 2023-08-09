#include <iostream>

using namespace std;

int function (int i,int *j) {
	i++;
	(*j)++;
	return i+*j;
}

int main () {
	int a=3,b=7;
	cout<<a<<" "<<b<<endl;
	cout<<function (a,&b)<<endl;
	cout<<a<<" "<<b<<endl;
	cout<<function (a,&b)<<endl;
	cout<<a<<" "<<b<<endl;
	return 0;
}
