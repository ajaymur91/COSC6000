//
// Sample16.cpp
//
#include <iostream>

int main (int argc, char *argv[]) {
    std::cout << "Type in :";
    char string[256];
    
    while(std::cin.peek() != '\n'){
        std::cin >> string;
        std::cout << string << std::endl;
    }
    return 0;
}
