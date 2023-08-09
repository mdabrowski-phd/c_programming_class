#include <iostream>
#include <string>

using namespace std;

struct Item {
	string value;
	Item *lower;
};

Item *top=0;

void push (string value) {
	Item *auxiliary=top;
	top=new Item ();
	top->value=value;
	top->lower=auxiliary;
}

string pop () {
	string value=top->value;
	Item *auxiliary=top->lower;
	delete top;
	top=auxiliary;
	return value;
}

int main () {
	string word;
	while (cin>>word)
	push (word);
	while (top)
	cout<<pop ()<<" ";
	cout<<endl;
	return 0;
}
