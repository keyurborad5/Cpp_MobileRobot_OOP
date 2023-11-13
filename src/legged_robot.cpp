#include "legged_robot.h"

//==============================================================================
//method implementation of Kick
void RWA2::LeggedRobot::kick(){
    std::cout<<model_<< " kicks with a strength of "<<leg_strength_<<'\n';
    //updating battery current charge status after kick
    battery_.discharge(0.01*leg_strength_);
}

//==============================================================================
//Method implementation of jump
void RWA2::LeggedRobot::jump(double amount){
    height_=amount*leg_strength_;
    std::cout<<model_<<" jumps at a height of" <<height_ <<"cm above the ground "<<'\n';
    //updating battery current charge status after kick
    battery_.discharge(height_);

}
//=============================================================================
//method implementation of move
void RWA2::LeggedRobot::move(double distance, double angle){
    // checks if the distance to be travelled is within limit and asks to enter new limit if it is exceeding the max limits
    do{
        if(distance>10){
            std::cout<<"Please enter the valid distance value of legged robot, between [0-10]: ";
            std::cin>>distance;
        }
    }while(distance>10);
    
    // checks if the current charge is enough to execute kick and jump
    double battery_consumed = distance*leg_strength_+ 0.01*leg_strength_;
    if (battery_consumed>get_battery_level()){
        battery_.start_charging();
    }
    //sensor data reading
    for (int i=0; i<sensors_.size();++i){
        sensors_[i]->read_data(5);
    }
    rotate(angle);
    jump(distance);
    kick();
    print_status();


}
//=============================================================================
//method implementation of rotate
void RWA2::LeggedRobot::rotate(double angle){
    std::cout<<"LeggedRobot:: "<<model_<<" rotated "<< angle<<"degrees."<<'\n';

}
//=============================================================================
//method implementation of print status
void RWA2::LeggedRobot::print_status(){
    RWA2::MobileRobot::print_status();
    std::cout << "================\n";
    std::cout<<"ROBOT MODEL IS: "<<model_<<'\n';
    std::cout << "================\n";
    std::cout<< "LeggedRobot has leg_strength: " << leg_strength_<< ", number of legs: " << number_of_legs_ <<", height of jump"<<height_ <<"\n";

}