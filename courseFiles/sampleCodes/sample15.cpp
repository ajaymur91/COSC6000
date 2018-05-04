//
// Sample15.cpp
//
#include <iostream>
#include <iomanip>

int main (int argc, char *argv[]) {
    double number = 123.456;
    // print number in default
    std::cout << "number=" << number << std::endl;
    // set precision 2
    std::cout.precision(2);
    std::cout << "number=" << number << std::endl;
    // set fixed decimal point and alway show the point
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
    std::cout << "number=" << number << std::endl;
    
    // use setprecision from "iomanip"
    std::cout << std::setprecision(1);
    std::cout << "number=" << number << std::endl;
    
    // set width
    std::cout.width(10);
    std::cout << number << std::endl;
    
    // set width left
    std::cout.setf(std::ios::left);
    std::cout.width(10);
    std::cout << number << number <<std::endl;
    
    // use setw from "iomanip"
    std::cout.unsetf(std::ios::left);
    std::cout << number << std::setw(10) << number <<std::endl;
    return 0;
}
