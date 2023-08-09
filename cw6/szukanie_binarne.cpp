#include <iostream>

using namespace std;

int binarysearch(int x[], int n, int t) {
	int l=0, u=n-1, m;
	while (l <= u) {
		m = (l + u) / 2;
		if (x[m] < t)
			l = m+1;
		else if (x[m] == t)
			return m;
		else /* x[m] > t */
			u = m-1;
	}
	return -1;
}

int main() {
	int n, x;
	cin >> n;
	int tab[n];
	for(int i=0; i<n; i++)
		cin >> tab[i];
	cin >> x;
	cout << binarysearch(tab, n, x) << endl;
	return 0;
}
