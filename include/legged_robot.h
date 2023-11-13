#pragma once

#include <iostream>
#include <utility>
#include "mobile_robot.h"
/**
 * @brief Namespace RWA2
 * 
 */
namespace RWA2{
    /**
     * @brief class LeggedRobot with the public inheritance of MobileRobot
     * 
     */
    class LeggedRobot final : public MobileRobot{
        public:
            // ============================Constructor===========================
            LeggedRobot(double x, double y, double orientation,std::string legged_robot_model,std::string battery_model,
                        int leg_strength, int number_of_legs=2)
                        :MobileRobot(x,y,orientation,legged_robot_model,battery_model), 
                        leg_strength_{leg_strength}, number_of_legs_{number_of_legs}{
                            do{
                                if(number_of_legs_%2 != 0 | number_of_legs_>7){

                                    std::cout<< "Please enter the valid number of legs of legged robot, which are 2 or 4 or 6. :";
                                    std::cin>> number_of_legs_;
                                }
                            }while (number_of_legs_%2 != 0 | number_of_legs_>7);
                            do{
                                if (leg_strength_<1|leg_strength_>10){
                                    std::cout<< "Please enter the valid leg strength of legged robot, which is [1-10]. :";
                                    std::cin>> leg_strength_;
                                }
                            } while(leg_strength_<1|leg_strength_>10);
                             
                        }
            // ============================methods===========================
            /**
             * @brief move method to move the robot
             * 
             * @param distance distance parameter to pass amount of distance to move in meters.The maximum value for distance
                    is 10 meters.
             * @param angle angle of movemment while moving
             */
            virtual void move(double distance,double angle) override;
            /**
             * @brief prints all attributes of parent class MobileRobot as well as of LeggedRobot
             * 
             */
            virtual void print_status() override;
        
        protected:
            // ============================ Methods ===========================
            /**
             * @brief method to rotate the robot
             * 
             * @param angle angle paramter passes the angle of orientation in double
             */
            virtual void rotate(double angle) override;
           
        
        private:
            //=========================Attributes=======================
            /**
             * @brief Distance between the robot’s feet and the ground.
             * 
             */
            double height_;
            /**
             * @brief Strength of the robot’s legs (1-10 scale)
             * 
             */
            int leg_strength_;
            /**
             * @brief Number of legs of the robot. Possibilities are 2, 4, and 6. If
                not provided, this attribute defaults to 2.
             * 
             */
            int number_of_legs_;

            //==========================methods=========================
            /**
             * @brief  The robot gives a kick with a strength of leg_strength_
             * 
             */
            void kick();
            /**
             * @brief The robot jumps amount times its leg_strength_ in centimeters.
             * 
             * @param amount amount high of jump in meters
             */
            void jump(double amount);


    }; //Class LeggedRobot
} // namespace RWA2