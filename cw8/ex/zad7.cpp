#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

int main (int argc,char *argv []) {
	ifstream input (argv [1]);
	ofstream output ("output.txt");
	string line,previous=argv [2],next=argv [3];
	while (getline (input,line)) {
		for (int index=0;(index=line.find (previous,index))!=string::npos;) {
			line.replace (index,previous.size (),next);
			index+=next.size ();
		}
		output<<line<<endl;
	}
	output.close ();
	input.close ();
	rename ("output.txt",argv [1]);
	return 0;
}
