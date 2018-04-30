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
    ~ProjectileWithDrag();
    void update(double dt);
private:
    double drag_coeff;
};

#endif /* ProjectileWithDrag_hpp */
