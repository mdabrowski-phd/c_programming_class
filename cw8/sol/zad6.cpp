#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main (int argc,char *argv []) {
	int number;
	istringstream (argv [1])>>number;
	string line;
	while (getline (cin,line)) {
		istringstream stream (line);
		string word;
		for (int counter=0;counter!=number;++counter)
			if (!(stream>>word)) {
				word.clear ();
				break;
			}
		cout<<word<<endl;
	}
	return 0;
}
