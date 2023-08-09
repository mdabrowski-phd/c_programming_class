/* dziedziczenie danych i funkcji skladowych, wywolanie konstruktorow klas mecierzystych oraz uzycie referencji
i wskaznikow do klas macierzystych */


#include <iostream>

using namespace std;

class Figure {
const string color;
public:
Figure (const string &color);
const string &getColor () const;
};

Figure::Figure (const string &color): color (color) {}

const string &Figure::getColor () const {
return color;
}

class Circle: public Figure {
const double r;
public:
Circle (const string &color,double r);
double getRadius () const;
};

Circle::Circle (const string &color,double r): Figure (color),r (r) {}

double Circle::getRadius () const {
return r;
}

class Rectangle: public Figure {
const double a,b;
public:
Rectangle (const string &color,double a,double b);
double getFirstEdge () const;
double getSecondEdge () const;
};

Rectangle::Rectangle (const string &color,double a,double b):
Figure (color),a (a),b (b) {}

double Rectangle::getFirstEdge () const {
return a;
}

double Rectangle::getSecondEdge () const {
return b;
}


int main () {
Circle circle ("red",1);
cout<<"circle "<<circle.getColor ()<<" "<<circle.getRadius ()<<endl;
Rectangle rectangle ("green",3,4);
cout<<"rectangle "<<rectangle.getColor ()<<" "
<<rectangle.getFirstEdge ()<<" "<<rectangle.getSecondEdge ()<<endl;
Figure &reference=circle;
cout<<"circle "<<reference.getColor ()<<endl;
Figure *pointer=&circle;
cout<<"circle "<<pointer->getColor ()<<endl;
return 0;
}
