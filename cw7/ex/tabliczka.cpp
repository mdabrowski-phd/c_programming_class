#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main () {
	int n,w;
	cin>>n;
	w=log10 (n*n)+1;
	cout<<setw (w)<<""<<" ";
	for (int j=1;j<=n;j++)
		cout<<" "<<setw (w)<<j;
	cout<<endl;
	cout<<setw (w)<<""<<" ";
	cout<<setfill ('-');
	for (int j=1;j<=n;j++)
		cout<<"-"<<setw (w)<<"";
	cout<<setfill (' ');
	cout<<endl;
	for (int i=1;i<=n;i++) {
		cout<<setw (w)<<i<<"|";
		for (int j=1;j<=n;j++)
			cout<<" "<<setw (w)<<i*j;
		cout<<endl;
	}
	return 0;
}
