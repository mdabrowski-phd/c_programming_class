// prosta klasa reprezentujaca figure o zadanym kolorze

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

int main () {
Figure figure ("red");
cout<<figure.getColor ()<<endl;
return 0;
}
