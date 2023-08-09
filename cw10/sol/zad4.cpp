#include <iostream>
#include <string>

using namespace std;

class Stack {
		struct Item {
			string value;
			Item *lower;
		};
		Item *top;
	public:
		Stack ();
		~Stack ();
		void push (const string &value);
		bool pop (string &value);
};

Stack::Stack (): top (0) {}

Stack::~Stack () {
	while (top) {
		Item *auxiliary=top->lower;
		delete top;
		top=auxiliary;
	}
}

void Stack::push (const string &value) {
	Item *auxiliary=top;
	top=new Item ();
	top->value=value;
	top->lower=auxiliary;
}

bool Stack::pop (string &value) {
	if (!top)
		return false;
	value=top->value;
	Item *auxiliary=top->lower;
	delete top;
	top=auxiliary;
	return true;
}

int main () {
	string word;
	Stack stack;
	while (cin>>word)
		stack.push (word);
	while (stack.pop (word))
		cout<<word<<" ";
	cout<<endl;
	return 0;
}
