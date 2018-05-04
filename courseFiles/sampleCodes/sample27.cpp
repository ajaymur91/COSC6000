//
// sample27.cpp
//

#include <iostream>

// class definition
class BankAccount
{
public:
    BankAccount(int dollars, int cents, double rate);
    // Postcondition: The account balance has been set $dollars.cents;
    // The interest rate has been set to rate percent.
    
    BankAccount(int dollars, double rate);
    // Postcondition: The account balance has benn set to $dollars.00.
    // The interest rate has been set to rate percent.
    
    BankAccount(); // Default constructor
    // Initializes the account balance to $0.00 and the interest rate to 0.0%
    
    void update();
    // Postcodition: One year of simple interest has been
    // added to the account balance.
    
    double get_balance();
    // Returns the current account balance.
    
    double get_rate();
    // Returns the current account interest rate as a percentage.
    
    void output(std::ostream& outs);
    // Precondition: If outs is a file output stream, outs has already
    // been connected to a file.
    // Postcondition: Account balance and interest rate have been
    // written to the stream outs.
    
private:
    int dollar_part;
    int cents_part;
    double interest_rate;
    
    double fraction(double percent);
    // Converts a percentage to a fraction.
    
    double percent(double fraction_value);
    // Converts a fraction to a percentage
};

BankAccount::BankAccount(int dollars, int cents, double rate)
    :dollar_part(dollars),cents_part(cents),interest_rate(rate)
{
    if ((dollars < 0) || (cents < 0) || (rate < 0)){
        std::cout << "Illegal values for money or interest rate.\n";
        exit(-1);
    }
}

BankAccount::BankAccount(int dollars, double rate)
    :dollar_part(dollars),cents_part(0),interest_rate(rate)
{
    if ((dollars < 0) || (rate < 0)){
        std::cout << "Illegal values for money or interest rate.\n";
        exit(-1);
    }
}

BankAccount::BankAccount():dollar_part(0),cents_part(0),interest_rate(0)
{
    // nothing to do
}
void BankAccount::update()
{
    double balance = get_balance();
    balance += fraction(interest_rate) * balance;
}

double BankAccount::get_balance()
{
    return dollar_part + 0.01 * cents_part;
}

double BankAccount::get_rate()
{
    return interest_rate;
}

void BankAccount::output(std::ostream& outs)
{
    outs.setf(std::ios::fixed);
    outs.setf(std::ios::showpoint);
    outs.precision(2);
    outs << "Account balance $" << get_balance() << std::endl;
    outs << "Interest rate " << interest_rate << "%" << std::endl;
}

double BankAccount::fraction(double percent)
{
    return percent / 100.0;
}

double BankAccount::percent(double fraction_value)
{
    return fraction_value * 100.0;
}

// main function
int main(int argc, const char * argv[]) {
    BankAccount account1(123, 99, 3.0), account2;
    std::cout << "Start Test:\n";
    
    std::cout << "account1 initial statement:\n";
    account1.output(std::cout);
    
    std::cout << "account2 initial statement:\n";
    account2.output(std::cout);
    
    account1 = BankAccount(999,99,5.5); // explicit call to the constructor
    std::cout << "account1 new setup:\n";
    account1.output(std::cout);
    
    return 0;
}
