// klasy anstrakcyjne i funkcje wirtualne

#include <iostream>
#include <cmath>

using namespace std;

class Figure {
const string color;
public:
Figure (const string &color);
const string &getColor () const;
virtual double getArea () const=0;
};

Figure::Figure (const string &color): color (color) {}

const string &Figure::getColor () const {
return color;
}

class Circle: public Figure {
const double r;
public:
Circle (const string &color,double r);
double getArea () const;
double getRadius () const;
};

Circle::Circle (const string &color,double r): Figure (color),r (r) {}

double Circle::getArea () const {
return M_PI*r*r;
}

double Circle::getRadius () const {
return r;
}

class Rectangle: public Figure {
const double a,b;
public:
Rectangle (const string &color,double a,double b);
double getArea () const;
double getFirstEdge () const;
double getSecondEdge () const;
};

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
cout<<"circle "<<circle.getColor ()<<" "
<<circle.getRadius ()<<" "<<circle.getArea ()<<endl;
Rectangle rectangle ("green",3,4);
cout<<"rectangle "<<rectangle.getColor ()<<" "
<<rectangle.getFirstEdge ()<<" "<<rectangle.getSecondEdge ()<<" "
<<rectangle.getArea ()<<endl;
Figure &reference=circle;
cout<<"circle "<<reference.getColor ()<<" "<<reference.getArea ()<<endl;
Figure *pointer=&circle;
cout<<"circle "<<pointer->getColor ()<<" "<<pointer->getArea ()<<endl;
return 0;
}
