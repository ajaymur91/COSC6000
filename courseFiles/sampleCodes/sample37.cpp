//
// sample37.cpp
//
#include <iostream>
#include <cmath>

class vector2d
{
public:
    // constructor
    vector2d();
    vector2d(double x,double y);
    
    // set x y
    void set_xy(double xi,double yi);
    
    // accessors
    double get_x(void ) const;
    double get_y(void ) const;
    
    double norm() const; // vector norm
    
    /// overloading operators
    friend vector2d operator+(const vector2d& p1,const vector2d& p2);// addition
    friend vector2d operator-(const vector2d& p1,const vector2d& p2);// subtraction
    friend vector2d operator+=(vector2d& p1, const vector2d& p2);//addition & assign
    friend vector2d operator-=(vector2d& p1, const vector2d& p2);// subraction & assign
    friend vector2d operator*(const vector2d& p1, const double& d);// multiplication
    friend double operator*(const vector2d& p1,const vector2d& p2);// dot product
    friend vector2d operator/(const vector2d& p1, const double& d);// division
    friend vector2d operator*=(vector2d& p1, const double& d);// multiplication & assign
    friend vector2d operator/=(vector2d& p1, const double& d);// division & assign
    friend vector2d operator*(const double& d, const vector2d& p);// multiplication
    
    friend std::ostream& operator<<(std::ostream& strm, const vector2d& p);//output
    friend std::istream& operator>>(std::istream& strm, vector2d& p);//input
private:
    // private member variables
    double x;
    double y;
};

vector2d::vector2d():x(0),y(0){
}

vector2d::vector2d(double xi,double yi):x(xi),y(yi){
}

void vector2d::set_xy(double xi,double yi){
    x = xi;
    y = yi;
}

double vector2d::get_x(void ) const
{
    return x;
}

double vector2d::get_y(void ) const
{
    return y;
}

double vector2d::norm() const
{
    return std::sqrt(x * x + y * y);
}


// Operators
vector2d operator+(const vector2d& p1,const vector2d& p2)
{
    vector2d p0(p1.x + p2.x, p1.y + p2.y);
    return p0;
}

vector2d operator-(const vector2d& p1,const vector2d& p2)
{
    vector2d p0(p1.x - p2.x, p1.y - p2.y);
    return p0;
}

vector2d operator+=(vector2d& p1,const vector2d& p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

vector2d operator-=(vector2d& p1,const vector2d& p2)
{
    p1.x -= p2.x;
    p1.y -= p2.y;
    return p1;
}

vector2d operator*(const vector2d& p1, const double& d)
{
    vector2d p0(p1.x * d,p1.y * d);;
    return p0;
}

double operator*(const vector2d& p1,const vector2d& p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}

vector2d operator/(const vector2d& p1, const double& d)
{
    vector2d p0(p1.x / d, p1.y / d);
    return p0;
}
vector2d operator*=(vector2d& p1, const double& d){
    p1.x *= d;
    p1.y *= d;
    return p1;
}

vector2d operator/=(vector2d& p1, const double& d)
{
    p1.x /= d;
    p1.y /= d;
    return p1;
}

vector2d operator*(const double& d, const vector2d& p)
{
    return p * d;
}

std::ostream& operator<<(std::ostream& strm, const vector2d& p)
{
    strm << "(" << p.x << "," << p.y << ")";
    return strm;
}
std::istream& operator>>(std::istream& strm, vector2d& p)
{
    strm >> p.x >> p.y;
    return strm;
}

int main(int argc, char **argv)
{
    vector2d a(1,2);
    vector2d b(3,4);
    
    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;
    
    vector2d c;
    c = a + b;
    std::cout <<"a+b=" << c << std::endl;
    
    c = a - b;
    std::cout <<"a-b=" << c << std::endl;
    
    double d = a * b;
    std::cout <<"a.b=" << d << std::endl;
    
    std::cout <<"a * 2=" << a * 2 << std::endl;
    std::cout <<"2 * a=" << 2 * a << std::endl;
    std::cout <<"a / 2=" << a / 2 << std::endl;
    std::cout <<"|b|=" << b.norm() << std::endl;
    
    return 0;
}
