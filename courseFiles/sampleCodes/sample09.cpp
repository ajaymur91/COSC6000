//
// CPP sample09.cpp
//
#include <iostream>

using namespace std;

void show_me(int a){
  cout << "Integer value is " << a << endl;
}

void show_me(double a){
  cout << "Double value is " << a << endl;
}

int main (int argc, char *argv[]) {
  int a = 1;
  double x = 2.5;

  show_me(a);
  show_me(x);

  return 0;
}
