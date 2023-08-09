#include <iostream>
#include <string>

using namespace std;

int main () {
	int length=0,number=0;
	for (string word;cin>>word;length+=word.size (),++number);
		cout<<number<<" "<<(double) length/number<<endl;
	return 0;
}
