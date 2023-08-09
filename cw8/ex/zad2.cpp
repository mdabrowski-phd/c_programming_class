#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void spacer (ostream &output,istream &input) {
	string word;
	if (input>>word)
		output<<word;
	while (input>>word)
		output<<" "<<word;
}

int main () {
	istringstream si;
	ostringstream so;
	spacer (so,si);
	ifstream fi ("input.txt");
	ofstream fo ("output.txt");
	spacer (fo,fi);
	fo.close ();
	fi.close ();
	spacer (cout,cin);
	return 0;
}
