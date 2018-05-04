//
//  main.cpp
//  sample01
//
//  Created by Hideki Fujioka on 3/12/13.
//  Copyright (c) 2013 Tulane University. All rights reserved.
//
/*
  this is comments
 */
#include <iostream>

int main(int argc, const char * argv[])
{

    // cout is in the namespace 'std'
    std::cout << "Hello, World!\n";
    std::cout << "Hello, World!" << std::endl;

    using namespace std;
    cout << "Hello, World!" << endl;

    return 0;
}

