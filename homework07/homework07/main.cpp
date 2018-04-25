#include <iostream>
#include "USLength.hpp"

using namespace diego;

int main(int argc, const char * argv[]){
    USLength L1(1,2,9);
    USLength L2(1,2,11);
    
    std::cout << "Length 1: " << L1 << std::endl;
    std::cout << "Length 2: " << L2 << std::endl;
    if(L1 == L2){
        std::cout << "Lengths are the same\n";
    }
    if(L1 < L2){
        std::cout << "Length 2 is greater than Length 1\n";
    }
    if(L1 <= L2){
        std::cout << "Length 2 is greater than or equal to Length 1\n";
    }
    if(L1 >= L2){
        std::cout << "Length 1 is greater than or equal to Length 2\n";
    }
    if(L1 > L2){
        std::cout << "Length 1 is greater than Length 2\n";
    }
    
    USLength L3=L1+L2;
    USLength L4=(L1+=L2);
    USLength L5=L1*10;
    USLength L6=10*L1;
    USLength L7=L2/5;
    USLength L8=(L2*=5);
    USLength L9=(L1/=2);
    std::cout << "Length 1 + Length 2 = " << L3;
    std::cout << "\nLength 1 += Length 2 = " << L4;
    std::cout << "\nLength 1 * 10 = " << L5;
    std::cout << "\n10 * Length 1 = " << L6;
    std::cout << "\nLength 2 / 5 =" << L7;
    std::cout << "\nLength 1 *= 5 =" << L8;
    std::cout << "\nLength 1 /= 2 =" << L9;
    return 0;
}

