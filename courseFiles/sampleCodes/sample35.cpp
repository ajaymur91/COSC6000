//
// sample35.cpp
//
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
    // precondition : minutes are integers.
    // Initializes the time according to the arguments.
    // call checktime() to convert a right form.
    
    TimeOfDay();
    // Initialize the time to 00:00
    
    friend std::ostream& operator << (std::ostream &strm, const TimeOfDay& t1);
    // Output time to stream
    
    friend std::istream& operator >> (std::istream &strm, TimeOfDay& t1);
    // Input time from stream
    
    int get_hours() const;
    // return hours
    
    int get_minutes() const;
    // return minutes
    
    friend bool operator ==(const TimeOfDay& t1, const TimeOfDay& t2);
    // precondition : t1 and t2 have values.
    // returns true if t1 and t2 represents the same time;
    // otherwise,  return false
    
    friend TimeOfDay operator + (const TimeOfDay& t1, const TimeOfDay& t2);
    // precondition : t1 and t2 have values.
    // returns t1 + t2
    
    friend TimeOfDay operator += (TimeOfDay& t1, const TimeOfDay& t2);
    // precondition : t1 and t2 have values.
    // comput t1 + t2 and store result to t1
    // returns t1
    
    friend TimeOfDay operator -= (TimeOfDay& t1, const TimeOfDay& t2);
    // precondition : t1 and t2 have values.
    // comput t1 - t2 and store result to t1
    // returns t1
    
    friend TimeOfDay operator - (const TimeOfDay& t1, const TimeOfDay& t2);
    // precondition : t1 and t2 have values.
    // returns t1 - t2
    
    TimeOfDay operator - ();
    // returns - for both hours and minutes
    
    TimeOfDay operator ++ (); //overloaded prefix ++ operator
    // Incremant 1 minute
    // returns result
    
    TimeOfDay operator ++ (int); //overloaded postfix ++ operator
    // Increment 1 minute
    // returns the value before increment
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

std::ostream& operator << (std::ostream &strm, const TimeOfDay& t1)
{
    strm << std::setfill('0') << std::setw(2) << t1.hours << ':'
    << std::setfill('0') << std::setw(2) << t1.minutes;
    return strm;
}

std::istream& operator >> (std::istream &strm, TimeOfDay& t1)
{
    strm >> t1.hours >> t1.minutes;
    return strm;
}


int TimeOfDay::get_hours() const
{
    return hours;
}


int TimeOfDay::get_minutes() const
{
    return minutes;
}

bool operator == (const TimeOfDay& t1, const TimeOfDay& t2)
{
    return (t1.hours == t2.hours) && (t1.minutes == t2.minutes);
}

TimeOfDay operator + (const TimeOfDay& t1, const TimeOfDay& t2)
{
    TimeOfDay tsum(t1.hours + t2.hours, t1.minutes + t2.minutes);
    return tsum;
}

TimeOfDay operator += (TimeOfDay& t1, const TimeOfDay& t2)
{
    t1.hours += t2.hours;
    t1.minutes += t2.minutes;
    t1.checktime();
    return t1;
}

TimeOfDay operator -= (TimeOfDay& t1, const TimeOfDay& t2)
{
    t1.hours -= t2.hours;
    t1.minutes -= t2.minutes;
    t1.checktime();
    return t1;
}

TimeOfDay operator - (const TimeOfDay& t1, const TimeOfDay& t2)
{
    TimeOfDay tsub(t1.hours - t2.hours, t1.minutes - t2.minutes);
    return tsub;
}

TimeOfDay TimeOfDay::operator - ()
{
    TimeOfDay ans(-hours, -minutes);
    return ans;
}

TimeOfDay TimeOfDay::operator ++ ()
{
    minutes++;
    checktime();
    TimeOfDay ans(hours,minutes);
    return ans;
}

TimeOfDay TimeOfDay::operator ++ (int)
{
    TimeOfDay ans(hours,minutes);
    minutes++;
    checktime();
    return ans;
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
