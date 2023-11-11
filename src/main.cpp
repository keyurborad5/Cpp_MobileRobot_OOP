#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "mobile_robot.h"
#include"aerial_robot.h"
#include"aquatic_robot.h"
#include"wheeled_robot.h"
#include"legged_robot.h"

void move_robot(const std::vector<std::unique_ptr<RWA2::MobileRobot>>& robots){
    for(const auto& robot: robots)
      robot->move(60,180);

}

int main() {
  //auto aerial_robot = std::make_unique<RWA2::AerialRobot>(1, 2, 0, "Li-ion", false,1.0,false);
    //aerial_robot->move(14,90);
    //auto sensors_= std::make_unique<RWA2::Sensor>("2D Lidar");
    //sensors_->read_data(5);
    // auto drone =std::make_unique<RWA2::AerialRobot>(0,0,90,"Erle-Plane","LiFePO4",0,0.0,0);
    // drone->add_sensor(std::make_unique<RWA2::Sensor>("3D Lidar"));
    // drone->add_sensor(std::make_unique<RWA2::Sensor>("4D Lidar"));
    // drone->add_sensor(std::make_unique<RWA2::Sensor>("5D Lidar"));
    // auto sensors_= std::make_unique<RWA2::Sensor>("2D Lidar");
    // sensors_->read_data(5);
    // drone->move(10,180);
    //drone.print_status();
    //std::cout<<"##############################################"<<'\n';

    // RWA2::AquaticRobot submarine(10,10,90,"HoloOcean","LiFePO4",1);
    // submarine.add_sensor(std::make_unique<RWA2::Sensor>("4D Lidar"));
    // submarine.move(70,180);
    ////submarine.print_status();
    // std::cout<<"##############################################"<<'\n';

    //  RWA2::WheeledRobot AMR(20,20,90,"AMMRR","Li-ion",180,10,6);
    //  AMR.add_sensor(std::make_unique<RWA2::Sensor>("4D Lidar"));
    //  AMR.move(40,180);
    // AMR.print_status();
     //std::cout<<"##############################################"<<'\n';

    // RWA2::LeggedRobot humanoid(30,30,90,"HUMOOO","Li-ion",11,1);
    // humanoid.add_sensor(std::make_unique<RWA2::Sensor>("5D Lidar"));
    // humanoid.move(50,180);
    //humanoid.print_status();
    // std::cout<<"##############################################"<<'\n';
  //aerial_robot->add_sensor(std::make_unique<RWA2::Sensor>("2D lidar"));

  
  std::vector<std::unique_ptr<RWA2::MobileRobot>> mobile_robots;
  
  std::unique_ptr<RWA2::MobileRobot> aerial_ptr =std::make_unique<RWA2::AerialRobot>(0,0,90,"Erle-Plane","LiFePO4",0,0.0,0);
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

  mobile_robots.push_back(std::move(aerial_ptr));
  // mobile_robots.push_back(std::move(aquatic_ptr));
  // mobile_robots.push_back(std::move(legged_ptr));
  // mobile_robots.push_back(std::move(wheeled_ptr));

  
  move_robot(mobile_robots);


}
