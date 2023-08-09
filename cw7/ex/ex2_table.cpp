#include <iostream>

using namespace std;

int main () {
	int t [5]={8,3,6,5,7};
	cout<<&t [0]<<' '<<t<<endl;
	for (int i=0;i<5;i++)
		cout<<i<<' '<<&t [i]<<' '<<t+i<<' '<<t [i]<<' '<<*(t+i)<<endl;
	for (int *p=t;p<t+5;p++)
		cout<<p-t<<' '<<p<<' '<<*p<<endl;
	return 0;
}
