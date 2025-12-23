#include <algorithm>
#include <iostream>
#include <vector>

struct car {
    double final_velocity;
    int distance;
};

double time (const car& car)  {
    return (2.0 * car.distance) / (car.final_velocity);
};

int main(){
    int totalcar;
    int distance;
    double kmh;
    std::cout << "Enter the distance of the race in meter: ";
    std::cin >> distance;
    std::cout << "Enter how many cars are in the race?: ";
    std::cin >> totalcar;
    std::vector<car> cars(totalcar);
    
    for (int i= 0; i < totalcar; i++) {
     cars[i].distance = distance;
     std::cout << "Enter the velocity of car " << i + 1 << " in km/h : ";
     std::cin >> kmh;
     cars[i].final_velocity = kmh * (5.0/18.0);
    }

    auto winner = std::min_element(
        cars.begin(),
        cars.end(),
        [](const car& a, const car& b) {return time(a) < time(b);} );

    int winnerIndex = std::distance(cars.begin(), winner);

    std::cout << "\nWinner: Car " << winnerIndex + 1
              << " with time " << time(*winner) << " seconds\n";

    
    return 0;
}
