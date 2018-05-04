// Division By Zero 2
//
#include <iostream>
#include <exception>

using namespace std;

class DivideByZero:public exception{
    virtual const char* what() const throw()
    {
        return "Error: Division by zero!\n";
    }
};

double safe_divide(int top, int bottom) throw(DivideByZero);

double safe_divide(int top, int bottom) throw(DivideByZero){
    if (bottom == 0) throw DivideByZero();
        return top / static_cast<double>(bottom);
}

int main(int argc, char **argv)
{
    int numerator;
    int denominator;
    double quotient;
    cout << "Enter numerator:";
    cin >> numerator;
    cout << "Enter denominator:";
    cin >> denominator;
    try
    {
        quotient = safe_divide(numerator, denominator);
    }
    catch(exception& e)
    {
        cout << e.what();
        exit(-1);
    }
    cout << numerator << "/" << denominator << "=" << quotient << endl;
    cout << "Bye\n";
    return 0;
}

