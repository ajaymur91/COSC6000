//
//  ProjectileWithDrag.hpp
//  homework11
//
//  Created by Diego Gomez on 4/20/18.
//  Copyright © 2018 Diego Gomez. All rights reserved.
//

#ifndef ProjectileWithDrag_hpp
#define ProjectileWithDrag_hpp

#include <stdio.h>
#include "Projectile.hpp"

class ProjectileWithDrag:public Projectile{
    //CONSTRUCTORS
public:
    ProjectileWithDrag();
    ProjectileWithDrag(double weight,vector2d initial_velocity);
    ProjectileWithDrag(double weight,double initial_speed,double angle,double drag_coeff);
    virtual void update(double dt);
private:
    double drag_coeff;
};

#endif /* ProjectileWithDrag_hpp */
