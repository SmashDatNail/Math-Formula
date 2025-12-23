
#include <iomanip>
#include <iostream>
#include <cmath>

const double gravity = 9.81;

double time(double height){
    return sqrt((2*height)/gravity); 
}

double final_velocity(double height) {
  return gravity * time(height);
}

double Kinetic_Energy(double height, double mass) {
  return 0.5 * mass * pow(final_velocity(height), 2);
}

int main(){
   double height;
   double time_taken;
   double velocity;
   double Rock_Impact;
   double mass_rock = 0.05;

   std::cout<< "Enter a height in meters: ";
   std::cin >> height;
   std::cout << "Assuming you throw a small pebble (weight at 50g) vertically at " << height << " Meters\n";

   time_taken = time(height);
   velocity = final_velocity(height);
   Rock_Impact = Kinetic_Energy(height, mass_rock);

   std::cout << std::fixed << std::setprecision(2) << "The time taken for the pebble to hit the ground is " << time_taken << " Seconds\n";
   std::cout << std::fixed << std::setprecision(2) << "The velocity of the pebble is " << velocity << " m/s\n";
   std::cout << std::fixed << std::setprecision(2) << "The Kinetic Energy of the pebble is " << Rock_Impact << " Joules\n";

   return 0;  
}

