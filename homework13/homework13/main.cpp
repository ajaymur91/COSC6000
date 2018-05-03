#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
#include "Projectile.hpp"
#include "ProjectileWithDrag.hpp"

const double weight = 20;
const double D = 0.5;
const double dt = 0.01;

bool YesOrNo(std::string message){
    std::cout << message << std::endl;
    std::string ans;
    std::cin >> ans;
    if (ans[0] == 'Y' || ans[0] == 'y') return false;
    return true;
}

bool TargetDestroyed(double x,double target){
    if(fabs(x - target) < 1) return true;
    return false;
}

class ProjectileFormatMistake:public std::exception{
public:
    ProjectileFormatMistake(std::string response):response(response){}
    virtual const char *what() const throw(){
        return response.c_str();
    }
private:
    std::string response;
};

void simulation(Projectile trajectory,double target_dist){
    while(1){
        trajectory.update(dt);
        vector2d cord = trajectory.get_coordinate();
        if (cord.get_y() <= 0.0){
            if (TargetDestroyed(cord.get_x(), target_dist)){
                std::cout << "Target Destroyed" <<  std::endl;
            }
            else {
                std::cout << "Miss" << std::endl;
                std::cout << "Final distance is: " << cord.get_x() << "m" << std::endl;
                std::cout << "A missed by " << fabs(cord.get_x()-target_dist) << "m"
                << std::endl;
            }
            break;
        }
    }
}

int main(){
    std::cout << "Try to hit a target 100m away" << std::endl;
    std::cout << "Your object has a weight of " << weight
    << "kg, "<<" and a drag coefficient of "
    << D << "kg/s" << std::endl;
   
    while(1){
        vector2d cord;
        double init_speed = 0;
        double init_angle = 0;
        double target_dist = 0;
        std::cout << "\nEnter the target distance: ";
        std::cin >> target_dist;
        std::cout << "\nEnter an initial speed in m/s: ";
        std::cin >> init_speed;
        std::cout << "\nEnter an initial angle in radians: ";
        std::cin >> init_angle;
        try {
            if (!std::cin){
                std::cin.clear();
                throw ProjectileFormatMistake("Wrong data!\n");
            }
            if (init_speed <= 50 || init_speed >= 100 ){
                throw ProjectileFormatMistake("Initial speed out of bounds!\n");
            }
            if (init_angle <= 0 || init_angle >= M_PI_2){
                throw ProjectileFormatMistake("Initial angle out of bounds!\n");
            }
            if (target_dist <= 0){
                throw ProjectileFormatMistake("Target distance less than 0!\n");
            }
            ProjectileWithDrag trajectory(weight,init_speed,init_angle,D);
            simulation(trajectory,target_dist);
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
            std::cout << "Enter correct inputs\n";
            continue;
        }
        if (YesOrNo("Again?(y/n)")) {
            break;
        }
    }
    std::cout << "End of program \n";
    return 0;
}
