//
//  ProjectileWithDrag.cpp
//  homework11
//
//  Created by Diego Gomez on 4/20/18.
//  Copyright © 2018 Diego Gomez. All rights reserved.
//

#include "ProjectileWithDrag.hpp"

ProjectileWithDrag::ProjectileWithDrag():Projectile(1.0,0,0){
    
}

ProjectileWithDrag::ProjectileWithDrag(double weight,vector2d initial_velocity):Projectile(weight,initial_velocity){
    
}

ProjectileWithDrag::ProjectileWithDrag(double weight,double initial_speed,double angle,double drag_coeff):Projectile(weight,initial_speed,angle),drag_coeff(drag_coeff){
    
}

void ProjectileWithDrag::update(double dt){
    Projectile::update(dt);
    acceleration.set_xy(-drag_coeff*velocity.norm()*velocity.get_x()/weight,g-drag_coeff*velocity.norm()*velocity.get_y()/weight);
}
