#include "battery.h"

#include <chrono>
#include <thread>
//==============================================================
//For method implementation of start_charging
void RWA2::Battery::start_charging() {
  std::cout << "Battery started charging" << '\n';
  is_charging_ = true;
  if (model_=="Li-ion"){
    std::cout << "Battery Li-ion is charging" << '\n';
    std::chrono::seconds duration((100-current_charge_)/2);
    std::this_thread::sleep_for(duration);
    
    }
  else if (model_=="LiFePO4"){
    std::cout << "Battery LiFePO4 is charging" << '\n';
    std::chrono::seconds duration((100-current_charge_)/4);
    std::this_thread::sleep_for(duration);
    
    }
  stop_charging();
  current_charge_ = 100;
}

//=============================================================
//for method Implementation of stop_charging
void RWA2::Battery::stop_charging() {
  is_charging_ = false;
  std::cout<< "Battery "<<model_<<" is fully charged"<<'\n';
}

//=============================================================
//for method implementation of discharge
void RWA2::Battery::discharge(double amount) {
  current_charge_ -= amount;
  //std::cout << "Current charge: " << current_charge_ <<"%"<< '\n';
}