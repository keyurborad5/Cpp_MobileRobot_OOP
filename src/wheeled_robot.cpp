#include <wheeled_robot.h>
#include <chrono>
#include <thread>

void RWA2::WheeledRobot::accelerate(double amount){
    while(speed_<desired_speed_){
        speed_+=amount;
        std::chrono::milliseconds duration(500);
        std::this_thread::sleep_for(duration);

    }
    std::cout<<model_<<"has reachedthedesired speed of :" << desired_speed_<<"m/s"<<'\n';
}

void RWA2::WheeledRobot::decelerate(double amount){
     while(speed_>0){
        speed_-=amount;
        std::chrono::milliseconds duration(500);
        std::this_thread::sleep_for(duration);

    }
    //not asked for the print but keeping for debugging
    std::cout<<model_<<"has reachedthedesired speed of :" << "0"<<"m/s"<<'\n';
}

void RWA2::WheeledRobot::brake(){
    speed_=0;
    //not asked for the print but keeping for debugging
    std::cout<<"applying brake"<<'\n';
}

void RWA2::WheeledRobot::move(double distance, double angle){
    do{
    if(distance>100){
        std::cout<<"Please enter the distance in the range if 0m to 100m"<<'\n';
    }
    }while(distance>100);

    if(get_battery_level()<distance){
        std::cout<<"NOT enough battery level"<<'\n';
        battery_.start_charging();
    }
    
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

void RWA2::WheeledRobot::rotate(double angle){
    std::cout<<"WheeledRobot::"<<model_<<" rotated "<< angle<<" degrees."<<'\n';

}

void RWA2::WheeledRobot::print_status(){
    RWA2::MobileRobot::print_status();
    std::cout << "================\n";
    std::cout<<"ROBOT MODEL IS: "<<model_<<'\n';
    std::cout << "================\n";
    std::cout<< "WheeledRobot has number of wheels: "<< number_of_wheels_<< ", Wheel diameter: " << wheel_diameter_<< " cm, desired speed: " << desired_speed_ << "\n";

}