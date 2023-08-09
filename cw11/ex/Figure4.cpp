// implementacja operatora pisania do strumienia

#include <iostream>
#include <cmath>

using namespace std;

class Figure {
const string color;
virtual ostream &print (ostream &stream) const=0;
public:
Figure (const string &color);
const string &getColor () const;
virtual double getArea () const=0;
friend ostream &operator << (ostream &stream,const Figure &figure);
};

Figure::Figure (const string &color): color (color) {}

const string &Figure::getColor () const {
return color;
}

ostream &operator << (ostream &stream,const Figure &figure) {
return figure.print (stream);
}

class Circle: public Figure {
const double r;
ostream &print (ostream &stream) const;
public:
Circle (const string &color,double r);
double getArea () const;
double getRadius () const;
};

ostream &Circle::print (ostream &stream) const {
return stream<<"circle "<<getColor ()<<" "<<r;
}

Circle::Circle (const string &color,double r): Figure (color),r (r) {}

double Circle::getArea () const {
return M_PI*r*r;
}

double Circle::getRadius () const {
return r;
}

class Rectangle: public Figure {
const double a,b;
ostream &print (ostream &stream) const;
public:
Rectangle (const string &color,double a,double b);
double getArea () const;
double getFirstEdge () const;
double getSecondEdge () const;
};

ostream &Rectangle::print (ostream &stream) const {
return stream<<"rectangle "<<getColor ()<<" "<<a<<" "<<b;
}

Rectangle::Rectangle (const string &color,double a,double b):
Figure (color),a (a),b (b) {}

double Rectangle::getArea () const {
return a*b;
}

double Rectangle::getFirstEdge () const {
return a;
}

double Rectangle::getSecondEdge () const {
return b;
}

int main () {
Circle circle ("red",1);
cout<<circle<<" "<<circle.getArea ()<<endl;
Rectangle rectangle ("green",3,4);
cout<<rectangle<<" "<<rectangle.getArea ()<<endl;
Figure &reference=circle;
cout<<reference<<" "<<reference.getArea ()<<endl;
Figure *pointer=&circle;
cout<<*pointer<<" "<<pointer->getArea ()<<endl;
return 0;
}
