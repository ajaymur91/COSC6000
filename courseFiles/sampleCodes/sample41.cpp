//
//  sample41.cpp
//
//  Created by Hideki Fujioka on 4/4/13.
//  Copyright (c) 2013 Tulane University. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
  string s1,s2;
  cout << "input:";
  cin >> s1;
  //cin.ignore(100,'\n');
  getline(cin,s2);
  cout << "s1=" << s1 << endl;
  cout << "s2=" << s2 << endl;

  return 0;
}

