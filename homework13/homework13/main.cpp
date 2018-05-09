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

class ProjectileFormatMistake:public std::exception{
public:
    ProjectileFormatMistake(std::string response):response(response){}
    virtual const char *what() const throw(){
        return response.c_str();
    }
private:
    std::string response;
};

bool simulation(Projectile trajectory,const double &target_dist){
    while(1){
        trajectory.update(dt);
        vector2d cord = trajectory.get_coordinate();
        if (cord.get_y() <= 0.0){
            if(fabs(cord.get_x() - target_dist) < 1){
                std::cout << "Target Destroyed" <<  std::endl;
                return true;
            }
            else {
                std::cout << "Miss" << std::endl;
                std::cout << "Target distance is: " << target_dist << "m" << std::endl;
                std::cout << "Projectile distance is: " << cord.get_x() << "m" << std::endl;
                std::cout << "and missed by " << fabs(cord.get_x()-target_dist) << "m"
                << std::endl;
                return false;
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
        double init_speed = 0;
        double init_angle = 0;
        double target_dist = 0;
        std::cout << "\nEnter the target distance: ";
        std::cin >> target_dist;
        while(1){
            std::cout << "\nEnter an initial speed in m/s: ";
            std::cin >> init_speed;
            std::cout << "\nEnter an initial angle in radians: ";
            std::cin >> init_angle;
            try {
                if (!std::cin){
                    std::cin.clear();
                    throw ProjectileFormatMistake("Wrong data!\n");
                }
                if (init_speed < 50 || init_speed > 100 ){
                    throw ProjectileFormatMistake("Initial speed out of bounds!\n");
                }
                if (init_angle <= 0 || init_angle >= M_PI_2){
                    throw ProjectileFormatMistake("Initial angle out of bounds!\n");
                }
                if (target_dist <= 0){
                    throw ProjectileFormatMistake("Target distance less than 0!\n");
                }
                ProjectileWithDrag trajectory(weight,init_speed,init_angle,D);
                if (simulation(trajectory, target_dist)) goto label1;
                else{
                    if (YesOrNo("Try again at this distance? (Y/N)")){
                        goto end;
                    }
                }
            }
            catch (std::exception &e) {
                std::cout << e.what() << std::endl;
                std::cout << "Enter correct inputs\n";
                continue;
            }
        }
    label1:if (YesOrNo("A new target? (Y/N)")) {
            break;
        }
    }
end:std::cout << "End of program \n";
    return 0;
}
