//
//  hourlyemployee.hpp
//  sample
//
//  Created by Hideki Fujioka on 4/14/16.
//  Copyright © 2016 Hideki Fujioka. All rights reserved.
//

#ifndef hourlyemployee_h
#define hourlyemployee_h
#include <string>
#include "employee.h"

namespace cosc3000
{
    class HourlyEmployee:public Employee
    {
    public:
        /// default constructor
        HourlyEmployee();
        /// constructor takes name, ssn, wage rate, and hours
        HourlyEmployee(std::string the_name,std::string the_ssn,
                       double the_wage_rate,double the_hours);
        /// set wage rate
        void set_rate(double new_wage_rate);
        /// get wage rate
        double get_rate() const;
        /// set hours worked
        void set_hours(double hours_worked);
        /// get hours worked
        double get_hours() const;
        /// print check
        void print_check();
    private:
        double wage_rate;
        double hours;
    };
}// cosc30000
#endif /* hourlyemployee_h */
