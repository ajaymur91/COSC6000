//
// CPP sample08.cpp
//
#include <iostream>
#include <cmath>

using namespace std;

double dist(double x1,double x2){
  return abs(x1 - x2);
}

double dist(double x1,double y1,double x2,double y2){
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main (int argc, char *argv[]) {
  double x1 = 1.2;
  double x2 = 0.8;
  double y1 = 3.2;
  double y2 = 3.0;
  
  cout << "1d distance=" << dist(x1,x2) << endl;
  cout << "2d distance=" << dist(x1,y1,x2,y2) << endl; 
  
  return 0;
}
