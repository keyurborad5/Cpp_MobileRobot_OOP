#include "aquatic_robot.h"

//=================================================================================
//for method implementation of dive
void RWA2::AquaticRobot::dive(double depth){
    if(is_diving_==true){ std::cout<<" bring the robot on the surface and then pass this command"<<'\n';}
    //checks if robot has fins
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
    // updating depth after diving
    depth_=depth;
    // updating current charge after diving
    battery_.discharge(depth_);
    // updating divnig status
    is_diving_=true;
    //TO check if the method is executing or not
    std::cout<< "aquatic robot is at the depth of: "<< depth<<" meters."<<'\n';

}

//===============================================================================
//for method implementation of surface
void RWA2::AquaticRobot::surface(){
    if(is_diving_==false){ std::cout<<" Robot is already on surface, first make dive and then pass this command"<<'\n';}
    // checks if robot has fins
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
        // updating battery current charge after sufacing robot
        battery_.discharge(depth_);
        // updating depth after surfacing
        depth_=0.0;
        // updating diving status after surfacing
        is_diving_=false;
        std::cout<<"Aquatic robot is on the surface"<<'\n';
        // Starting charging once the robot is on surface
        battery_.start_charging();
    }

   
}
//================================================================================
//method implementation of move
void RWA2::AquaticRobot::move(double distance, double angle){
    // checks if the distance to be travelled is within limit and asks to enter new limit if it is exceeding the max limits
    do{
    if(distance>100){
        std::cout<<"Please enter the distance of aquatic robot in the range of 0m to 100m: ";
        std::cin>>distance;
    }
    }while(distance>100);

    // checks the battery current charge, if not sufficeint it sets charging command
    if(get_battery_level()<distance){
        std::cout<<"NOT enough battery level"<<'\n';
        battery_.start_charging();
    }
    // sensor data reading
    for (int i=0; i<sensors_.size();++i){
        sensors_[i]->read_data(5);
    }
    rotate(angle);
    dive(distance/2);
    surface();
    std::cout<<model_<<" reached at depth of "<<distance<<" meters and then surfaced."<<'\n';
    print_status();
    
    

}

//===========================================================================================
//method implementation of rotate
void RWA2::AquaticRobot::rotate(double angle){

    std::cout<<"AquaticRobot::"<<model_<<" rotated "<< angle<<" degrees."<<'\n';

}

//==========================================================================================
//method implementation of print_status
void RWA2::AquaticRobot::print_status(){
    RWA2::MobileRobot::print_status();
    std::cout << "================\n";
    std::cout<<"ROBOT MODEL IS: "<<model_<<'\n';
    std::cout << "================\n";
    std::cout<< "AquaticRobor Has Fins: " << std::boolalpha<< has_fins_<< 
    " AquaticRobot is at depth of: " << depth_ <<
    " meters. AquaticRobot is diving: "<<std::boolalpha<<is_diving_ <<"\n";

}