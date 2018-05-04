// Program to compute state income tax.
#include <iostream>

double statetax(int net_income);
// Precondition: The formal parameter net_income is net income,
// rounded up to a whole number of dollars.
// Returns the amount of state income tax due to computed as follows:
// No tax on income up to $15,000;
// 5% on income between $15,001 and $25,000;
// 10% on income over $25,000.

int main(int arc, char *argv[]){
    int net_income;
    std::cout << "Enter net income (rounded to whole dollars) $";
    std::cin >> net_income;
    
    double tax_bill = statetax(net_income);
    
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
    std::cout << "Net income = $" << net_income << std::endl;
    std::cout << "Tax bill = $" << tax_bill << std::endl;
    
    return 0;
}

double statetax(int net_income){
    if (net_income <= 15000)
        return 0;
    else if (net_income <= 25000)
        // return 5% of amount over $15,000
        return 0.05 * (net_income - 15000);
    else // net_income > $25,000
    {
        // five_percent_tax = 5% of income from $15,000 to $25,000
        double five_percent_tax = 0.05 * 10000;
        // ten_percent_tax = 10% of income over $25,000
        double ten_percent_tax = 0.10 * (net_income - 25000);
        return five_percent_tax + ten_percent_tax;
    }
}

