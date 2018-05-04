//
// CPP sample22.cpp
//
#include <iostream>
#include <cmath>

using namespace std;

struct Vector2d{
    double x;
    double y;
};

Vector2d rotate(double a, Vector2d p){
    Vector2d q;
    q.x = p.x * cos(a) - p.y * sin(a);
    q.y = p.x * sin(a) + p.y * cos(a);

    return q;
}

int main (int argc, char *argv[]) {
    Vector2d x1 = {1.0, 0.0};
    
    cout << "(" << x1.x << "," << x1.y << ")" << endl;
    
    x1 = rotate(M_PI / 4.0, x1);
    cout << "(" << x1.x << "," << x1.y << ")" << endl;
 
    x1 = rotate(M_PI / 4.0, x1);
    cout << "(" << x1.x << "," << x1.y << ")" << endl;
    
    x1 = rotate(M_PI / 4.0, x1);
    cout << "(" << x1.x << "," << x1.y << ")" << endl;
    
    x1 = rotate(M_PI / 4.0, x1);
    cout << "(" << x1.x << "," << x1.y << ")" << endl;
    
    x1 = rotate(M_PI / 4.0, x1);
    cout << "(" << x1.x << "," << x1.y << ")" << endl;
    
    x1 = rotate(M_PI / 4.0, x1);
    cout << "(" << x1.x << "," << x1.y << ")" << endl;
    
    x1 = rotate(M_PI / 4.0, x1);
    cout << "(" << x1.x << "," << x1.y << ")" << endl;

    x1 = rotate(M_PI / 4.0, x1);
    cout << "(" << x1.x << "," << x1.y << ")" << endl;
    
    return 0;
}

