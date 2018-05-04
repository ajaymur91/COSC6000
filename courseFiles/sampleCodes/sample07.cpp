/*
  CPP sample07.cpp
 */

#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
  int i;

  cout << "while-loop" << endl;
  i = 0;
  while(i < 5){
    cout << "i = " << i << endl;
    i++;
  }

  cout << "do-while-loop" << endl;
  i = 0;
  do{
    cout << "i = " << i << endl;
    i++;
  }while(i < 5);

  cout << "while-loop" << endl;  
  i = 5;  // INITIAL VALUE MAKES CONDITION OF LOOP FALSE
  while(i < 5){
    cout << "i = " << i << endl;
    i++;
  }

  cout << "do-while-loop" << endl;
  i = 5;  // INITIAL VALUE MAKES CONDITION OF LOOP FALSE
  do{
    cout << "i = " << i << endl;
    i++;
  }while(i < 5);

  return 0;
}
