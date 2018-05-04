//
// sample25.cpp
//

#include <iostream>

// class definition
class BankAccount
{
public:
    void set(int dollars, int cents, double rate);
    // Postcondition: The account balance has been set $dollars.cents;
    // The interest rate has been set to rate percent.
    
    void set(int dollars, double rate);
    // Postcondition: The account balance has benn set to $dollars.00.
    // The interest rate has been set to rate percent.
    
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
    double balance;
    double interest_rate;
    
    double fraction(double percent);
    // Converts a percentage to a fraction.
};

void BankAccount::set(int dollars, int cents, double rate)
{
    if ((dollars < 0) || (cents < 0) || (rate < 0)){
        std::cout << "Illegal values for money or interest rate.\n";
        exit(-1);
    }
    balance = dollars + 0.01 * cents;
    interest_rate = rate;
}

void BankAccount::set(int dollars, double rate)
{
    set(dollars,0,rate);
}

void BankAccount::update()
{
    balance += fraction(interest_rate) * balance;
}

double BankAccount::get_balance()
{
    return balance;
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
    outs << "Account balance $" << balance << std::endl;
    outs << "Interest rate " << interest_rate << "%" << std::endl;
}

double BankAccount::fraction(double percent)
{
    return percent / 100.0;
}

// main function
int main(int argc, const char * argv[]) {
    BankAccount account1, account2;
    std::cout << "Start Test:\n";
    
    account1.set(123, 99, 3.0);
    std::cout << "account1 initial statement:\n";
    account1.output(std::cout);
    
    account1.set(100, 5.0);
    std::cout << "account1 with new setup:\n";
    account1.output(std::cout);
 
    account2 = account1;
    std::cout << "account2:\n";
    account2.output(std::cout);
    
    return 0;
}
