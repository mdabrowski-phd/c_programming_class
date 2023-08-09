#include <iostream>
#include <string>

using namespace std;

int main (int argc,char *argv []) {
	string line;
	while (getline (cin,line))
		if (line.find (argv [1])!=string::npos)
			cout<<line<<endl;
	return 0;
}
