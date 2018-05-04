//
// sample38.cpp
//
//
#include <iostream>
#include <iomanip>
#include "timeday.h"

using namespace cosc3000;

// main function
int main(int argc, const char * argv[]) {
    TimeOfDay time1(24,33);
    TimeOfDay time2(1,-27);
    
    std::cout << "time1=" << time1 << std::endl;
    std::cout << "time2=" << time2 << std::endl;
    if (time1 == time2){
        std::cout << "time1 and time2 are same\n";
    }
    TimeOfDay time3 = time1 + time2;
    std::cout << "time3=time1+time2=" << time3 << std::endl;
    
    TimeOfDay time4 = time3 - time2;
    std::cout << "time4=time3-time2=" << time4 << std::endl;
    
    TimeOfDay time5 = time3 + 10;
    std::cout << "time5=time3+10=" << time5 << std::endl;
    
    TimeOfDay time6 = -time5;
    std::cout << "time6=-time5=" << time6 << std::endl;
    
    TimeOfDay time7 = ++time6;
    std::cout << "time7=++time6=" << time7 << std::endl;
    
    std::cout << "Input time :";
    std::cin >> time1;
    std::cout << "time1=" << time1 << std::endl;
    
    time1 += time2;
    std::cout << "time1+time2=" << time1 << std::endl;
    
    time1 -= time2;
    std::cout << "time1-time2=" << time1 << std::endl;
    
    return 0;
}
