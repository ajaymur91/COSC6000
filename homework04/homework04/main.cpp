#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>

const double NULLTEMP=-99; //creating constants nullTemp that will disregard the temperature from when no data was entered that day
const double CUTTEMP=32; //the temperature cutoff of values to be read on screen or file.

using namespace std;

bool screenOrFile(void){
    bool response;
    char ans[256];
    cin >> ans;
    if(ans[0]=='Y' || ans[0]=='y'){
        return response=true;
    }
    return response=false;
}

void tempFunc(ifstream& infile,ostream& outfile){
    double temp;
    int day,month,year;
    outfile << "\nDays where it has been colder than 32F" << endl;
    outfile << "Month" << setw(6) << "Day" << setw(8) << "Year" << setw(22) << "Temperature (F)" << endl;
    while(infile>>month>>day>>year>>temp){
        if(temp<CUTTEMP && temp!=NULLTEMP){
            outfile << month << setw(8) << day << setw(10) << year << setw(11) << temp << endl;
        }
    }
}

int main(){
    bool response;
    ifstream infile;
    infile.open("/Users/dgomez/Desktop/COSC6000/homework04/LANEWORL.txt");
    if(!infile){
        cout << "error opening file" << endl;
    }
    cout << "Would you like to see temperature values on the screen? \n\n[Y / N]" << endl;
    cout << "\n\n\n               *******NOTE*******" << endl;
    cout << "        If [N] file will be written to COSC6000/homework04" << endl;
    response=screenOrFile();
    if(response==true){
        tempFunc(infile,cout);
    }
    else{
        ofstream outfile;
        outfile.open("/Users/dgomez/Desktop/COSC6000/homework04/temp.txt",ios::out);
        tempFunc(infile,outfile);
        outfile.close();
    }
    return 0;
}

