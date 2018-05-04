//
// sample42.cpp
//
#include <iostream>
#include <string>
#include <vector>

int main(int argc, const char * argv[])
{
    // input strings
    std::vector<std::string> buf;
    while(1){
        std::cout << "input:";
        std::string s1;
        std::getline(std::cin, s1);
        if (s1.empty()) break;
        buf.push_back(s1);
    }
    // print all
    for (int i = 0 ; i < buf.size() ; i++){
        std::cout << buf[i] << std::endl;
    }
    return 0;
}
