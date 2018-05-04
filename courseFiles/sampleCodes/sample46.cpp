//
//  sample46.cpp
//
//  Created by Hideki Fujioka on 4/5/13.
//  Copyright (c) 2013 Tulane University. All rights reserved.
//

#include <iostream>

using namespace std;

template <class T>
void swap_values(T &v1, T &v2){
  T tmp = v1;
  v1 = v2;
  v2 = tmp;
}

int main(int argc, const char * argv[])
{
  int m = 5, n = 8;
  cout << "(m,n)=(" << m << "," << n << ")\n"; 
  swap_values(m,n);
  cout << "(m,n)=(" << m << "," << n << ")\n"; 

  double x = 1.2, y = 4.7;
  cout << "(x,y)=(" << x << "," << y << ")\n"; 
  swap_values(x,y);
  cout << "(x,y)=(" << x << "," << y << ")\n"; 

  return 0;
}

