#include <iostream>

using namespace std;

int main () {
	int spectrum [26];
	for (int index=0;index<26;index++)
		spectrum [index]=0;
	char letter;
	while (cin>>letter)
		if (letter>='a' && letter<='z')
			spectrum [letter-'a']++;
		else if (letter>='A' && letter<='Z')
			spectrum [letter-'A']++;
	for (int index=0;index<26;index++)
		cout<<(char) (index+'a')<<' '<<spectrum [index]<<endl;
	return 0;
}
