/*
 * sample04.cpp
 *
 *  Created on: Jan 15, 2016
 *      Author: fuji
 */
#include <iostream>

int main(int argc, const char * argv[]){
	int dividend, divisor;

	std::cout << "input two integers :\n";
	std::cout << "dividend=";
	std::cin >> dividend;
	std::cout << "divisor=";
	std::cin >> divisor;

	int quotient = dividend / divisor;
	int remainder dividend % divisor;

    std::cout << dividend << " / " << divisor << " = " << quotient << std::endl;
    std::cout << dividend << " % " << divisor << " = " << remainder << std::endl;
    return 0;
}



