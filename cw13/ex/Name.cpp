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

Name::Name (): given (),family () {}

Name::Name (const string &given,const string &family): given (given),family (family) {}

string Name::initials () const {
	return given.substr (0,1)+family.substr (0,1);
}

bool operator< (const Name &first,const Name &second) {
	return first.family<second.family || (first.family==second.family && first.given<second.given);
}

ostream &operator<< (ostream &stream,const Name &Name) {
	return stream<<Name.given<<’ ’<<Name.family;
}

istream &operator>> (istream &stream,Name &Name) {
	return stream>>Name.given>>Name.family;
}

int main () {
	Name a,b;
	cin>>a>>b;
	if (a<b)
		cout<<a<<" "<<a.initials ()<<endl;
	else
	cout<<b<<" "<<b.initials ()<<endl;
	return 0;
}
