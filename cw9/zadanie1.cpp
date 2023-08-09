#include <iostream>
using std::cout;

typedef char * arrayString;

char characterAt(arrayString s, int position) {
	return s[position];
}

////definicja funkcji append() bez uzycia funkcji pomocniczej length()
//void append(arrayString& s, char c) {
//	int oldLength = 0;
//	while (s[oldLength] != 0) {
//		oldLength++;
//	}
//	arrayString newS = new char[oldLength + 2];
//	for (int i = 0; i < oldLength; i++) {
//		newS[i] = s[i];
//	}
//	newS[oldLength] = c;
//	newS[oldLength + 1] = 0;
//	delete[] s;
//	s = newS;
//}

int length(arrayString s) {
	int count = 0;
	while (s[count] != 0) {
		count++;
	}
	return count;
}

void append(arrayString& s, char c) {
	int oldLength = length(s);
	arrayString newS = new char[oldLength + 2];
	for (int i = 0; i < oldLength; i++) {
		newS[i] = s[i];
	}
	newS[oldLength] = c;
	newS[oldLength + 1] = 0;
	delete[] s;
	s = newS;
}

void concatenate(arrayString& s1, arrayString s2) {
	int s1_OldLength = length(s1);
	int s2_Length = length(s2);
	int s1_NewLength = s1_OldLength + s2_Length;
	arrayString newS = new char[s1_NewLength + 1];
	for(int i = 0; i < s1_OldLength; i++) {
		newS[i] = s1[i];
	}
	for(int i = 0; i < s2_Length; i++) {
		newS[s1_OldLength + i] = s2[i];
	}
	newS[s1_NewLength] = 0;
	delete[] s1;
	s1=newS;
}

void appendTester() {
	arrayString a = new char[5];
	a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] =  0;
	append(a, '!');

	arrayString b = new char[1];
	b[0] = 0;
	append(b, '!');

	cout << a << '\n' << b << '\n';
}

void concatenateTester() {
	arrayString a = new char[5];
	a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] =  0;
	arrayString b = new char[4];
	b[0] = 'o'; b[1] = 'w'; b[2] = 'y'; b[3] = 0;
	concatenate(a, b);
	
	cout << a << '\n' << b << '\n';
	
	arrayString c = new char[1];
	c[0] = 0;
	concatenate(c, a);
	
	cout << a << '\n' << c << '\n';
	cout << (void *) a << '\n' << (void *) c << '\n';
	
}

int main() {
	appendTester();
	concatenateTester();

	return 0;
}
