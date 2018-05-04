//
//  Sample53.cpp
//  ProjectileLinearDrag
//
//  Created by Hideki Fujioka on 4/18/13.
//  Copyright (c) 2013 Tulane University. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "ProjectileLinearDrag.h"

using namespace cosc3000;

int main(int argc, const char * argv[])
{
    // initial conditions
    const double init_speed=10.0;
    const double init_angle=M_PI_4; // PI/4
    const double weight1 = 1.0;
    const double drag1 = 0.5;
    // Creat an object
    double angle= M_PI * (rand() % 180) / 180.0;
    vector2d w(-5.0,0.0);
    Wind2d *wind = new Wind2d(w);
    Projectile *trajectory = new ProjectileLinearDrag(weight1,init_speed,init_angle,drag1,wind);

    std::ofstream file;
    file.open("ProjectileLinearDrag.dat");
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
    
    delete trajectory;
    return 0;
}
