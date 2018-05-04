//
// CPP sample13.cpp
//
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main (int argc, char *argv[]) {
  ofstream ofile; 

  ofile.open("data01.dat");
  
  for (int i = 1 ; i <= 10 ; i++){
    for (int j = 1 ; j <= 10 ; j++){
      ofile << i << setw(4) << j <<endl;
    }
  }
  ofile.close();

  return 0;
}
