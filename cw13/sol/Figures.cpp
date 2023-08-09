#include <iostream>
#include <cmath>

using namespace std;

class Figure {
	const string color;
	virtual ostream &print (ostream &stream) const=0;
	public:
		Figure (const string &color);
		const string &getColor() const;
		virtual double getArea() const = 0;
		friend ostream &operator << (ostream &stream, const Figure &figure);
};

Figure::Figure (const string &color): color (color) {}

const string &Figure::getColor() const {
	return color;
}

ostream &operator << (ostream &stream, const Figure &figure) {
	return figure.print (stream);
}

class Circle: public Figure {
	const double r;
	ostream &print (ostream &stream) const;
	public:
		Circle (const string &color, double r);
		double getArea() const;
		double getRadius() const;
};

ostream &Circle::print (ostream &stream) const {
	return stream << "circle " << getColor() << " " << r;
}

Circle::Circle (const string &color, double r): Figure (color), r (r) {}

double Circle::getArea() const {
	return M_PI*r*r;
}

double Circle::getRadius() const {
	return r;
}

class Rectangle: public Figure {
	const double a, b;
	ostream &print (ostream &stream) const;
	public:
		Rectangle (const string &color, double a, double b);
		double getArea() const;
		double getFirstEdge() const;
		double getSecondEdge() const;
};

ostream &Rectangle::print (ostream &stream) const {
	return stream << "rectangle " <<getColor ()<< " " << a << " " < <b ;
}

Rectangle::Rectangle (const string &color, double a, double b): Figure (color), a (a), b (b) {}

double Rectangle::getArea() const {
	return a*b;
}

double Rectangle::getFirstEdge() const {
	return a;
}

double Rectangle::getSecondEdge() const {
	return b;
}

Figure *scan (istream &stream) {
	string name, color;
	stream >> name >> color;
	if (name=="circle") {
		double r;
		stream >> r;
		return new Circle (color, r);
	}
	if (name=="rectangle") {
		double a, b;
		stream >> a >> b;
		return new Rectangle (color, a, b);
	}
	return 0;
}

bool compare (Figure *first, Figure *second) {
	return first->getArea() < second->getArea();
}

int main () {
	vector <Figure*> figures;
	Figure *figure;
	while (figure=scan (cin))
		figures.push_back(figure);
	sort (figures.begin(), figures.end(), compare);
	for (vector <Figure*>::iterator i = figures.begin(); i != figures.end(); ++i)
		cout<< **i <<" "<< (*i)->getArea() <<endl;
	for (vector <Figure*>::iterator i = figures.begin(); i != figures.end(); ++i)
		delete *i;
	return 0;
}
