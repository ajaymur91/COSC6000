//
// sample39.cpp
//
//
#include <iostream>
#include <iomanip>
#include "timeday.h"

// main function
int main(int argc, const char * argv[]) {
    cosc3000::TimeOfDay time1(20,30);
    cosc3000::TimeOfDay time2(4,27);
    
    std::cout << "time1=" << time1 << std::endl;
    std::cout << "time2=" << time2 << std::endl;

    cosc3000::TimeOfDay time3 = time1 + time2;
    std::cout << "time3=time1+time2=" << time3 << std::endl;
    
    return 0;
}
