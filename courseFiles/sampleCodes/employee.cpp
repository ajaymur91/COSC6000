//
//  employee.cpp
//  sample
//
//  Created by Hideki Fujioka on 4/14/16.
//  Copyright © 2016 Hideki Fujioka. All rights reserved.
//
#include <iostream>
#include <string>
#include <cstdlib>
#include "employee.h"

namespace cosc3000
{
    Employee::Employee():name("NA"),ssn("NA"),net_pay(0)
    {
        /// intentionally blank
    }
    
    Employee::Employee(std::string the_name,std::string the_ssn)
    :name(the_name),ssn(the_ssn),net_pay(0)
    {
        /// intentionally blank
    }
    std::string Employee::get_name() const
    {
        return name;
    }
    std::string Employee::get_ssn() const
    {
        return ssn;
    }
    double Employee::get_net_pay() const
    {
        return net_pay;
    }
    void Employee::set_name(std::string new_name)
    {
        name = new_name;
    }
    void Employee::set_ssn(std::string new_ssn)
    {
        ssn = new_ssn;
    }
    void Employee::set_net_pay(double new_net_pay)
    {
        net_pay = new_net_pay;
    }
    void Employee::print_check() const
    {
        std::cout << "ERROR\n";
        std::cout << "print_check FUNCTION CALLED FOR\n";
        std::cout << "AN UNDIFFERENTIATED EMPLOYEE.\n";
        exit(-1);
    }
}//cosc3000