#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Name {
	private:
		string given, family;
	public:
		Name ();
		Name (const string &given, const string &family);
		string initials () const;
		friend bool operator< (const Name &first, const Name &second);
		friend ostream &operator<< (ostream &stream, const Name &Name);
		friend istream &operator>> (istream &stream, Name &Name);
};

Name::Name (): given (),family () {}

Name::Name (const string &given,const string &family): given (given),family (family) {}

string Name::initials () const {
	return given.substr (0,1)+family.substr (0,1); }

bool operator< (const Name &first,const Name &second) {
	return first.family<second.family || (first.family==second.family && first.given<second.given);
}

ostream &operator<< (ostream &stream,const Name &Name) {
	return stream<<Name.given<<’ ’<<Name.family;
}

istream &operator>> (istream &stream,Name &Name) {
	return stream>>Name.given>>Name.family;
}

bool compare (const Name &first, const Name &second) {
	return first.initials () < second.initials ();
}

int main () {
	vector <Name> names;
	Name name;
	while (cin >> name)
		names.push_back (name);
	sort( names.begin(), names.end() );
	for (vector <Name>::iterator iterator=names.begin (); iterator!=names.end (); ++iterator)
		cout<< *iterator << endl;
	cout << endl;
	sort (names.begin (), names.end (), compare);
	for (vector <Name>::iterator iterator=names.begin (); iterator!=names.end (); ++iterator)
		cout << *iterator << endl;
	return 0;
}
