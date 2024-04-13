#include <string>
#include <iostream>
using namespace std;

class Creature {
public:
    string name;
    int health, position_x, position_y;
    void move(int dx, int dy) {
        position_x += dx;
        position_y += dy;
        std::cout << position_x << " " << position_y << "\n";
    }
};

class Beast : public Creature {
};

class Bug : public Creature {
public:
    int leg_count;
};

class Wasp : public Bug {
public:
    bool can_sting;
    Wasp(int health_in, int pos_x_in, int pos_y_in) {
        leg_count = 6;
        can_sting = true;
        health = health_in;
        position_x = pos_x_in;
        position_y = pos_y_in;
    }
    void sting() {
        if (can_sting) {
            std::cout << "bzhh!" << std::endl;
            can_sting = false;
        } else {
            std::cout << "there is no sting" << std::endl;
        }
    }
};

int main() {
    Wasp wasp_instance(10, 5, 2);
    wasp_instance.sting();
    wasp_instance.sting();
    wasp_instance.move(5, 5);
    return 0;
}