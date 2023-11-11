#include "aerial_robot.h"
#include <chrono>
#include <thread>

void RWA2::AerialRobot::take_off(double altitude){
    if(is_flying_==true){ std::cout<<" Land the robot on the surface and then pass this command"<<'\n';}
    else{
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
    
    altitude_=altitude;
    battery_.discharge(2*altitude_);
    is_flying_=true;
    //TO check if the method is executing or not
    
    std::cout<<"aerial robot took off at altitude: "<< altitude<< " meters."<<'\n';
}

void RWA2::AerialRobot::land(){
    if(is_flying_==false){ std::cout<<" Robot is already on surface, first make dive and then pass this command"<<'\n';}
    else{
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
        battery_.discharge(2*altitude_);
        altitude_=0.0;
        is_flying_=false;
        std::cout<<"Aerial robot is on the surface"<<'\n';
        
    }
}

void RWA2::AerialRobot::move(double distance, double angle){
    do{
    if(distance>50){
        std::cout<<"Please enter the distance in the range if 0m to 50m ";
        std::cin>>distance;
    }
    }while (distance>50);
    
    if(get_battery_level()<2*distance){
        std::cout<<"NOT enough battery level"<<'\n';
        battery_.start_charging();
    }
    for (int i=0; i<sensors_.size();++i){
        sensors_[i]->read_data(5);
    }
    take_off(distance/2);
    rotate(angle);
    land();
    std::cout<<model_<<" reached an altitude of "<<distance<<" meters and then landed."<<'\n';
    print_status();


}

void RWA2::AerialRobot::rotate(double angle){
    std::cout<<"AerialRobot::"<<model_<<" rotated "<< angle<<" degrees."<<'\n';

}

void RWA2::AerialRobot::print_status(){
    RWA2::MobileRobot::print_status();
    std::cout << "================\n";
    std::cout<<"ROBOT MODEL IS: "<<model_<<'\n';
    std::cout << "================\n";
    std::cout<< "Aerial Robot has Wings: (" << std::boolalpha << has_wings_<< "), Altitude: " << altitude_ 
    << ", AerialRobot is flying: ("<<std::boolalpha<<is_flying_<<"). \n";

}