#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>

const double nullTemp=-99; //data that wasn't recorded for that day is -99 in file

using namespace std;

void tempFunc(ifstream& infile){ //tempFunc reads an ifstream file
    double temp,minTemp; //def of temp and the minimum temperature
    int day,month,year,minDay,minMonth,minYear; // def of dates and mindate
    infile>>minMonth>>minDay>>minYear>>minTemp; //sets first minDates to first date
    while(infile>>month>>day>>year>>temp){ //while loop insures all lines of data are read
        if(temp<minTemp && temp!=nullTemp){ //if the temp is less than the min temp and isn't the null temp
            minTemp=temp; //change the new minTemp and minDates
            minDay=day;
            minYear=year;
            minMonth=month;
        }
    }
    //display at the end of the loop
    cout << "The minimum temperatrue in New Orleans occurred on: " << endl;
    cout << "Month " << "Day " << "Year " << "Temp " << endl;
    cout << minMonth << "     " << minDay << "   " << minYear << " " << minTemp << endl;
}

int main(){ //main func
    ifstream infile; //def ifstream var as infile
    infile.open("/Users/dgomez/Downloads/LANEWORL.txt"); //open the file
    if(!infile){ //if you can't open file display error
        cout << "error" << endl;
    }
    tempFunc(infile); //call tempFunc
    infile.close(); //close file
    return 0;
}
