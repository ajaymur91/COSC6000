//
// sample33.cpp
//

#include <iostream>

// class definition

class DayOfYear
{
public:
    DayOfYear(int month, int day);
    // precondition : month and day form a possible date.
    // Initializes the date according to the arguments.
    DayOfYear();
    // Initialize the tade to January first
    friend bool equal(const DayOfYear& date1, const DayOfYear& date2);
    // precondition : date1 and date2 have values.
    // returns true if date1 and date2 represents the same date;
    // otherwise,  return false
    void output( ) const;
    void set(int new_month, int new_day);
    int get_day();
    int get_month();
private:
    int month;
    int day;
    
};
// Member Function definition (implementation)

DayOfYear::DayOfYear(int month, int day):month(month),day(day)
{
}
DayOfYear::DayOfYear():month(1),day(1)
{
}

void DayOfYear::output() const
{
    std::cout << "month = " << month
    <<  ",  day = " << day
    << std::endl;
}

void DayOfYear::set(int new_month, int new_day)
{
    month = new_month;
    day = new_day;
}

int DayOfYear::get_day(){
    return day;
}

int DayOfYear::get_month(){
    return month;
}

// friend
bool equal(const DayOfYear& date1, const DayOfYear& date2)
{
    //date1.output();
    //date2.output();
    return (date1.month == date2.month &&
            date1.day == date2.day );
}

// main function
int main(int argc, const char * argv[]) {
    DayOfYear today(2,29);
    DayOfYear leapday(2, 29);
    
    if (equal(today,leapday)){
        std::cout << "Today is leap day\n";
    }
    today.output();
    
    return 0;
}

