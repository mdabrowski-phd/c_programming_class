#include <iostream>

using namespace std;

int catalan(int n) {
	if(n==0) {
		return 1;
	}
	else {
		return catalan(n-1)*(4*(n-1)+2)/((n-1)+2);
	}
}

int main() {
	int n;
	cout << "Podaj liczbe naturalna n: ";
	cin >> n;
	cout << "Wyraz ciagu o podanym indeksie to " << catalan(n) << "."; 
}
