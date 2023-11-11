#include "aquatic_robot.h"


void RWA2::AquaticRobot::dive(double depth){
    if(is_diving_==true){ std::cout<<" bring the robot on the surface and then pass this command"<<'\n';}
    else{
        if(has_fins_==true){
            int speed=2;
            int time = depth*1000/speed;
            std::chrono::milliseconds duration(time);
            std::this_thread::sleep_for(duration);
            }
        else {
            int speed=1;
            int time = depth*1000/speed;
            std::chrono::milliseconds duration(time);
            std::this_thread::sleep_for(duration);
            }
    }
    depth_=depth;
    battery_.discharge(depth_);
    is_diving_=true;
    //TO check if the method is executing or not
    std::cout<< "aquatic robot is at the depth of: "<< depth<<" meters."<<'\n';

}
void RWA2::AquaticRobot::surface(){
    if(is_diving_==false){ std::cout<<" Robot is already on surface, first make dive and then pass this command"<<'\n';}
    else{
        if(has_fins_==true){
            int speed=4;
            int time= depth_*1000/speed;
            std::chrono::milliseconds duration(time);
            std::this_thread::sleep_for(duration);
        }
        else{
            int speed=2;
            int time = depth_*1000/speed;
            std::chrono::milliseconds duration(time);
            std::this_thread::sleep_for(duration);
        }
        battery_.discharge(depth_);
        depth_=0.0;
        is_diving_=false;
        std::cout<<"Aquatic robot is on the surface"<<'\n';
        battery_.start_charging();
    }

   
}

void RWA2::AquaticRobot::move(double distance, double angle){
    do{
    if(distance>100){
        std::cout<<"Please enter the distance in the range of 0m to 100m"<<'\n';
        std::cin>>distance;
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
    dive(distance/2);
    surface();
    std::cout<<model_<<" reached at depth of "<<distance<<" meters and then surfaced."<<'\n';
    print_status();
    
    

}

void RWA2::AquaticRobot::rotate(double angle){

    std::cout<<"AquaticRobot::"<<model_<<" rotated "<< angle<<" degrees."<<'\n';

}

void RWA2::AquaticRobot::print_status(){
    RWA2::MobileRobot::print_status();
    std::cout << "================\n";
    std::cout<<"ROBOT MODEL IS: "<<model_<<'\n';
    std::cout << "================\n";
    std::cout<< "AquaticRobor Has Fins: " << std::boolalpha<< has_fins_<< 
    " AquaticRobot is at depth of: " << depth_ <<
    " meters. AquaticRobot is diving: "<<std::boolalpha<<is_diving_ <<"\n";

}