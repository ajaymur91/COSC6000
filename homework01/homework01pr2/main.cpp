#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int sum=0,i,value;
    double average;
    cout << "Enter 5 whole numbers to find the average: " << endl;
    for(i=0;i<5;i++){
        cin >> value;
        sum+=value;
    }
    average=sum/(double)i;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << "The average for the numbers: " <<average << endl;
    
    return 0;
}
