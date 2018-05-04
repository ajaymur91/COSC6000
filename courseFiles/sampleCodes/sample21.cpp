//
// CPP sample21.cpp
//
#include <iostream>

using namespace std;

struct Vector2d{
  double x;
  double y;
};

int main (int argc, char *argv[]) {
  Vector2d a;
  a.x = 1.0;
  a.y = 2.0;

  Vector2d b = a;

  cout << "b=(" << b.x << "," << b.y << ")" << endl;
  
  return 0;
}
