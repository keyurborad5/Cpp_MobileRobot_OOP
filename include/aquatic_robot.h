#pragma once

#include <iostream>
#include <utility>
#include <mobile_robot.h>
/**
 * @brief  Namespace RWA2
 * 
 */
namespace RWA2{
    /**
     * @brief class AquaticRobot and public inheritence of MobileRobot class
     * 
     */
    class AquaticRobot final : public MobileRobot{
        public:
            // ======================= constructors =========================
            AquaticRobot(double x, double y, double orientation,std::string aquatic_robot_model,std::string battery_model,
                        bool has_fins, double depth=0.0, bool is_diving=false)
                        : MobileRobot(x,y,orientation,aquatic_robot_model,battery_model), 
                        has_fins_{has_fins},depth_{depth},is_diving_{is_diving}{
                            if(model_=="SoFi"){
                                number_of_fins_=1;

                            }
                        }
            // ======================== methods ================================
            /**
             * @brief move method to move the robot
             * 
             * @param distance distance parameter to pass amount of distance to move in meters
             * @param angle angle of movemment while moving
             */
            virtual void move(double distance, double angle) override;
            /**
             * @brief prints all attributes of parent class MobileRobot as well as of AerialRobot
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
            //=======================Attributes======================
            /**
             * @brief true if the robot has ﬁns, otherwise false. The robot SoFi is the
                only one with ﬁns
             * 
             */
            bool has_fins_;
            /**
             * @brief Current depth of the robot in meter. Objects created from AquaticRobot
                are initialized with a depth_ of 0.0.
             * 
             */
            double depth_;
            /**
             * @brief true if the robot is diving, otherwise false. AquaticRobot objects
                are initialized with is_diving_ set to false.
             * 
             */
            bool is_diving_=false;
            /**
             * @brief  number of fins of the given Aquatic Robot
             * 
             */
            int number_of_fins_;

            //======================= methods ======================
            /**
             * @brief Action of moving the robot to the surface.
             * 
             */
            void surface();
            /**
             * @brief The robot dives to reach depth.This method can be called only if the robot is not already diving.
             * 
             * @param depth depth of the dive
             */
            void dive(double depth);


    }; //class AquaticRobot
}// namespace RWA2