//
// sample17.cpp
//
#include <iostream>
#include <fstream>

void better_two_sum(std::istream& source_file)
{
    int n1, n2;
    source_file >> n1 >> n2;
    std::cout << n1 << " + " << n2 << " = " << (n1 + n2) << std::endl;
}

int main(int argc, const char *argv[])
{
    // input from keyboard
    std::cout << "Input two integer numbers : ";
    better_two_sum(std::cin);
    
    // input from a file
    std::ifstream fin;
    fin.open("input.dat");
    better_two_sum(fin);
    fin.close();
 
    return 0;
}

