#include <iostream>
using namespace std;

int main() {
	int p;
	cout << "Podaj pole p prostokata: ";
	cin >> p;
	int a_min=1, l_min=2*(p+1);
	for(int a=2; a*a<=p; a++) {
		if(p%a==0) {
			if(2*(a+p/a)<l_min) {
				a_min=a;
			}
		}
	}
	cout << "Minimalny prostokat ma wymiary "
		 << a_min << " na " << p/a_min << " i obwod " << 2*(a_min+p/a_min) << "."; 
}
