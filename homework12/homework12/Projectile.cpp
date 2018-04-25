//
//  Projectile.cpp
//  homework11
//
//  Created by Diego Gomez on 4/19/18.
//  Copyright © 2018 Diego Gomez. All rights reserved.
//

#include "Projectile.hpp"
#include <iomanip>
#include <iostream>

//CONSTRUCTORS
Projectile::Projectile():Projectile(1.0,0,0){
    
}

Projectile::Projectile(double weight,vector2d initial_velocity):cord(0,0),time(0),velocity(initial_velocity),acceleration(0.0,g),weight(weight){
    
}

Projectile::Projectile(double weight,double initial_speed,double angle):cord(0,0),velocity(initial_speed*cos(angle),initial_speed*sin(angle)),acceleration(0,g),time(0),weight(weight){
    
}

//DESTRUCTORS
Projectile::~Projectile(){
    
}

//FUNCTIONS
void Projectile::update(double dt){
    cord += velocity * dt;
    velocity += acceleration * dt;
    time += dt;
}

//GETTERS
vector2d Projectile::get_coordinate() const{
    return cord;
}

vector2d Projectile::get_velocity() const{
    return velocity;
}

vector2d Projectile::get_acceleration() const{
    return acceleration;
}

double Projectile::get_time() const{
    return time;
}

//OVERLOAD STREAM
std::ostream& operator << (std::ostream& strm, const Projectile& p){
    strm << std::setprecision(8);
    strm << std::scientific;
    strm << p.time
    << std::setw(16) << p.cord
    << std::setw(16) << p.velocity
    << std::setw(16) << p.acceleration;
    
    return strm;
}
