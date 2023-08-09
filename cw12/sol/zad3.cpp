#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// program nalezy uzupelnic zgodnie z trescia zadania (obsluga plikow)

int main (int argc,char *argv []) {
	int key;
	istringstream (argv [1])>>key;
	if ((string) argv [2]=="e") {
		char letter;
		while (cin.get (letter))
			cout<<(letter^key)<<’ ’;
	}
	else {
		int number;
		while (cin>>number)
			cout<<(char) (number^key);
	}
	return 0;
}
