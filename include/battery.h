#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

/**
 * @brief Namespace for the maze navigation project
 *
 */
namespace RWA2 {
/**
 * @brief Class for the battery
 *
 */
  class Battery final{
    private:
      // ==================== attributes ====================
      /**
       * @brief type of the battery
       * 
       */
      std::string model_;
      /**
       * @brief current remaining charge
       * 
       */
      int current_charge_;
      /**
       * @brief bool if battery is charging or not
       * 
       */
      bool is_charging_;
      // ==================== methods ====================
      /**
       * @brief to stop charging the battery
       * 
       */
      void stop_charging();

    public:
      // ==================== constructors ====================
      Battery(std::string model , int current_charge, bool is_charging)
          : model_{model},
            current_charge_{current_charge},
            is_charging_{is_charging} {}

      // ==================== accessors ====================
      /**
       * @brief Get the capacity of the battery
       *
       * @return double current charge remaining
       */
      double get_current_charge() const { return current_charge_; }

      // ==================== methods ====================
      /**
       * @brief Start charging the battery
       *
       */
      void start_charging();
      /**
       * @brief Discharge the battery
       *
       *@param amount battery discharges by the amount supplied
       */
      void discharge(double amount);

  };  // class Battery
}  // namespace RWA2
