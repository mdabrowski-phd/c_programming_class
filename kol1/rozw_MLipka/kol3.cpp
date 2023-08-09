#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int acc=0;
    int tmp;
    for(int i=0; i<n; ++i)
    {
    	cin >> tmp;
    	acc+=tmp;
    }
       for(int i=0; i<n-1; ++i)
    {
    	cin >> tmp;
    	acc-=tmp;
    }
cout << acc;
    return 0;

}

