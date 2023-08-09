#include <iostream>
using namespace std;

void foo(int *ptr,int n) {
	if(!n) (*ptr) = 1;
	else {
		foo(ptr,n-1);
    	(*ptr) = (*ptr)*(4*(n-1)+2)/(2+(n-1));
	}
}


int main()
{
    int val,n;
    cin >> n;
    foo(&val, n);
    
    cout << val;
    return 0;

}
