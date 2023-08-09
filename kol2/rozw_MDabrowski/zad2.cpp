#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

int main (int argc, char *argv []) {
	string line, name;
	ifstream input (argv [1]);
	ofstream output ("wyniki.txt");
	getline(input,line);
	istringstream stream (line);
	stream >> name;
	output << name;
	stream >> name;
	output <<' '<< name;
	double wyn, total=0;
	vector <double> vec;
	while (stream >> wyn) {
		total+=wyn;
		vec.push_back(wyn);
	}
	output <<' '<< total <<endl;
	int student=1;
	for (student; getline(input,line); ++student) {
		stream.clear();
		stream.str(line);
		stream >> name;
		output << name;
		stream >> name;
		output <<' '<< name;
		total=0;
		for (int zad=0; zad<vec.size(); ++zad) {
			stream >> wyn;
			total+=wyn;
			vec[zad]+=wyn;
		}
		output <<' '<< total << endl;
	}
	for (int zad=0; zad<vec.size(); ++zad)
		output << 'z' << zad+1 <<' '<< vec[zad]/student <<"   ";
	output.close ();
	input.close ();
}
