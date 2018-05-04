//
// sample43.cpp
//
#include <iostream>
#include <vector>

int main(int argc, const char * argv[])
{
    const int size = 100;
    std::vector<int> x;
    for (int i = 0 ; i < size ; i++){
        std::cout << "size=" << x.size()
        << " capacity=" << x.capacity()
        << " address=" << x.data() << std::endl;
        x.push_back(i);
    }
    
    return 0;
}
