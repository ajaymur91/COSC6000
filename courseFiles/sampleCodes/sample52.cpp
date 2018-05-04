//
//  Sample52.cpp
//  Projectile without Drag Force
//
//  Created by Hideki Fujioka on 4/18/13.
//  Copyright (c) 2013 Tulane University. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "Projectile.h"

using namespace cosc3000;

int main(int argc, const char * argv[])
{
    // initial conditions
    const double init_speed=10.0;
    const double init_angle=M_PI_4; // PI/4
    const double weight1 = 1.0;
    // Creat an object
    Projectile *trajectory = new Projectile(weight1,init_speed,init_angle);
    vector2d initial_velocity = trajectory->get_velocity();
    
    std::ofstream file;
    file.open("ProjectileNoDrag.dat");
    while(1){
        /// data out
        file << *trajectory << std::endl;
        std::cout << *trajectory << std::endl;
        
        /// increment time
        trajectory->update();
        
        /// check if it hit ground
        vector2d cord = trajectory->get_coordinate();
        if (cord.get_y() < 0.0) break;
    }
    file.close();
    double final_time = trajectory->get_time();
    
    /// delete object
    delete trajectory;
    
    /// compute analytical solution
    vector2d grav(0.0,-9.8);
    file.open("ProjectileNoDragSol.dat");
    for (int i = 0 ; i < 100 ; i++){
        double time = final_time * i / 100.0;
        vector2d cord = 0.5 * grav * time * time + initial_velocity * time;
        file << time << " ";
        file << cord.get_x() << " ";
        file << cord.get_y() << std::endl;
    }
    file.close();
    return 0;
}

