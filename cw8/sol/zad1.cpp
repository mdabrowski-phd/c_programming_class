#include <iostream>
#include <string>

using namespace std;

int characters (const string &text,char c) {
	int n=0;
	for (int i=0;i<text.size ();i++)
		if (text [i]==c)
			n++;
	return n;
}

int main () {
	string word="Trentatre Trentini entrarono in Trento tutti e trentatre trotterellando.";
	cout<<characters (word,’t’)<<endl;
	cout<<characters ("Opasly susel spal sobie smacznie.",’s’)<<endl;
	return 0;
}
