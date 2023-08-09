#include <iostream>

using namespace std;

int main () {
	//deklaracja tablicy wystapien znakow, inicjalizajca, itp.
	char letter; // aktualnie przetwarzany znak
	while (cin>>letter)
		{
			//tu wpisz tresc programu
		}
	for (int index=0;index<26;index++) // wypisanie statystyki znakow
		cout<<(char) (index+'a')<<' '<<spectrum [index]<<endl;
	return 0;
}
