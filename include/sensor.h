#pragma once

#include <iostream>
#include <memory>
#include <thread>
#include <utility>
#include <vector>
#include <array>

/**
 * @brief Namespace for the maze navigation project
 *
 */
namespace RWA2 {
/**
 * @brief Class for the sensor
 *
 */
class Sensor {
 private:
  // ==================== attributes ====================
  std::string model_;
  std::array<double,50> data_{0.0};

 public:
  // ==================== constructors ====================
  Sensor(std::string sensor_name) : model_{sensor_name} {}

  // ==================== methods ====================
 
  /**
   * @brief Start reading the sensor data
   *
   * @param period Period of the reading (in s)
   */
  void read_data(unsigned int duration);
  /**
   * @brief Stop reading the sensor data
   *
   */
  void stop_reading();
  
};  // class Sensor
}  // namespace RWA2
