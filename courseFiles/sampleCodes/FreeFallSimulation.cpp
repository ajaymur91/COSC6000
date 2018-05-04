//
//  main.cpp
//  fall
//
//  Created by Hideki Fujioka on 4/11/18.
//  Copyright © 2018 Hideki Fujioka. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>

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

void simulation(FreeFall *obj,std::ostream & strm,double dt){
    while(1){
        strm << *obj << std::endl;
        obj->update(dt);
        if (obj->getY() < 0.0)break;
    }
}
int main(int argc, const char * argv[]) {
    FreeFall *object1 = new FreeFall(0.0,100);
    FreeFall *object2 = new FreeFallWithDrag(0.0,100,1.0,1.0);
    FreeFall *object3 = new Lander(0.0,100,1.0,1.0);
    std::vector<FreeFall *> objs;
    objs.push_back(object1);
    objs.push_back(object2);
    objs.push_back(object3);
    const double dt = 0.01;
    for (int i = 0 ; i < objs.size() ; i++){
        std::stringstream fileName;
        fileName << "result" << i + 1 << ".txt";
        std::ofstream fout;
        fout.open(fileName.str());
        simulation(objs[i],fout,dt);
        fout.close();
    }
    /*
    std::ofstream fout;
    fout.open("result1.txt");
    simulation(object1,fout,dt);
    fout.close();
    fout.open("result2.txt");
    simulation(object2,fout,dt);
    fout.close();
    fout.open("result3.txt");
    simulation(object3,fout,dt);
    fout.close();
     */
    delete object1;
    delete object2;
    delete object3;

    return 0;
}
