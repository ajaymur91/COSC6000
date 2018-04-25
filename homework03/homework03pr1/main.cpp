#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>

const double LBS2KILO=2.2046; //Creating conversion constants
const int GRAM2KILO=1000;
const int OZ2LBS=16;

using namespace std;

bool yesOrNo(void){  //yes or no has the user enter "yes" or no
    char ans[256];   //this function is used to allow user to continue to
    cin>>ans;       //convert numbers or to let them exit the program by returning
    if((ans[0] == 'Y') || (ans[0] == 'y')) return true;//boolean operator true || false **postcondition
    return false;
}

int pounds(int kilo, double gram){ //this function converts int kilograms
    double intlb=(kilo+gram/GRAM2KILO)*LBS2KILO;//into an int value of pounds
    int lb=floor(intlb);
    return lb;
}

double ounces(int kilo, double gram){ //converts the decimal value of lbs into ounces
    double intlb=(kilo+gram/GRAM2KILO)*LBS2KILO;
    double intoz=abs(floor(intlb)-intlb);
    double oz=OZ2LBS*intoz;
    return oz;
}

double poundsTotal(int kilo, double gram){ //funct returns only lbs when user inputs kilos and grams
    double poundsOnly=(kilo+gram/GRAM2KILO)*LBS2KILO;
    return poundsOnly;
}
double ouncesTotal(int kilo, double gram){ //funct returns only oz when user inputs kilos and grams
    double ouncesOnly=(kilo+gram/GRAM2KILO)*LBS2KILO*OZ2LBS;
    return ouncesOnly;
}

int main(){ //main function
    int kilo=0; //defines user inputs of kilo and gram
    double gram=0;
    do{ //init of do while func. Want the program to constantly allow users
        //to enter in weights of kilograms and grams and return conversion until
        //yesOrNo returns false and breaks while
        cout << "Enter a weight in kilograms and grams" << endl;
        cout << "Kilograms: ";
        cin >> kilo;
        cout << "Grams: ";
        cin >> gram;
        cout << kilo << " kgs & " << gram << " g" << " is: \n" <<endl; //shows all the user inputs
        cout.setf(ios::fixed); // next lines set decimal precision in output
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << pounds(kilo,gram)  << " lbs & " << ounces(kilo,gram) << " oz" << endl << endl;
        cout<<"This is also: " << poundsTotal(kilo,gram) << " lbs or " << ouncesTotal(kilo,gram) << " oz" <<endl;
        cout << "Do you wish to continue? [Y/N]" << endl;
    }while(yesOrNo()); //when function calls function yesOrNo() user can either
    //return true, bringing user back to do{ where user will define new kilo and
    //grams to be converted. This loop will continue until yesOrNo() is called and
    //user returns false. At this point the program will end **precondition
    
    return 0;
}
