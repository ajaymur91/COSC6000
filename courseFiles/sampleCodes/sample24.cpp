nclude <iostream>

// class definition
class DayOfYear
{
public:
    void output( ); //Member Function Declaration
    void set(int new_month, int new_day);
    int get_day();
    int get_month();
private:
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

// main function
int main(int argc, const char * argv[]) {
    DayOfYear today;
    today.set(2, 17);
    
    today.output();
    
    return 0;
}
