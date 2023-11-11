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

    //HERE ARE DIFFERENT WAYS TO EXECUTE THE OOPS PROGRAM.
    //RECOMMENDED EXECUTE ONE BLOCK AT A TIME

    // ***************************** Creating objects from class using unique pointer ***********************************

    // Making a unique pointer (aerial_robot) of class (RWA@::AerialRobot) with the given prameters
    auto aerial_robot = std::make_unique<RWA2::AerialRobot>(1, 2, 0, "Li-ion", false,1.0,false);
    // unique pointer(aerial_robot) dereferencing to execute method (move)
    aerial_robot->move(14,90);
    // Making a unique pointer (sensor_) of class (RWA2::Sensor) with the given prameters
    auto sensors_= std::make_unique<RWA2::Sensor>("2D Lidar");
    // unique pointer(sensor_) dereferencing to execute method (read_data)
    sensors_->read_data(5);

    // ***************************** Creating objects from class using unique pointer ***********************************
    // Making a unique pointer (drone) of class (RWA@::AerialRobot) with the given prameters
    auto drone =std::make_unique<RWA2::AerialRobot>(0,0,90,"Erle-Plane","LiFePO4",0,0.0,0);
    // Making a vector of unique pointer (sensors) of class (RWA2::Sensor) with the given prameters
    // unique pointer(drone) dereferencing to execute method (add_sensor) which eventually push back every newly added sensors
    drone->add_sensor(std::make_unique<RWA2::Sensor>("3D Lidar"));
    drone->add_sensor(std::make_unique<RWA2::Sensor>("4D Lidar"));
    drone->add_sensor(std::make_unique<RWA2::Sensor>("5D Lidar"));
    // unique pointer(drone) dereferencing to execute method (move)
    drone->move(10,180);
    std::cout<<"##############################################"<<'\n';

    // ***************************************** Creating objects from class **********************************************

    // these class objects are stored on the Stack unlike objects made using unique pointers which are made on heap memory

    //instantiating RWA2::AquaticRobot class with object name (submarine) and given parametes
    RWA2::AquaticRobot submarine(10,10,90,"HoloOcean","LiFePO4",1);
    //Now calling functions/methods in a class is simple here. just (object_name.method_name)
    //here calling add_sensor and move methods
    submarine.add_sensor(std::make_unique<RWA2::Sensor>("4D Lidar"));
    submarine.move(70,180);
    //We can all call print_status method, however,the reason I have commented it here is because I have mentioned it in move method as well. 
    //submarine.print_status();
    std::cout<<"##############################################"<<'\n';

    //instantiating RWA2::WheeledRobot class with object name (AMR) and given parametes
    RWA2::WheeledRobot AMR(20,20,90,"AMMRR","Li-ion",180,10,6);
    AMR.add_sensor(std::make_unique<RWA2::Sensor>("4D Lidar"));
    AMR.move(40,180);
    AMR.print_status();
    std::cout<<"##############################################"<<'\n';

    //instantiating RWA2::LeggedRobot class with object name (humanoid) and given parametes
    RWA2::LeggedRobot humanoid(30,30,90,"HUMOOO","Li-ion",11,1);
    humanoid.add_sensor(std::make_unique<RWA2::Sensor>("5D Lidar"));
    humanoid.move(50,180);
    humanoid.print_status();
    std::cout<<"##############################################"<<'\n';
  aerial_robot->add_sensor(std::make_unique<RWA2::Sensor>("2D lidar"));

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
