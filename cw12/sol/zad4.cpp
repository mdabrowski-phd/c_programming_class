#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main () {
	cout<<scientific<<setprecision (1);
	vector <double> sums;
	{
		string line;
		getline (cin,line);
		istringstream stream (line);
		double value,sum=0.;
		while (stream>>value) {
			cout<<setw (8)<<value<<" ";
			sums.push_back (value);
			sum+=value;
		}
		cout<<setw (8)<<sum<<endl;
	}
	{
		string line;
		while (getline (cin,line)) {
			istringstream stream (line);
			double value,sum=0.;
			for (int i=0;i!=sums.size ();++i) {
				stream>>value;
				cout<<setw (8)<<value<<" ";
				sums [i]+=value;
				sum+=value;
			}
			cout<<setw (8)<<sum<<endl;
		}
	}
	{
		double sum=0.;
		for (int i=0;i!=sums.size ();++i) {
			cout<<setw (8)<<sums [i]<<" ";
			sum+=sums [i];
		}
		cout<<setw (8)<<sum<<endl;
	}
	return 0;
}
