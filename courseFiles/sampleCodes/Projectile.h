//
//  Projectile.h
//  ProjectileNoDrag
//
//  Created by Hideki Fujioka on 4/13/18.
//  Copyright (c) 2018 Tulane University. All rights reserved.
//

#ifndef Projectile_h
#define Projectile_h

#include "vector2d.h"
using namespace cosc3000;

const double gravity = -9.8; ///< gravitational acceleration m/s^2

class Projectile{
public:
    /// default constructor set weight = 1, initial velocity to 0
    Projectile();
    
    /// constructor, weight and initial velocity
    Projectile(double weight, vector2d initial_velocity);
    
    /// constructor, weight, initial speed and angle
    Projectile(double weight, double initial_speed, double angle);
    
    /// destructor don't do anything
    ~Projectile();
    
    /// update velocity and coordinate with a small time-step, dt
    void update(double dt);
    
    /// get acceleration;
    vector2d get_acceleration() const;
    
    /// get velocity;
    vector2d get_velocity() const;
    
    /// get_coordinate
    vector2d get_coordinate() const;
    
    /// get_time
    double get_time() const;
    
    /// Output to ostream
    friend std::ostream& operator<<(std::ostream& strm, const Projectile& p);

protected:
    vector2d acceleration;///<acceleration (m/s^2)
    vector2d velocity;///< velocity  (m/s)
    vector2d cord;///< position coordinate (m)
    
    double weight;/// Object Weight (kg)
    
    double time;///< Current Time (sec)
};
#endif // Projectile_h
