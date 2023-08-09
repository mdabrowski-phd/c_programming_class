#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main () {
	srand (time (0));
	int num;
	cin>>num;
	double vec [num];
	for (double *pnt=vec;pnt<vec+num;pnt++)
		*pnt=(double) rand ()/RAND_MAX;
	for (double *pnt=vec;pnt<vec+num;pnt++)
		cout<<pnt<<" "<<*pnt<<endl;
	cout<<endl;
	double *min=vec;
	for (double *pnt=vec+1;pnt<vec+num;pnt++)
		if (*pnt<*min)
			min=pnt;
	cout<<min<<" "<<*min<<endl;
	return 0;
}
