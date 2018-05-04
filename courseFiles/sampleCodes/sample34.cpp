//
// sample34.cpp
//

#include <iostream>
#include <iomanip>

// class for Duration Of Time

class TimeOfDay
{
public:
    TimeOfDay(int hours, int minutes);
    // precondition : hours and minutes are integers.
    // Initializes the time according to the arguments.
    // call checktime() to convert a right form.
    
    TimeOfDay(int minutes);
    // precondition : minutes is integers.
    // Initializes the time according to the arguments.
    // call checktime() to convert a right form.

    TimeOfDay();
    // Initialize the time to 00:00
    
    void output(std::ostream &strm) const;
    // Output time to stream
    
    int get_hours() const;
    // return hours
    
    int get_minutes() const;
    // return minutes
    
    friend bool equal(const TimeOfDay& t1, const TimeOfDay& t2);
    // precondition : t1 and t2 have values.
    // returns true if t1 and t2 represents the same time;
    // otherwise,  return false
    
    friend TimeOfDay add(const TimeOfDay& t1, const TimeOfDay& t2);
    // precondition : t1 and t2 have values.
    // returns t1 + t2
    
    friend TimeOfDay subtract(const TimeOfDay& t1, const TimeOfDay& t2);
    // precondition : t1 and t2 have values.
    // returns t1 - t2
private:
    void checktime();
    // precondition : hours and minutes are set
    // Modify hours to be between 0 and 23.
    // Modify minutes to be between 0 and 59.
    // * If minutes<0, add 60 to minutes and subtract 1 from hours,
    //   repeat those until minutes >=0.
    // * If minutes>59, subtract 60 from minutes and add 1 to hours,
    //   repeat those until minutes <= 59.
    
    // hours
    int hours;
    // minutes
    int minutes;
    
};
// Member Function definition (implementation)
TimeOfDay::TimeOfDay(int hours, int minutes)
:hours(hours),minutes(minutes)
{
    checktime();
}
TimeOfDay::TimeOfDay(int minutes)
:hours(0),minutes(minutes)
{
    checktime();
}
TimeOfDay::TimeOfDay()
:hours(0),minutes(0)
{
}

void TimeOfDay::output(std::ostream &strm) const
{
    strm << std::setfill('0') << std::setw(2) << hours << ':'
    << std::setfill('0') << std::setw(2) << minutes << std::endl;
}

int TimeOfDay::get_hours() const
{
    return hours;
}


int TimeOfDay::get_minutes() const
{
    return minutes;
}

bool equal(const TimeOfDay& t1, const TimeOfDay& t2)
{
    return (t1.hours == t2.hours) && (t1.minutes == t2.minutes);
}

TimeOfDay add(const TimeOfDay& t1, const TimeOfDay& t2)
{
    TimeOfDay tsum(t1.hours + t2.hours, t1.minutes + t2.minutes);
    return tsum;
}

TimeOfDay subtract(const TimeOfDay& t1, const TimeOfDay& t2)
{
    TimeOfDay tsub(t1.hours - t2.hours, t1.minutes - t2.minutes);
    return tsub;
}

void TimeOfDay::checktime(){
    while(minutes < 0){
        minutes += 60;
        hours--;
    }
    while(minutes > 59){
        minutes -= 60;
        hours++;
    }
    while(hours < 0){
        hours += 24;
    }
    while(hours > 23){
        hours -= 24;
    }
}

// main function
int main(int argc, const char * argv[]) {
    TimeOfDay time1(24,33);
    TimeOfDay time2(1,-27);
    
    std::cout << "time1=";
    time1.output(std::cout);
    std::cout << "time2=";
    time2.output(std::cout);
    if (equal(time1,time2)){
        std::cout << "time1 and time2 are same\n";
    }
    TimeOfDay time3 = add(time1,time2);
    std::cout << "time3=time1+time2=";
    time3.output(std::cout);
    
    TimeOfDay time4 = subtract(time3,time2);
    std::cout << "time4=time3-time2=";
    time4.output(std::cout);
    return 0;
}
