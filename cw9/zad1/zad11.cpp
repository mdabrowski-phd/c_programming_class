#include <iostream>
using std::cout;

typedef char * arrayString;

// this function is not tested or used in this listing
char characterAt(arrayString s, int position) {
	return s[position];
}

void append(arrayString& s, char c) {
	int oldLength = 0;
	while (s[oldLength] != 0) {
		oldLength++;
	}
	arrayString newS = new char[oldLength + 2];
	for (int i = 0; i < oldLength; i++) {
		newS[i] = s[i];
	}
	newS[oldLength] = c;
	newS[oldLength + 1] = 0;
	delete[] s;
	s = newS;
}

void appendTester() {
	arrayString a = new char[5];
	a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] =  0;
	append(a, '!');

	arrayString b = new char[1];
	b[0] = 0;
	append(b, '!');

	cout << '\n'; 
}

int main() {
	appendTester();

	return 0;
}