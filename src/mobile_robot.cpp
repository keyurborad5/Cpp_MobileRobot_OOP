#include "mobile_robot.h"

#include <chrono>
#include <iostream>
#include <thread>


//==============================================================================
void RWA2::MobileRobot::charge_battery() {
  battery_.start_charging();
}
//==============================================================================

void RWA2::MobileRobot::rotate(double angle) {
  orientation_ +=angle; 
  std::cout << "Rotating " << angle << " degrees" << '\n';
}
//==============================================================================

void RWA2::MobileRobot::move(double distance, double rotate) {
  // each meter consumes 1% of the battery
  // check if the battery has enough charge to move the robot forward by the
  // given distance
  if (battery_.get_current_charge() < distance) {
    std::cout << "Battery level is too low to move forward by " << distance
              << " m\n";
    charge_battery();
  }
  
  std::cout << "Moving forward " << distance << " m\n";
  std::cout << "Rotating " << rotate << " degrees" << '\n';
  std::chrono::seconds duration(static_cast<int>(distance));
  std::this_thread::sleep_for(duration);
  std::cout << "Robot moved forward " << distance << " m\n";
  battery_.discharge(distance);
}
//==============================================================================

void RWA2::MobileRobot::add_sensor(std::unique_ptr<RWA2::Sensor> sensors) {
                sensors_.push_back(std::move(sensors));
                std::cout<<"added sensor"<<'\n';
}


//==============================================================================

// void RWA2::MobileRobot::get_sensor_reading(int duration) {
//      sensors_.read_data(duration);

//  }
void RWA2::MobileRobot::print_status() {
  std::cout << "================\n";
  std::cout
      << "Position: (" << position_.first << ", "
      << position_.second << "), Orientation: " << orientation_
      << ", Speed: " << speed_ << "\n";
}