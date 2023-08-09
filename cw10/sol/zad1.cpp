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

Vector::Vector (): x (),y () {}

Vector::Vector (double x,double y): x (x),y (y) {}

double Vector::length () const {
	return sqrt (x*x+y*y);
}

Vector Vector::operator - () const {
	return Vector (-x,-y);
}

Vector &Vector::operator += (const Vector &vector) {
	x+=vector.x;
	y+=vector.y;
	return *this;
}

Vector &Vector::operator -= (const Vector &vector) {
	x-=vector.x;
	y-=vector.y;
	return *this;
}

Vector &Vector::operator *= (double number) {
	x*=number;
	y*=number;
	return *this;
}

Vector operator * (double number,const Vector &vector) {
	return Vector (number*vector.x,number*vector.y);
}

Vector operator * (const Vector &vector,double number) {
	return Vector (vector.x*number,vector.y*number);
}

double operator * (const Vector &first,const Vector &second) {
	return first.x*second.x+first.y*second.y;
}

Vector operator + (const Vector &first,const Vector &second) {
	return Vector (first.x+second.x,first.y+second.y);
}

Vector operator - (const Vector &first,const Vector &second) {
	return Vector (first.x-second.x,first.y-second.y);
}

ostream &operator << (ostream &stream,const Vector &vector) {
	return stream<<vector.x<<' '<<vector.y;
}

istream &operator >> (istream &stream,Vector &vector) {
	return stream>>vector.x>>vector.y;
}

int main() {
	//miejsce na testowanie
	return 0;
}
