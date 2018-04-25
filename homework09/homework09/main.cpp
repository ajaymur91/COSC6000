#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "USLength.hpp"
#include "BaseballPark.hpp"

int main(){
    std::ifstream infile;
    infile.open("/Users/dgomez/Desktop/COSC6000/homework09/MajorLeagueBallparks.csv");// Path to the CSV file
    if (infile.fail()){
        std::cout << "file not found\n";
        return -1;
    }
    std::string franchise;
    std::string stadium;
    std::string city;
    int capacity;
    int yards;
    int feet;
    std::string entry;
    
    std::string line;
    std::vector<park::BaseballPark> list;
    while (std::getline(infile,line)){
        std::stringstream ststrm(line);
        std::getline(ststrm,franchise,',');
        std::getline(ststrm,stadium,',');
        std::getline(ststrm,city,',');
        std::getline(ststrm,entry,',');
        capacity = std::stoi(entry);
        std::getline(ststrm,entry,',');
        yards = std::stoi(entry);
        std::getline(ststrm,entry);
        feet = std::stoi(entry);
        
        length::USLength centerField(yards,feet,0);
        park::BaseballPark bbpark(franchise,stadium,city,capacity,centerField);
        list.push_back(bbpark);
        
    }
    infile.close();
    std::sort(list.begin(), list.end(), [](const park::BaseballPark &bp1,const park::BaseballPark &bp2)
              {
                  return (bp1.get_dimension() > bp2.get_dimension());
              });
    std::ofstream outfile;
    outfile.open("/Users/dgomez/Desktop/COSC6000/homework09/sorted.txt");
    
    
    for(auto bp: list){
        outfile << bp << std::endl;
    }
    outfile.close();
    return 0;
    
}
