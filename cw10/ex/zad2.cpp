#include <iostream>
#include <string>

using namespace std;

class Name {
	public:
		Name ();
		Name (const string &given,const string &family);
		string initials () const;
		friend bool operator< (const Name &first,const Name &second);
		friend ostream &operator<< (ostream &stream,const Name &Name);
		friend istream &operator>> (istream &stream,Name &Name);
	private:
		string given,family;
};

//tu definicje metod klasy Name


int main () {
	Name a,b;
	cin>>a>>b;
	if (a<b)
		cout<<a<<" "<<a.initials ()<<endl;
	else
	cout<<b<<" "<<b.initials ()<<endl;
	return 0;
}
