//
//  salariedemployee.cpp
//  sample
//
//  Created by Hideki Fujioka on 4/14/16.
//  Copyright © 2016 Hideki Fujioka. All rights reserved.
//
#include <iostream>
#include "salariedemployee.h"
namespace cosc3000
{
    SalariedEmployee::SalariedEmployee():Employee(),salary(0)
    {
        /// intentionally blank
    }
    
    SalariedEmployee::SalariedEmployee(std::string the_name,
                                       std::string the_ssn,
                                       double the_weekly_salary)
    :Employee(the_name,the_ssn),salary(the_weekly_salary)
    {
        /// intentionally blank
    }
    
    double SalariedEmployee::get_salary() const
    {
        return salary;
    }
    
    void SalariedEmployee::set_salary(double new_salary)
    {
        salary = new_salary;
    }
    
    void SalariedEmployee::print_check()
    {
        /// Compute net: pay = salary
        set_net_pay(salary);
        std::cout << "_______________________________________________\n";
        std::cout << "Pay to the order of " << get_name() << std::endl;
        std::cout << "The sum of " << get_net_pay() << " Dollars\n";
        std::cout << "_______________________________________________\n";
        std::cout << "Check Stub : NOT NEGOTIABLE\n";
        std::cout << "Employee Number: " << get_ssn() << std::endl;
        std::cout << "Salaried Employee. Regular Pay:" << salary << std::endl;
        std::cout << "_______________________________________________\n";
    }
}//cosc3000