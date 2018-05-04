//
//  salariedemployee.hpp
//  sample
//
//  Created by Hideki Fujioka on 4/14/16.
//  Copyright © 2016 Hideki Fujioka. All rights reserved.
//

#ifndef salariedemployee_h
#define salariedemployee_h

#include <string>
#include "employee.h"

namespace cosc3000
{
    class SalariedEmployee:public Employee
    {
    public:
        /// default constructor
        SalariedEmployee();
        /// constructor takes name. ssn, and weekly salary
        SalariedEmployee(std::string the_name,std::string the_ssn,
                         double the_weekly_salary);
        /// get salary
        double get_salary() const;
        /// set salary
        void set_salary(double new_salary);
        /// print check
        void print_check();
    private:
        double salary;///< Weekly Salary
    };
} // cosc3000
#endif /* salariedemployee_h */
