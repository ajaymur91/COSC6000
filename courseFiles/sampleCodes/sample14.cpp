//
// CPP sample14.cpp
//
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char *argv[]) {
  ifstream ifile; 

  ifile.open("data01.dat");
  
  if (ifile.fail()){
    cout << "file not found" << endl;
    return 0;
  }

  int i,j;
  int ti = 0;
  int tj = 0;
  while(1){
    ifile >> i >> j;
    if (ifile.eof()) break;

    ti += i;
    tj += i;
  }
  ifile.close();

  cout << "totail i =" << ti << endl;
  cout << "totail j =" << tj << endl;

  return 0;
}
