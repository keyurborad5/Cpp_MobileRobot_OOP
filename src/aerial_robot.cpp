#include "aerial_robot.h"
#include <chrono>
#include <thread>
//===================================================================
//method implementation of take_off
void RWA2::AerialRobot::take_off(double altitude){
    if(is_flying_==true){ std::cout<<" Land the robot on the surface and then pass this command"<<'\n';}
    else{
        // condition check if robot has wings
        if(has_wings_==true){
            int speed=3;
            int time = altitude*1000/speed;
            std::chrono::milliseconds duration(time);
            std::this_thread::sleep_for(duration);
            }
        else {
            double speed=1.5;
            int time = altitude*1000/speed;
            std::chrono::milliseconds duration(time);
            std::this_thread::sleep_for(duration);
            }
    }
    //as the robot completes the take off duration its altitude updates
    altitude_=altitude;
    //battery would also be discharge due to take_off
    battery_.discharge(2*altitude_);
    // flying status updating
    is_flying_=true;
    //TO check if the method is executing or not
    
    std::cout<<"aerial robot took off at altitude: "<< altitude<< " meters."<<'\n';
}

//=======================================================================================
//method implementation of land
void RWA2::AerialRobot::land(){
    if(is_flying_==false){ std::cout<<" Robot is already on surface, first make dive and then pass this command"<<'\n';}
    else{
        // condition check if robot has wings
        if(has_wings_==true){
            int speed=4;
            int time= altitude_*1000/speed;
            std::chrono::milliseconds duration(time);
            std::this_thread::sleep_for(duration);
        }
        else{
            int speed=2;
            int time = altitude_*1000/speed;
            std::chrono::milliseconds duration(time);
            std::this_thread::sleep_for(duration);
        }
        // battery discharges accordingly
        battery_.discharge(2*altitude_);
        // As robot lands it altitude is also updated
        altitude_=0.0;
        // updating flying status
        is_flying_=false;
        std::cout<<"Aerial robot is on the surface"<<'\n';
        
    }
}

//=========================================================================
// for method implementation of move
void RWA2::AerialRobot::move(double distance, double angle){
    // checks if the distance to be travelled is within limit and asks to enter new limit if it is exceeding the max limits
    do{
    if(distance>50){
        std::cout<<"Please enter the distance for aerial robot in the range if 0m to 50m: ";
        std::cin>>distance;
    }
    }while (distance>50);
    
    // checks the battery current charge, if not sufficeint it sets charging command
    if(get_battery_level()<2*distance){
        std::cout<<"NOT enough battery level"<<'\n';
        battery_.start_charging();
    }
    //sensor data reading
    for (int i=0; i<sensors_.size();++i){
        sensors_[i]->read_data(5);
    }
    take_off(distance/2);
    rotate(angle);
    land();
    std::cout<<model_<<" reached an altitude of "<<distance<<" meters and then landed."<<'\n';
    print_status();


}
//============================================================================
// for method implementation of rotate
void RWA2::AerialRobot::rotate(double angle){
    std::cout<<"AerialRobot::"<<model_<<" rotated "<< angle<<" degrees."<<'\n';

}

//===========================================================================
//for method implementation of print_status
void RWA2::AerialRobot::print_status(){
    RWA2::MobileRobot::print_status();
    std::cout << "================\n";
    std::cout<<"ROBOT MODEL IS: "<<model_<<'\n';
    std::cout << "================\n";
    std::cout<< "Aerial Robot has Wings: (" << std::boolalpha << has_wings_<< "), Altitude: " << altitude_ 
    << ", AerialRobot is flying: ("<<std::boolalpha<<is_flying_<<"). \n";

}