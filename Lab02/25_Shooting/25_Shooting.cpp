#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Shooting target (сoncentric circles)
    // radius 1 > 10 pts
    // radius 2 > 5 pts
    // radius 3 > 1 pt
    // over 3 > 0 pts (missed)

    // target points to reach
    const int goal = 50;

    // accumulated points
    int total_points = 0;

    // number of attempts
    int shots = 0;

    //double cx = 0.0;
    //double cy = 0.0;
    
    // randomize target center
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int cx_i = std::rand() % 5 - 2; // integers in [-2..2]
    int cy_i = std::rand() % 5 - 2;
    double cx = static_cast<double>(cx_i);
    double cy = static_cast<double>(cy_i);

    std::cout << "Target center is hidden.\n";
    //std::cout << "Target center: (" << cx << ", " << cy << ")\n";
    std::cout << "Shoot until you reach " << goal << " points.\n";

    while (total_points < goal) {
        double x, y;

        std::cout << "Enter shot coordinates (x y): ";
        if (!(std::cin >> x >> y)) {
            std::cerr << "Input error\n";
            
            //return 1; // avoid killing the game, ask again
            std::cin.clear();
            std::cin.ignore(1000000, '\n');
            continue;
        }

        // add random target disturbance
         int noiseXi = std::rand() % 3 - 1; // integers in  [-1..1]
         int noiseYi = std::rand() % 3 - 1;
         double noiseX = static_cast<double>(noiseXi);
         double noiseY = static_cast<double>(noiseYi);
         x += noiseX;
         y += noiseY;

        // distance from target center
        double dx = x - cx;
        double dy = y - cy;
        double r = std::sqrt(dx * dx + dy * dy);

        int score = 0;

        if (r <= 1.0) score = 10;
        else if (r <= 2.0) score = 5;
        else if (r <= 3.0) score = 1;
        else score = 0;

        total_points += score;
        shots++;

        std::cout << "Shot #" << shots << ": +" << score << " points (total = " << total_points << ")\n";
    }

    std::cout << "\nGame over! Total shots: " << shots << "\n";

    // shooter level
    if (shots < 10) {
        std::cout << "Level: Sniper\n";
    }
    else if (shots <= 20) {
        std::cout << "Level: Shooter\n";
    }
    else {
        std::cout << "Level: Novice\n";
    }

    return 0;
}

