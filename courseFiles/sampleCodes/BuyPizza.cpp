//
//  main.cpp
//  BuyPizza
//
//  Created by Hideki Fujioka on 2/3/17.
//  Copyright © 2017 Hideki Fujioka. All rights reserved.
//
/*
Input:
 – Diameter of two sizes of pizza.
 – Cost of the same two sizes of pizza.
+ Output:
 – Cost per square inch for each size of pizza.
 – Which size is the best buy,
    * Based on lowest price per square inch,
    * If cost per square inch is the same, the smaller size will be the better buy.
*/
#include <iostream>
double unitprice(int diameter, double price);
// Returns the price per square inch of a pizza
// The formal parameter named diameter is the
// diameter of the pizza in inches. The formal
// parameter named price is the price of the
// pizza.

int main(int argc, const char * argv[]) {
    // Subtask 1
    // – Get the input data for each size of pizza
    std::cout << "Input Size and Price of Small Pizza:";
    double price_small;
    int size_small;
    std::cin >> size_small;
    std::cin >> price_small;
    std::cout << "Input Size and Price of Large Pizza:";
    double price_large;
    int size_large;
    std::cin >> size_large >> price_large;
    // Subtask 2
    // – Compute price per inch for smaller pizza
    double unit_price_small = unitprice(size_small,price_small);
    // Subtask 3
    //  – Compute price per inch for larger pizza
    double unit_price_large = unitprice(size_large,price_large);
    // Subtask 4
    //  – Determine which size is the better buy
    if (unit_price_small <= unit_price_large){
        std::cout << "Smaler Pizza is the better buy.\n";
    }else{
        std::cout << "Larger Pizza is the better buy.\n";
    }
    // Subtask 5
    // – Output the results
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
    std::cout << "Small Size="
                << size_small
                << "inch $"
                << price_small
                << " Unit Price $" << unit_price_small
                << std::endl;
    std::cout << "Large Size="
                << size_large
                << "inch $"
                << price_large
                << " Unit Price $" << unit_price_large
                << std::endl;
    return 0;
}
double unitprice (int diameter, double price)
{
    const double PI = 3.14159;
    double radius, area;
    radius = diameter * 0.5;
    area = PI * radius * radius;
    return (price / area);
}
