#include "mobile_robot.h"

#include <chrono>
#include <iostream>
#include <thread>


//==============================================================================
//For method implementation of charge_battery
void RWA2::MobileRobot::charge_battery() {
  battery_.start_charging();
}
//==============================================================================
// For Method implementation of rotate
void RWA2::MobileRobot::rotate(double angle) {
  orientation_ +=angle; 
  std::cout << "Rotating " << angle << " degrees" << '\n';
}
//==============================================================================
// for method implementation of move ;although this is overriden 
void RWA2::MobileRobot::move(double distance, double rotate) {
  // empty function
  //  this function is overridden by other move implementation of derived classes
  
}
//==============================================================================
// for method implementation of add_sensor
void RWA2::MobileRobot::add_sensor(std::unique_ptr<RWA2::Sensor> sensors) {
                sensors_.push_back(std::move(sensors));
                std::cout<<"added sensor"<<'\n';
}


//==============================================================================
// for method implementaion of Print_status
void RWA2::MobileRobot::print_status() {
  std::cout << "================\n";
  std::cout
      << "Position: (" << position_.first << ", "
      << position_.second << "), Orientation: " << orientation_
      << ", Speed: " << speed_ << "\n";
}