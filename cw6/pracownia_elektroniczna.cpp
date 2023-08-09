#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, d, b;
	cin >> n;
	int t[n];
	for(int i=0; i<n; i++) {
		cin >> d >> b;
		t[i]=d-b;	
	}
	sort(t,t+n);
	int suma=0, licz=0;
	for(int i=n-1; i>=0; i--) {
		suma+=t[i];
		if(suma<0)
			break;
		licz++;
	}
	cout << licz << endl;
	return 0;
}
