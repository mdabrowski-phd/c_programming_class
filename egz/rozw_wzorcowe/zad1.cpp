#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int tribonacci(int n) {
	if(n==0 || n==1) {
		return 1;
	}
	else if(n==2) {
		return 2;
	}
	else {
		return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
	}
}

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);
	ofstream output("wyniki.txt");
	for(int i=0; i<n; i++)
		output << tribonacci(i) << "  ";
	output.close(); 
}
