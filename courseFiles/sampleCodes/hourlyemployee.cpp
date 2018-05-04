//
//  hourlyemployee.cpp
//  sample
//
//  Created by Hideki Fujioka on 4/14/16.
//  Copyright © 2016 Hideki Fujioka. All rights reserved.
//
#include <iostream>
#include "hourlyemployee.h"
namespace cosc3000
{
    HourlyEmployee::HourlyEmployee():Employee(),wage_rate(0),hours(0)
    {
        /// intentionally blank
    }
    HourlyEmployee::HourlyEmployee(std::string the_name,
                                   std::string the_ssn,
                                   double the_wage_rate,
                                   double the_hours)
     :Employee(the_name,the_ssn),wage_rate(the_wage_rate),hours(the_hours)
    {
        /// intentionally blank
    }
    
    void HourlyEmployee::set_rate(double new_wage_rate)
    {
        wage_rate = new_wage_rate;
    }
    
    double HourlyEmployee::get_rate() const
    {
        return wage_rate;
    }
    
    void HourlyEmployee::set_hours(double hours_worked)
    {
        hours = hours_worked;
    }
    
    double HourlyEmployee::get_hours() const
    {
        return hours;
    }
    
    void HourlyEmployee::print_check()
    {
        /// Compute net: pay = hours * wage_rate
        set_net_pay(hours * wage_rate);
        std::cout << "_______________________________________________\n";
        std::cout << "Pay to the order of " << get_name() << std::endl;
        std::cout << "The sum of " << get_net_pay() << " Dollars\n";
        std::cout << "_______________________________________________\n";
        std::cout << "Check Stub : NOT NEGOTIABLE\n";
        std::cout << "Employee Number: " << get_ssn() << std::endl;
        std::cout << "Hourly Employee.\n";
        std::cout << "Hours worked: " << hours;
        std::cout << " Rate: " << wage_rate << " Pay: " << get_net_pay() << std::endl;
        std::cout << "_______________________________________________\n";
    }
}// cosc3000