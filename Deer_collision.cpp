#include <iomanip>
#include <iostream>
double km_to_ms(const double kmh) {
    return kmh / 3.6;
}
double distance(const double ms,const double a) {
    return (ms*ms) / (2*a);
}
int main(){
    int deer_distance = 10;
    double deceleration = 8.0;
    double velocity,ms_velocity,car_distance;
    
    std::cout << "A deer is 10 meters away from you while you're driving a car\n";
    std::cout << "Type a velocity (km/h) to calculate the distance whether you will hit the deer or not: ";
    std::cin >> velocity;

    ms_velocity = km_to_ms(velocity);
    car_distance = distance(ms_velocity, deceleration);

    std::cout << std::fixed << std::setprecision(2) << "You brake at " << car_distance << " meters\n";

    if (car_distance >= deer_distance) {std::cout << "You hit the deer!!\n";}
    else {std::cout << "You successfully brake before you hit the deer!!\n";}

    return 0;
}
