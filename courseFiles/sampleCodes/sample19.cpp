//
// sample19.cpp
//
// This program reads in an amount of money in dollar and cent
// and output the exchanged money in euro and cent.
// Using exchange rate : 1.00 USD = 0.883022 EUR
//

#include <iostream>

const double rateUSD2EURO = 0.883022; // global constat variable

void inputDollarCent(int& dollar, int &cent);
// This function takes two integer variables, dollar and cent, with those reference,
// in order to return values assigned in this function to the upper routine.
// Print messsage on screen that ask for input an amount of money in dollar and cent.
// Get two values from keyboard

void convertDollarCentToEuroCent(int dollar, int centDollar, int& euro, int& centEuro);
// This function takes four integer variables, Dollar and Cent with values, and Euro and Cent with references.
// Three subtasks here
// subtask 2-1 : Convert a dollar and cent to a dollar: total_dollar = dollar + centDoller * 0.01
// subtaks 2-2 : Convert a dollar to an euro: total_euro = total_dollar * [exchange rate]
// subtask 2-3 : Convert an euro to an euro and cent: euro = static_cast<int>(total_euro), centEuro = (total_euro - euro) * 100

void outputEuroCent(int euro, int cent);
// This function takes two integer variables, euro and cent with values.
// Output those two values to screen

bool askYesOrNo(void );
// This function asks user to type in Y or N
// This function return true if user type in Y otherwise return false


// main function
int main(int arc, char **argv){
    int dollar, centDollar;
    int euro, centEuro;
    
    do{
        inputDollarCent(dollar, centDollar);
        convertDollarCentToEuroCent(dollar, centDollar, euro, centEuro);
        outputEuroCent(euro, centEuro);
        std::cout << "Repeat? [Y/N] :";
    }while(askYesOrNo());

    return 0;
}

void inputDollarCent(int& dollar, int &cent){
    std::cout << "Input USD Dollar and Cent :";
    std::cin >> dollar >> cent;
}

void convertDollarCentToEuroCent(int dollar, int centDollar, int& euro, int& centEuro){
    double total_dollar = dollar + centDollar * 0.01;
    double total_euro = total_dollar * rateUSD2EURO;
    euro = total_euro; // cut-off under decimol values
    centEuro = 100 * (total_euro - euro); // cut-off under decimol values
}

void outputEuroCent(int euro, int cent){
    std::cout << euro << "Euro and " << cent << "Cents\n";
}

bool askYesOrNo(void ){
    char ans[256];
    std::cin >> ans;
    if ((ans[0] == 'Y') || (ans[0] == 'y')) return true;
    return false;
}


