//
//  sample55.cpp
//
//  Created by Hideki Fujioka on 4/23/13.
//  Copyright (c) 2013 Tulane University. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class pets{
public:
  // constructor
  pets(){
    cout << "constructor of pets" << endl;
  }
  // destructor
  ~pets(){
    cout << "destructor of pets" << endl;
  }

  // member functions
  void give_name(string name){
    pet_name = name;
  }
  
  void show_name(){
    cout << "pet name is " << pet_name << endl;
  }
protected:
  string pet_name;
};

class dog: public pets{
public:
  // constructor
  dog(){
    cout << "constructor of dog" << endl;
  };
  // destructor
  ~dog(){
    cout << "destructor of dog" << endl;
  }
  void show_name(){
    cout << "dog name is " << pet_name << endl;
  }
};


int main(int argc, const char * argv[])
{
  pets mypet;
  mypet.give_name("GOO");

  mypet.show_name();

  dog mydog;
  mydog.give_name("POO");
  
  mydog.show_name();
  return 0;
}

