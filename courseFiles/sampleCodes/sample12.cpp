//
// CPP sample12.cpp
//
#include <iostream>
#include <cmath>

using namespace std;

void rotate(double a, double &x1,double &y1){
  double xp = x1 * cos(a) - y1 * sin(a);
  double yp = x1 * sin(a) + y1 * cos(a);
  x1 = xp;
  y1 = yp;
}

int main (int argc, char *argv[]) {
  double x1 = 1.0;
  double y1 = 0.0;
  
  cout << "(" << x1 << "," << y1 << ")" << endl;

  rotate(M_PI / 4.0, x1 , y1);
  cout << "(" << x1 << "," << y1 << ")" << endl;

  rotate(M_PI / 4.0, x1 , y1);
  cout << "(" << x1 << "," << y1 << ")" << endl;

  rotate(M_PI / 4.0, x1 , y1);
  cout << "(" << x1 << "," << y1 << ")" << endl;

  rotate(M_PI / 4.0, x1 , y1);
  cout << "(" << x1 << "," << y1 << ")" << endl;

  rotate(M_PI / 4.0, x1 , y1);
  cout << "(" << x1 << "," << y1 << ")" << endl;

  rotate(M_PI / 4.0, x1 , y1);
  cout << "(" << x1 << "," << y1 << ")" << endl;

  rotate(M_PI / 4.0, x1 , y1);
  cout << "(" << x1 << "," << y1 << ")" << endl;

  rotate(M_PI / 4.0, x1 , y1);
  cout << "(" << x1 << "," << y1 << ")" << endl;
  
  return 0;
}
