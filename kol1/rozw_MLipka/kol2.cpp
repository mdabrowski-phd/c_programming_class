#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int p,b,c,obw;
    int a;
    cin >> p;
    a = (int)ceil(sqrt(p));
    for(int i=1; i<=a; ++i)
    {
    	if(p % i == 0) b = i;
    }
    c= p/b;
    obw=2*(c+b);
    
    
    cout << "wymiary: " << b <<  " na " << c << " obw: " << obw;
    return 0;
}
