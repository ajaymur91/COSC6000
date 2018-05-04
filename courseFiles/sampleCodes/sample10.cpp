/*
  CPP sample10.cpp
 */

#include <iostream>

using namespace std;

int addone(int a){
  cout << "a=" << a << endl;
  a += 1; // add 1
  cout << "a+1=" << a << endl;
  return a;
}

int main (int argc, char *argv[]) {
  int a = 5;
  int b = addone(a);

  cout << "a=" << a << " b=" << b << endl;
  
  return 0;
}
