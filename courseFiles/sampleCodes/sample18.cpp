//
// sample18.cpp
//
#include <iostream>
#include <fstream>

void say_hello(std::ostream& any_out_stream)
{
    any_out_stream << "Hello COSC3000/6000\n";
}

int main(int argc, const char *argv[])
{
    // output to screen
    say_hello(std::cout);
    
    // output to a file
    std::ofstream fout;
    fout.open("output.dat");
    say_hello(fout);
    fout.close();
 
    return 0;
}

