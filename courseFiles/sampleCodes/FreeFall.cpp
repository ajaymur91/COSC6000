//
//  main.cpp
//  fall
//
//  Created by Hideki Fujioka on 4/11/18.
//  Copyright © 2018 Hideki Fujioka. All rights reserved.
//

#include <iostream>
#include <iomanip>
const double g = -9.8;

class FreeFall{
public:
    FreeFall():y(0.0),v(0.0),a(g),t(0.0){}
    FreeFall(double initv,double inity)
    :y(inity),v(initv),a(g),t(0.0){}
    void update(double dt){
        y += v * dt;
        v += a * dt;
        t += dt;
        compute_acceleration();
    }
    virtual void compute_acceleration(){
        /// do nothing
    }
    friend std::ostream & operator << (std::ostream & strm,const FreeFall & obj){
        strm << obj.t << std::setw(16)
        << obj.y << std::setw(16)
        << obj.v << std::setw(16)
        << obj.a;
        return strm;
    }
    double getY() const{
        return y;
    }
    double getV() const{
        return v;
    }
    double getA() const{
        return a;
    }
    double getT() const{
        return t;
    }
    void setY(double iy){
        y = iy;
    }
    void setV(double iv){
       v = iv;
    }
    void setA(double ia){
        a = ia;
    }
    void setT(double it){
        t = it;
    }
private:
    double y;
    double v;
    double a;
    double t;
};

class FreeFallWithDrag:public FreeFall{
public:
    FreeFallWithDrag(){}
    FreeFallWithDrag(double initv,double inity,double weight,double drag_coeff)
    :FreeFall(initv,inity),weight(weight),drag_coeff(drag_coeff){}

    virtual void compute_acceleration(){
        setA(g - drag_coeff * getV() / weight);
    }
    double getWeight() const{
        return weight;
    }
    void setWeight(double w) {
        weight = w;
    }
    double getDragCoeff() const{
        return drag_coeff;
    }
    void setDragCoeff(double d) {
        drag_coeff = d;
    }
private:
    double weight;
    double drag_coeff;
};

class Lander:public FreeFallWithDrag{
public:
    Lander():FreeFallWithDrag(){}
    Lander(double initv,double inity,double weight,double drag_coeff):FreeFallWithDrag( initv, inity, weight, drag_coeff){}

    virtual void compute_acceleration(){
        const double threashhold = -1.0;
        const double retrogradeForce = 10.0;
        FreeFallWithDrag::compute_acceleration();

        if (getV() < threashhold){
            setA(getA() + retrogradeForce/ getWeight());
        }
    }
};

int main(int argc, const char * argv[]) {
    Lander object(0.0,100,1.0,1.0);
    const double dt = 0.01;
    while(1){
        std::cout << object << std::endl;
        object.update(dt);
        if (object.getY() < 0.0)break;
    }
    return 0;
}

