#include "sensor.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <random>
#include <array>



//==============================================================================
void RWA2::Sensor::read_data(unsigned int duration) {

    std::cout << "Sensor " << model_ << " gathering data for " << duration << "seconds"<< '\n';
    std::this_thread::sleep_for(std::chrono::seconds(duration));
    //generate random double between 1 and 30
    std::random_device rd;  // Random device engine, usually based on
                            // /dev/urandom on UNIX-like OSes
    std::mt19937 gen(rd());  // Initializes with the random device
    std::uniform_real_distribution<> dis(1.0, 30.0);
    for (int i=0 ;i<50; i++){ 
        data_[i]= dis(gen);
    }
    //std::cout << "Sensor " << sensor_name_ << " read data: " << sensor_data_ << '\n';
    stop_reading();
}

//==============================================================================
void RWA2::Sensor::stop_reading() {
    std::cout << "Stopping reading data" << '\n';
}

//==============================================================================