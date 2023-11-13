#include <wheeled_robot.h>
#include <chrono>
#include <thread>

//====================================================================================
//method implementation of accelerate
void RWA2::WheeledRobot::accelerate(double amount){
    while(speed_<desired_speed_){
        speed_+=amount;
        std::chrono::milliseconds duration(500);
        std::this_thread::sleep_for(duration);

    }
    std::cout<<model_<<"has reachedthedesired speed of :" << desired_speed_<<"m/s"<<'\n';
}
//==================================================================================
//method implementation of decelerate
void RWA2::WheeledRobot::decelerate(double amount){
     while(speed_>0){
        speed_-=amount;
        std::chrono::milliseconds duration(500);
        std::this_thread::sleep_for(duration);

    }
    //not asked for the print but keeping for debugging
    std::cout<<model_<<"has reachedthedesired speed of :" << "0"<<"m/s"<<'\n';
}
//==================================================================================
//method implementation of brake
void RWA2::WheeledRobot::brake(){
    speed_=0;
    //not asked for the print but keeping for debugging
    std::cout<<"applying brake"<<'\n';
}
//=================================================================================
//method implementation for move
void RWA2::WheeledRobot::move(double distance, double angle){
    // checks if the distance to be travelled is within limit and asks to enter new limit if it is exceeding the max limit
    do{
    if(distance>100){
        std::cout<<"Please enter the distance of wheeled robot in the range if 0m to 100m: ";
    }
    }while(distance>100);
    // Checks the current charge status of the battery 
    if(get_battery_level()<distance){
        std::cout<<"NOT enough battery level"<<'\n';
        battery_.start_charging();
    }
    //  reading sensor data
    for (int i=0; i<sensors_.size();++i){
        sensors_[i]->read_data(5);
    }
    rotate(angle);
    accelerate(2);
    int time=distance*1000-2000;
    std::chrono::milliseconds duration(time);
    std::this_thread::sleep_for(duration);
    decelerate(2);
    brake();
    battery_.discharge(distance);
    std::cout<<model_<<" drove "<<distance<<" m."<<'\n';
    print_status();

    


}
//========================================================================================
//method implementation of rotate
void RWA2::WheeledRobot::rotate(double angle){
    std::cout<<"WheeledRobot::"<<model_<<" rotated "<< angle<<" degrees."<<'\n';

}
//=======================================================================================
//method implementation of printstatus
void RWA2::WheeledRobot::print_status(){
    RWA2::MobileRobot::print_status();
    std::cout << "================\n";
    std::cout<<"ROBOT MODEL IS: "<<model_<<'\n';
    std::cout << "================\n";
    std::cout<< "WheeledRobot has number of wheels: "<< number_of_wheels_<< ", Wheel diameter: " << wheel_diameter_<< " cm, desired speed: " << desired_speed_ << "\n";

}