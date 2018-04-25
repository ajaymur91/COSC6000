#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "Projectile.hpp"
#include "ProjectileWithDrag.hpp"
using namespace cosc6000;

int main(){
    const double init_speed = 10.0;
    const double init_angle = M_PI_4;
    const double weight1=20;
    const double D [5] = {0,0.5,1,5,10};
    const double dt = 0.01;
    
    
    ProjectileWithDrag trajectory0(weight1,init_speed,init_angle,D[0]);
    ProjectileWithDrag trajectory1(weight1,init_speed,init_angle,D[1]);
    ProjectileWithDrag trajectory2(weight1,init_speed,init_angle,D[2]);
    ProjectileWithDrag trajectory3(weight1,init_speed,init_angle,D[3]);
    ProjectileWithDrag trajectory4(weight1,init_speed,init_angle,D[4]);
    
    std::ofstream file0,file1,file2,file3,file4;
    file0.open("/Users/dgomez/Desktop/COSC6000/homework11/ProjectileData/Projectile0Drag.dat");
    file1.open("/Users/dgomez/Desktop/COSC6000/homework11/ProjectileData/Projectile1Drag.dat");
    file2.open("/Users/dgomez/Desktop/COSC6000/homework11/ProjectileData/Projectile2Drag.dat");
    file3.open("/Users/dgomez/Desktop/COSC6000/homework11/ProjectileData/Projectile3Drag.dat");
    file4.open("/Users/dgomez/Desktop/COSC6000/homework11/ProjectileData/Projectile4Drag.dat");
    while(1){
        file0 << trajectory0 << std::endl;
        
        trajectory0.update(dt);
        
        vector2d cord = trajectory0.get_coordinate();
        if (cord.get_y() <= 0.0){
            break;
        }
    }
    file0.close();
    while(1){
        file1 << trajectory1 << std::endl;
        
        trajectory1.update(dt);
        
        vector2d cord = trajectory1.get_coordinate();
        if (cord.get_y() <= 0.0){
            break;
        }
    }
    file1.close();
    while(1){
        file2 << trajectory2 << std::endl;
        
        trajectory2.update(dt);
        
        vector2d cord = trajectory2.get_coordinate();
        if (cord.get_y() <= 0.0){
            break;
        }
    }
    file2.close();
    while(1){
        file2 << trajectory2 << std::endl;
        
        trajectory2.update(dt);
        
        vector2d cord = trajectory2.get_coordinate();
        if (cord.get_y() <= 0.0){
            break;
        }
    }
    file2.close();
    while(1){
        file3 << trajectory3 << std::endl;
        
        trajectory3.update(dt);
        
        vector2d cord = trajectory3.get_coordinate();
        if (cord.get_y() <= 0.0){
            break;
        }
    }
    file3.close();
    while(1){
        file4 << trajectory4 << std::endl;
        
        trajectory4.update(dt);
        
        vector2d cord = trajectory4.get_coordinate();
        if (cord.get_y() <= 0.0){
            break;
        }
    }
    file4.close();
}



