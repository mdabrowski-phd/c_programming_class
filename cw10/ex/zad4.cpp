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

//tu definicje metod klasy Stack

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
