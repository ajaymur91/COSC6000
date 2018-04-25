//
//
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <sstream>
#include "Projectile.hpp"
#include "ProjectileWithDrag.hpp"

using namespace cosc6000;

void simulation(Projectile *obj, std::ostream &strm,double dt){
    while(1){
        /// data out
        strm << *obj << std::endl;
        
        /// increment time
        obj->update(dt);
        
        /// check if it hit ground
        vector2d cord = obj->get_coordinate();
        if (cord.get_y() < 0.0) break;
    }
}

int main(int argc, const char * argv[]) {
    // initial conditions
    const double init_speed=10.0;
    const double init_angle=M_PI_4; // PI/4
    const double weight1 = 1.0;
    const double dt = 0.01;
    
    // Create objects
    std::vector<Projectile *> objects;
    objects.push_back(new Projectile(weight1,init_speed,init_angle));
    objects.push_back(new ProjectileWithDrag(weight1,init_speed,init_angle,0.1));
    
    /// compute numerical solution
    std::ofstream file;
    for (int i = 0 ; i < objects.size() ; i++){
        std::stringstream fileName;
        fileName << "/Users/dgomez/Desktop/COSC6000/homework12/ProjectileData/Trajectory" << std::setfill('0') << std::setw(2) << i << ".txt";
        file.open(fileName.str());
        simulation(objects[i],file,dt);
        file.close();
    }
    
    return 0;
}
