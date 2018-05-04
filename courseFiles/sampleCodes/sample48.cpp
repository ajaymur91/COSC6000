///
/// sample48.cpp
///
#include <iostream>
#include "hourlyemployee.h"
#include "salariedemployee.h"

int main(int argc, char **argv)
{
    cosc3000::HourlyEmployee hideki;
    hideki.set_name("Hideki Fujioka");
    hideki.set_ssn("123-45-6789");
    hideki.set_rate(20.50);
    hideki.set_hours(40);
    std::cout << "Check for " << hideki.get_name()
            << " for " << hideki.get_hours() << " hours.\n";
    hideki.print_check();
    std::cout << std::endl;
    
    cosc3000::SalariedEmployee boss("Dr. Big Shot","987-65-4321",10500.50);
    std::cout << "Check for " << boss.get_name() << std::endl;
    boss.print_check();
    return 0;
}

