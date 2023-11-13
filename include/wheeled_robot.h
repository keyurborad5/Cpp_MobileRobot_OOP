#pragma once

#include<iostream>
#include<utility>
#include<mobile_robot.h>
/**
 * @brief namespace RWA2
 * 
 */
namespace RWA2{
    
    /**
     * @brief class WheeledRobot with public inheritance of MobileRobot
     * 
     */

    class WheeledRobot final: public MobileRobot{
        public:
            //============================constructor===============================
            WheeledRobot(double x, double y, double orientation,std::string wheeled_robot_model,std::string battery_model,
                         double wheel_diameter, double desired_speed,int number_of_wheels=2):
                        MobileRobot(x,y,orientation,wheeled_robot_model,battery_model),
                         number_of_wheels_{number_of_wheels}, wheel_diameter_{wheel_diameter},
                         desired_speed_{desired_speed}{
                            do{
                                if(number_of_wheels_%2 != 0 | number_of_wheels_>7){
                                    std::cout<< "Please enter the valid number of wheels, which are either 2, 4 or 6.: ";
                                    std::cin>> number_of_wheels_;
                                }
                            }while(number_of_wheels_%2 != 0 | number_of_wheels_>7);
                            
                         }
            
            //============================methods===============================
            /**
             * @brief The max distance value is
                    100. Each meter the robot moves, 1% of the battery’s charge is consumed
             * 
             * @param distance distance parameter to pass amount of distance to move in meters
             * @param angle angle of movemment while moving
             */
            virtual void move(double distance, double angle) override;
            /**
             * @brief prints all attributes of parent class MobileRobot as well as of WheeledRobot
             * 
             */
            virtual void print_status() override;

        protected:
            //============================methods===============================
            /**
             * @brief method to rotate the robot
             * 
             * @param angle angle paramter passes the angle of orientation in double
             */
            virtual void rotate(double angle) override;

            
        private:
            //=======================Attributes============================
            /**
             * @brief Number of wheels of the robot. If not provided, this at-
                    tribute defaults to 2. Possible values are 2, 4, or 6.
             * 
             */
            int number_of_wheels_;
            /**
             * @brief Diameter of each wheel in centimeter.
             * 
             */
            double wheel_diameter_;
            /**
             * @brief Desired speed of the robot.
             * 
             */
            double desired_speed_;
            
            //=======================Methods===============================
            /**
             * @brief In a while loop, add amount to speed_ until speed_
                is less or equal to desired_speed_. The method sleep for 0.5 s each time
                amount is added to speed_
             * 
             * @param amount amount of speed to be added every 0.5 sec
             */
            void accelerate(double amount);
            /**
             * @brief In a while loop, decrease speed_ by amount while
                speed_ is greater or equal to zero .
                The method sleep for 0.5 s each time speed_ decreases by amount.
             * 
             * @param amount amount of speed to be subtracted every 0.5 sec
             */
            void decelerate(double amount);
            /**
             * @brief The robot stops moving and its speed_ is zero.
             * 
             */
            void brake();


    }; // class WheeledRobot
} //namespace RWA2