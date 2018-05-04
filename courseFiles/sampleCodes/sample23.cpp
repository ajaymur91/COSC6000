//
// sample23.cpp
//

#include <iostream>

// class definition
class DayOfYear
{
public:
    void output( ); //Member Function Declaration
    int month;
    int day;
    
};

// Member Function definition (implementation)
void DayOfYear::output()
{
    std::cout << "month = " << month
            <<  ",  day = " << day
            << std::endl;
}

// main function
int main(int argc, const char * argv[]) {
    DayOfYear today;
    today.month = 2;
    today.day = 17;
    
    today.output();
    
    return 0;
}
