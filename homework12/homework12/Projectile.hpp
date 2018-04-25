//
//  Projectile.hpp
//  homework11
//
//  Created by Diego Gomez on 4/19/18.
//  Copyright © 2018 Diego Gomez. All rights reserved.
//

#ifndef Projectile_hpp
#define Projectile_hpp

#include <stdio.h>
#include "vector2d.hpp"

using namespace cosc6000;

const double g=-9.81;

class Projectile{
public:
    //CONSTRUCTORS
    Projectile();
    Projectile(double weight,vector2d initial_velocity);
    Projectile(double weight,double initial_speed,double angle);
    
    //DESTRUCTOR
    ~Projectile();

    //FUNCTIONS
    virtual void update(double dt);
    
    //GETTERS
    vector2d get_acceleration() const;
    vector2d get_velocity() const;
    vector2d get_coordinate() const;
    double get_time() const;
    
    //OVERLOAD STREAM
    friend std::ostream& operator << (std::ostream& strm,const Projectile& p1);
    
protected:
    vector2d acceleration,velocity,cord;
    double time,weight;
};

#endif /* Projectile_hpp */
