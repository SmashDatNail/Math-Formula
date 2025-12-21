#include <algorithm>
#include <iostream>
#include <vector>

struct car {
    double initial_velocity;
    double final_velocity;
    int distance;
};

double time (const car& car)  {
    return (2.0 * car.distance) / (car.final_velocity + car.initial_velocity);
};

int main(){
    int totalcar;
    int distance;
    std::cout << "Enter the distance of the race in meter: ";
    std::cin >> distance;
    std::cout << "Enter how many cars are in the race?: ";
    std::cin >> totalcar;
    std::vector<car> cars(totalcar);
    
    for (int i= 0; i < totalcar; i++) {
     cars[i].distance = distance;
     cars[i].initial_velocity = 0;
     std::cout << "Enter the velocity of car" << i + 1 << " in m/s : ";
     std::cin >> cars[i].final_velocity;
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