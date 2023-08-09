#include <iostream>
#include <cmath>

using namespace std;

class Ray;
class System;

class Ray {
double u [2];
public:
Ray ();
Ray (double y,double alpha);
double getDistance () const;
double getAngle () const;
friend Ray operator * (const System &s,const Ray &r);
};

Ray::Ray () {
u [0]=0;
u [1]=0;
}

Ray::Ray (double y,double alpha) {
u [0]=y;
u [1]=alpha;
}

double Ray::getDistance () const {
return u [0];
}

double Ray::getAngle () const {
return u [1];
}

class System {
protected:
double m [2][2];
public:
System ();
friend System operator * (const System &s1,const System &s2);
friend Ray operator * (const System &s,const Ray &r);
};

System::System () {
for (int i=0;i<2;i++)
for (int j=0;j<2;j++)
m [i][j]=(i==j ? 1 :0);
}

System operator * (const System &s1,const System &s2) {
System s;
for (int i=0;i<2;i++)
for (int j=0;j<2;j++) {
s.m [i][j]=0;
for (int k=0;k<2;k++)
s.m [i][j]+=s1.m [i][k]*s2.m [k][j]; }
return s;
}

Ray operator * (const System &s,const Ray &r) {
Ray ray;
for (int i=0;i<2;i++) {
ray.u [i]=0;
for (int j=0;j<2;j++)
ray.u [i]+=s.m [i][j]*r.u [j]; }
return ray;
}

class Space: public System {
public:
Space (double d);
};

Space::Space (double d) {
m [0][0]=1;
m [0][1]=d;
m [1][0]=0;
m [1][1]=1;
}

class Lens: public System {
public:
Lens (double f);
};

Lens::Lens (double f) {
m [0][0]=1;
m [0][1]=0;
m [1][0]=-1/f;
m [1][1]=1;
}

int main () {
Ray ray=Lens (50)*Space (150)*Lens (100)*Ray (0.1,0);
cout<<ray.getDistance ()<<" "<<ray.getAngle ()<<endl;
return 0;
}
