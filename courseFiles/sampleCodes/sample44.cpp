//
// sample44.cpp
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "timeday.h"

// Binary function that accepts two TimeOfDay objects
// and returns a value convertible to bool.
// The value returned indicates whether the first argument is
// earlier than the second.
bool isEarlier (const cosc3000::TimeOfDay& t1, const cosc3000::TimeOfDay& t2)
{
    int min1 = t1.get_hours() * 60 + t1.get_minutes();
    int min2 = t2.get_hours() * 60 + t2.get_minutes();
    if (min1 < min2) return true;
    return false;
}


int main(int argc, const char * argv[])
{
    // Making List of Time 
    std::vector<cosc3000::TimeOfDay> times;
    for (int i = 0 ; i < 10 ; i++){
        cosc3000::TimeOfDay time(rand() % 1440);
        std::cout << time << std::endl;
        times.push_back(time);
    }
    std::cout << "sort\n";
    std::sort(times.begin(),times.end(),isEarlier);
    std::vector<cosc3000::TimeOfDay>::iterator it;
    for (it =  times.begin() ; it != times.end() ; it++){
        std::cout << *it << std::endl;
    }
    
    return 0;
}
