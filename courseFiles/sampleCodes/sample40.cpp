//
// sample40.cpp
//
#include <iostream>
#include "vector2d.h"

using namespace cosc3000;

int main(int argc, char **argv)
{
    vector2d a(1,2);
    vector2d b(3,4);
    
    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;
    
    vector2d c;
    c = a + b;
    std::cout <<"a+b=" << c << std::endl;
    
    c = a - b;
    std::cout <<"a-b=" << c << std::endl;
    
    double d = a * b;
    std::cout <<"a.b=" << d << std::endl;
    
    std::cout <<"a * 2=" << a * 2 << std::endl;
    std::cout <<"2 * a=" << 2 * a << std::endl;
    std::cout <<"a / 2=" << a / 2 << std::endl;
    std::cout <<"|b|=" << b.norm() << std::endl;
    
    return 0;
}
