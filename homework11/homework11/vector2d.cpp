#include "vector2d.hpp"
#include <iomanip>

namespace cosc6000 {
    //CONSTRUCTORS
    vector2d::vector2d():x(0),y(0){
        
    }
    vector2d::vector2d(double ix,double iy):x(ix),y(iy){
        
    }
    
    //SETTER
    void vector2d::set_xy(double ix, double iy){
        x = ix;
        y = iy;
    }
    
    //GETTER
    double vector2d::get_x() const{
        return x;
    }
    
    double vector2d::get_y() const{
        return y;
    }
    
    //FUNCTIONS
    
    double vector2d::norm() const{
        return std::sqrt(x * x + y * y);
    }
    
    double vector2d::dot(const vector2d &p2){
        return x * p2.get_x() + y * p2.get_y();
    }
    
    //OVERLOAD OPERATOR
    
    vector2d operator + (const vector2d& p1,const vector2d& p2){
        vector2d p0(p1.x + p2.x, p1.y + p2.y);
        return p0;
    }
    
    vector2d operator - (const vector2d& p1,const vector2d& p2){
        vector2d p0(p1.x - p2.x, p1.y - p2.y);
        return p0;
    }
    
    vector2d operator += (vector2d& p1, const vector2d& p2){
        p1.x += p2.x;
        p1.y += p2.y;
        return p1;
    }
    
    vector2d operator -= (vector2d& p1, const vector2d& p2){
        p1.x -= p2.x;
        p1.y -= p2.y;
        return p1;
    }
    
    vector2d operator * (const vector2d& p1, const double& d){
        vector2d p0(p1.x * d,p1.y * d);
        return p0;
    }
    
    vector2d operator * (const double& d, const vector2d& p){
        return p * d;
    }
    
    vector2d operator / (const vector2d& p1, const double& d){
        vector2d p0(p1.x / d,p1.x / d);
        return p0;
    }
    
    vector2d operator *= (vector2d& p1,const double& d){
        p1.x *= d;
        p1.y *= d;
        return p1;
    }
    
    vector2d operator /= (vector2d& p1,const double& d){
        p1.x /= d;
        p1.y /= d;
        return p1;
    }
    
    //OVERLOAD STREAM
    std::ostream& operator << (std::ostream& strm,const vector2d& p){
        strm << p.x << std::setw(16) << p.y;
        return strm;
    }
    
    std::istream& operator >> (std::istream& strm,vector2d& p){
        strm >> p.x >> p.y;
        return strm;
    }
    
}

