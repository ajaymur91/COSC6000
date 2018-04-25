#ifndef vector2d_hpp
#define vector2d_hpp
#include <stdio.h>
#include <iostream>
#include <cmath>

namespace cosc6000 {
    class vector2d{
    public:
        //CONSTRUCTOR
        vector2d();
        vector2d(double x,double y);
        
        //SETTERS
        void set_xy(double ix,double iy);
        
        //GETTERS
        double get_x(void) const;
        double get_y(void) const;
        
        //FUNCTIONS
        double norm() const;
        double dot(const vector2d& p2);
        
        //OVERLOAD OPERATORS
        friend vector2d operator + (const vector2d& p1,const vector2d& p2);
        friend vector2d operator - (const vector2d& p1,const vector2d& p2);
        friend vector2d operator += (vector2d& p1,const vector2d& p2);
        friend vector2d operator -= (vector2d& p1,const vector2d& p2);
        friend vector2d operator * (const vector2d& p1,const double& d);
        friend vector2d operator * (const double& d,const vector2d& p1);
        friend vector2d operator / (const vector2d& p1,const double& d);
        friend vector2d operator *= (vector2d& p1,const double& d);
        friend vector2d operator /= (vector2d& p1,const double& d);
        
        //OVERLOAD STREAMS
        friend std::ostream& operator << (std::ostream& strm,const vector2d& p);
        friend std::istream& operator >> (std::istream& strm, vector2d& p);
        
    private:
        double x,y;
        
    };
}

#endif /* vector2d_hpp */
