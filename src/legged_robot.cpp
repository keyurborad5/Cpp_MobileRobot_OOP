#include "legged_robot.h"

void RWA2::LeggedRobot::kick(){
    std::cout<<model_<< " kicks with a strength of "<<leg_strength_<<'\n';
    battery_.discharge(0.01*leg_strength_);
}

void RWA2::LeggedRobot::jump(double amount){
    height_=amount*leg_strength_;
    std::cout<<model_<<" jumps at a height of" <<height_ <<"cm above the ground "<<'\n';
    battery_.discharge(height_);

}

void RWA2::LeggedRobot::move(double distance, double angle){
    do{
        if(distance>10){
            std::cout<<"Please enter the valid distance value, between [0-10]: ";
            std::cin>>distance;
        }

    }while(distance>10);
    double battery_consumed = distance*leg_strength_+ 0.01*leg_strength_;
    if (battery_consumed>get_battery_level()){
        battery_.start_charging();
    }
    for (int i=0; i<sensors_.size();++i){
        sensors_[i]->read_data(5);
    }
    rotate(angle);
    jump(distance);
    kick();
    print_status();


}

void RWA2::LeggedRobot::rotate(double angle){
    std::cout<<"LeggedRobot:: "<<model_<<" rotated "<< angle<<"degrees."<<'\n';

}

void RWA2::LeggedRobot::print_status(){
    RWA2::MobileRobot::print_status();
    std::cout << "================\n";
    std::cout<<"ROBOT MODEL IS: "<<model_<<'\n';
    std::cout << "================\n";
    std::cout<< "LeggedRobot has leg_strength: " << leg_strength_<< ", number of legs: " << number_of_legs_ <<", height of jump"<<height_ <<"\n";

}