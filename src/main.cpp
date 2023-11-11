#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "mobile_robot.h"
#include"aerial_robot.h"
#include"aquatic_robot.h"
#include"wheeled_robot.h"
#include"legged_robot.h"

//This funtion is only executed with polymorphism
//executes method (move) for all the unique pointer objects added in the vector (mobile_robots)
void move_robot(const std::vector<std::unique_ptr<RWA2::MobileRobot>>& robots){
    //this for loop iterates through all the elements of the vector(robots)
    for(const auto& robot: robots)
      robot->move(60,180);

}

int main() {

// ********************** Ploymorphism with Unique pointer *********************************************
  
  //Creating a vector (mobile_robots) of a unique pointers of type (RWA2::MobileRobot)
  std::vector<std::unique_ptr<RWA2::MobileRobot>> mobile_robots;
  
  //Creating a [unique pointer and an object]->(aerial_ptr) of type (RWA2::MobileRobot) 
  std::unique_ptr<RWA2::MobileRobot> aerial_ptr =std::make_unique<RWA2::AerialRobot>(0,0,90,"Erle-Plane","LiFePO4",0,0.0,0);
  //Adding 2 sensors to the object(aerial_ptr) by dereferncing it and calling method (add_sensor)
  aerial_ptr->add_sensor(std::make_unique<RWA2::Sensor>("3D Lidar"));
  aerial_ptr->add_sensor(std::make_unique<RWA2::Sensor>("IMU "));

  std::unique_ptr<RWA2::MobileRobot> aquatic_ptr =std::make_unique<RWA2::AquaticRobot>(10,10,90,"HoloOcean","LiFePO4",1);
  aquatic_ptr->add_sensor(std::make_unique<RWA2::Sensor>("2D camera"));
  aquatic_ptr->add_sensor(std::make_unique<RWA2::Sensor>("IMU "));

  std::unique_ptr<RWA2::MobileRobot> wheeled_ptr =std::make_unique<RWA2::WheeledRobot>(20,20,90,"AMMRR","Li-ion",180,10,6);
  wheeled_ptr->add_sensor(std::make_unique<RWA2::Sensor>("3D Lidar"));
  wheeled_ptr->add_sensor(std::make_unique<RWA2::Sensor>("IMU"));
  
  std::unique_ptr<RWA2::MobileRobot> legged_ptr =std::make_unique<RWA2::LeggedRobot>(30,30,90,"HUMOOO","Li-ion",11,1);
  legged_ptr->add_sensor(std::make_unique<RWA2::Sensor>("3D Lidar"));
  legged_ptr->add_sensor(std::make_unique<RWA2::Sensor>("IMU"));

  //adding all above unique pointer in the vector of unique pointer (mobile_robots)
  mobile_robots.push_back(std::move(aerial_ptr));
  mobile_robots.push_back(std::move(aquatic_ptr));
  mobile_robots.push_back(std::move(legged_ptr));
  mobile_robots.push_back(std::move(wheeled_ptr));

  //executing function (move_robot)
  move_robot(mobile_robots);


}
