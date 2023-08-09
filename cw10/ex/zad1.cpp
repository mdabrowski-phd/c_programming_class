#include <cmath>
#include <iostream>

using namespace std;

class Vector {
	public:
		Vector ();
		Vector (double x,double y);
		double length () const;
		Vector operator - () const;
		Vector &operator += (const Vector &vector);
		Vector &operator -= (const Vector &vector);
		Vector &operator *= (double number);
		friend Vector operator * (double number,const Vector &vector);
		friend Vector operator * (const Vector &vector,double number);
		friend double operator * (const Vector &first,const Vector &second);
		friend Vector operator + (const Vector &first,const Vector &second);
		friend Vector operator - (const Vector &first,const Vector &second);
		friend ostream &operator << (ostream &stream,const Vector &vector);
		friend istream &operator >> (istream &stream,Vector &vector);
	private:
		double x,y;
};

//tutaj definicje metod klasy Vector

int main() {
	//miejsce na testowanie
	return 0;
}
