#include <iostream>

using namespace std;

double pPerV(double volume,double price){
    return price/volume;
}

int main(){
    double smallVol,largeVol,smallPrice,largePrice,largePperV,smallPperV;
    
    cout << "Enter in the volume of the small soda in liters: " ;
    cin >> smallVol;
    cout << "\nEnter in the cost of the small soda in dollars: $" ;
    cin >> smallPrice;
    cout << "\nEnter in the volume of the large soda in liters: " ;
    cin >> largeVol;
    cout << "\nEnter in the cost of the large soda in dollars: $" ;
    cin >> largePrice;
    
    largePperV=pPerV(largeVol,largePrice);
    smallPperV=pPerV(smallVol,smallPrice);
    
    if(smallPperV<=largePperV){
        cout << "\nThe small soda is a better value.\n\n" << endl;
    }
    else{
        cout << "\nThe large soda is a better value.\n\n" << endl;
    }
    return 0;
}
