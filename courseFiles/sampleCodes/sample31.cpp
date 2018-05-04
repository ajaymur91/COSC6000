//
// sample31.cpp
// compare with sample30.cpp

#include <iostream>

enum Direction{North,South,East,West};

void translate(int& x, int& y, Direction direction){
    switch(direction){
        case North:
            y += 1;
            break;
        case South:
            y -= 1;
            break;
        case East:
            x += 1;
            break;
        case West:
            x -= 1;
            break;
        default:
            std::cout << "Wrong Direction\n";
            break;
    }
}
int main(int argc, const char * argv[]) {
    int x = 0;
    int y = 0;
    
    std::cout << "(" << x << "," << y <<")\n";
    translate(x, y, North);
    std::cout << "(" << x << "," << y <<")\n";
    translate(x, y, North);
    std::cout << "(" << x << "," << y <<")\n";
    translate(x, y, East);
    std::cout << "(" << x << "," << y <<")\n";
    translate(x, y, East);
    
    return 0;
}


