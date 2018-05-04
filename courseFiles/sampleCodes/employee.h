//
//  employee.hpp
//  sample
//
//  Created by Hideki Fujioka on 4/14/16.
//  Copyright © 2016 Hideki Fujioka. All rights reserved.
//

#ifndef employee_h
#define employee_h
#include <string>

namespace cosc3000
{
    class Employee
    {
    public:
        /// default constructor
        Employee();
        /// constructor takes name and ssn
        Employee(std::string the_name,std::string the_ssn);
        /// get name
        std::string get_name() const;
        /// get ssn
        std::string get_ssn() const;
        /// get new pay
        double get_net_pay() const;
        /// set name
        void set_name(std::string new_name);
        /// set ssn
        void set_ssn(std::string new_ssn);
        /// set net pay
        void set_net_pay(double new_net_pay);
        /// print check (do not call)
        void print_check() const;
    private:
        std::string name;///< Name
        std::string ssn; ///< SSN
        double net_pay;  ///< Net pay
    };
}//cosc3000
#endif /* employee_h */
