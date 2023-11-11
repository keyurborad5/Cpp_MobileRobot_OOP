#pragma once

#include <iostream>
#include <utility>
#include "mobile_robot.h"
/**
 * @brief  Namespace RWA2
 * 
 */
namespace RWA2 {
    /**
     * @brief Defineing class as Aerial Robot and public inheritence of Mobile RObot class
     * 
     */
    class AerialRobot final : public MobileRobot {

        public:

        // ==================== constructors ====================
        AerialRobot(double x, double y, double orientation,std::string aerial_robot_model,std::string battery_model, 
                bool has_wings,double altitude=0.0, bool is_flying=false )
                :MobileRobot(x , y, orientation,aerial_robot_model, battery_model),
                 has_wings_{has_wings}, altitude_{altitude}, is_flying_{is_flying}{
                    if(model_=="Erle-Plane"){
                        has_wings_=true;
                    }
                    else{ has_wings_=false;}
                    /*empty body*/
                }
        // ==================== methods ====================
        /**
         * @brief move method to move the robot
         * 
         * @param distance distance parameter to pass amount of distance to move in meters
         * @param angle angle of movemment while moving
         */
        virtual void move(double distance, double angle) override;
        /**
         * @brief it prints all attributes of parent class MobileRobot as well as of AerialRobot
         * 
         */
        virtual void print_status() override;
        
        protected:
        /**
         * @brief method to rotate the robot
         * 
         * @param angle angle paramter passes the angle of orientation in double
         */
        virtual void rotate(double angle) override;


        private:
        // ==================== attributes ====================
        /**
         * @brief true if the robot has wings, false otherwise. Only the model Erle-
                    Plane has wings.
         * 
         */
        bool has_wings_;
        /**
         * @brief Current altitude of the robot in meter. Objects created from AerialRobot
                are initialized with altitude_ of 0.0.
         * 
         */
        double altitude_;
        /**
         * @brief true if the robot is ﬂying, otherwise false. AerialRobot objects are
            initialized with is_flying_ set to false.
         * 
         */
        bool is_flying_;


        // ==================== methods ====================
        /**
         * @brief The robot takes oﬀ to reach the altitude
         * 
         * @param altitude altitude takes double as an argument for take off
         */
        void take_off(double altitude);
        /**
         * @brief lAction of landing the Aerial robot
         * 
         */
        void land();


    };//class Aerial Robot
}// namespace RWA2