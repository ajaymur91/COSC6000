#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double penPrice, totalPrice;
    int penNumber;
    
    cout << "Enter the price of a pen in dollars: $";
    cin >> penPrice;
    cout << "\nEnter the number of pens: ";
    cin >> penNumber;
    totalPrice = penPrice*penNumber;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "The total price of the pen(s) is: $"<<totalPrice<<endl;
    return 0;
    
}

