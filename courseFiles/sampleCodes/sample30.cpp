//
// sample30.cpp
// compare with sample31.cpp

#include <iostream>

void translate(int& x, int& y, int direction){
    switch(direction){
        case 0:
            y += 1;
            break;
        case 1:
            y -= 1;
            break;
        case 2:
            x += 1;
            break;
        case 3:
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
    translate(x, y, 0);
    std::cout << "(" << x << "," << y <<")\n";
    translate(x, y, 0);
    std::cout << "(" << x << "," << y <<")\n";
    translate(x, y, 2);
    std::cout << "(" << x << "," << y <<")\n";
    translate(x, y, 2);
    
    return 0;
}


