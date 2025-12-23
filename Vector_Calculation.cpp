#include <iomanip>
#include <iostream>
#include <cmath>

struct vector {
    double x;
    double y;
};

double distance(const vector& a, const vector& b){
    return sqrt(pow(b.x - a.x, 2)+ pow(b.y-a.y, 2));
}

double dotproduct(const vector& a,const vector& b) {
    return a.x * b.x + a.y * b.y;
}

double magnitude (const vector& v){
    return sqrt(v.x * v.x + v.y * v.y);
}

double angle_two_vectors(const vector& a, const vector& b){
    return acos(dotproduct(a, b)/ (magnitude(a) * magnitude(b)));
}


int main(){
    vector v1,v2;
    int input;
    double result;
    double convert_rad_to_deg = 180.0 / M_PI;
    std::string mode;
    std::cout << "Enter a first coordinate (x y): ";
    std::cin >> v1.x >> v1.y;
    
    std::cout << "Enter a second coordinate (x y): ";
    std::cin >> v2.x >> v2.y;

    std::cout << "Select a mode\n";
    std::cout << "1-Dot product\n";
    std::cout << "2-Distance\n";
    std::cout << "3-Angle between two vectors\n";
    std::cout << "--> ";
    std::cin >> input;

    switch(input){
        case 1:result = dotproduct(v1, v2); mode = "The dot product is: "; break;
        case 2:result = distance(v1 ,v2); mode = "The distance is: "; break;
        case 3:result = angle_two_vectors(v1, v2); result= result * convert_rad_to_deg;  mode = "The angle betweeen two vectors is: "; break;
        default: std::cout << "Invalid option\n"; return 1; break;
    }
    std::cout << std::fixed <<  std::setprecision(2) << mode << result << "\n";
    return 0;

    
}
