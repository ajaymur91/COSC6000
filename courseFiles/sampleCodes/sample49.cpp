///
/// sample49.cpp
///
#include <iostream>
#include "discountsale.h"

int main(int argc, char **argv)
{
    /// One item at $10.00
    cosc3000::Sale simple(10.00);
    /// One item at $11.00 with a 10% discount
    cosc3000::DiscountSale discount(11.00, 10);
    
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
    
    if (discount < simple){
        std::cout << "Discounted item is cheaper.\n";
        std::cout << "Saving is $" << simple.savings(discount)
                    << std::endl;
    }else{
        std::cout << "Discount item is not cheaper.\n";
    }
    
    return 0;
}
