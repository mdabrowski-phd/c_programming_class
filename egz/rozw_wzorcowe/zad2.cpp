#include <iostream>
#include <cmath>
using namespace std;

class Dziedzina {
  public:
   double xmin, xmax;
   Dziedzina (double _xmin, double _xmax) : xmin(_xmin) , xmax(_xmax) { }
};

class M1 : public Dziedzina {     // y = Ax + B
  public:
   double A, B, m0;
   M1 (double _xmin, double _xmax, double _A, double _B) 
      : Dziedzina (_xmin, _xmax), A(_A), B(_B) { 
     znajdzm0 ();
   } 
   void znajdzm0 ();
};

void M1::znajdzm0 () {
  if (B != 0.) m0 = -B/A;
  else m0 = -9e99 ;
  if (m0<xmin || m0>xmax) m0 = -9e99 ;
}

class M2 : public Dziedzina {   // y = Ax^2 + Bx + C
  public:
   double A, B, C, m1, m2;
   M2 (double _xmin, double _xmax, double _A, double _B, double _C)
      : Dziedzina (_xmin, _xmax), A(_A), B(_B), C(_C) {
     znajdzm0();
   }
   void znajdzm0 ();
};

void M2::znajdzm0() {
  double Delta = B*B - 4.*A*C;
  if (Delta>=0) {
    m1 = (-B - sqrt(Delta)) / (2. *A) ;
    m2 = (-B + sqrt(Delta)) / (2. *A) ;
  } else {
    m1 = -9e99;
    m2 = -9e99;
  }
  if (m1 < xmin) m1 = -9e99;
  if (m1 > xmax) m1 = -9e99;
  if (m2 < xmin) m2 = -9e99;
  if (m2 > xmax) m2 = -9e99;
}

int main () {
  M1 mfun1 (-10., +10., 1., 2.);
  cout << mfun1.m0 << endl;
  
  M2 mfun2 (-10.,  0., 1., 0., -9.);
  cout << mfun2.m1 <<'\t'<< mfun2.m2 << endl;
  
  return 0;
}
