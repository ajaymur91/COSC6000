//
// sample20.cpp
//
// This program reads in an amount of money in dollar and cent
// and output the exchanged money in euro and cent.
// Using exchange rate : 1.00 USD = 0.883022 EUR
//

#include <iostream>

const double rateUSD2EURO = 0.883022; // global constat variable

double inputDollar(void );
// This function has no input argument. (void)
// Print messsage on screen that ask for input an amount of money in dollar and cent.
// Get two values from keyboard
// Convert a dollar and cent to a dollar: total_dollar = dollar + cent * 0.01
// return total_dollar

double convertDollarToEuro(double total_dollar);
// This function takes one "double" variable, Dollar.
// Convert a dollar to an euro: total_euro = total_dollar * [exchange rate]
// return total_euro

void outputEuro(double total_euro);
// This function takes one "double" variables, total_euro.
// Convert an euro to an euro and cent: euro = static_cast<int>(total_euro), cent = (total_euro - euro) * 100
// Output those two values to screen

bool askYesOrNo(void );
// This function asks user to type in Y or N
// This function return true if user type in Y otherwise return false


// main function
int main(int arc, char **argv){
    do{
        double dollar = inputDollar();
        double euro = convertDollarToEuro(dollar);
        outputEuro(euro);
        std::cout << "Repeat? [Y/N] :";
    }while(askYesOrNo());
    
    return 0;
}

double inputDollar(void){
    int dollar, cent;
    std::cout << "Input USD Dollar and Cent :";
    std::cin >> dollar >> cent;
    double total_dollar = dollar + cent * 0.01;
    
    return total_dollar;
}

double convertDollarToEuro(double total_dollar){
    double total_euro = total_dollar * rateUSD2EURO;
    return total_euro;
}

void outputEuro(double total_euro){
    int euro = total_euro; // cut-off under decimol values
    int cent = 100 * (total_euro - euro); // cut-off under decimol
    std::cout << euro << "Euro and " << cent << "Cents\n";
}

bool askYesOrNo(void ){
    char ans[256];
    std::cin >> ans;
    if ((ans[0] == 'Y') || (ans[0] == 'y')) return true;
    return false;
}


