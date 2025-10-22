#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <typeinfo>


// Base (abstract)
class Vehicle {
public:
    // counter for created vehicles
    static std::size_t s_count;

    Vehicle() { ++s_count; }

    virtual ~Vehicle() { }

    // interface prints behavior
    virtual void move() const = 0;

    // interface returns class name
    virtual std::string type() const = 0;

    // helper to serialize "<type>;<behavior>"
    virtual std::string behavior() const = 0;
};

std::size_t Vehicle::s_count = 0; // static member def

// Derived: Car
class Car 
    : public Vehicle {
public:
    std::string type() const override { return "Car"; }
    std::string behavior() const override { return "Car is driving on the road."; }

    void move() const override {
        std::cout << "Car is driving on the road.\n";
    }
};

// Derived: Boat
class Boat 
    : public Vehicle {
public:
    std::string type() const override { return "Boat"; }
    std::string behavior() const override { return "Boat is sailing on water."; }

    void move() const override {
        std::cout << "Boat is sailing on water.\n";
    }
};

// Derived: Plane
class Plane 
    : public Vehicle {
public:
    std::string type() const override { return "Plane"; }
    std::string behavior() const override { return "Plane is flying in the sky."; }

    void move() const override {
        std::cout << "Plane is flying in the sky.\n";
    }
};


// Derived: AmphibiousVehicle combines properties
class AmphibiousVehicle 
    : public Vehicle {
public:
    std::string type() const override { return "AmphibiousVehicle"; }

    std::string behavior() const override {
        return "AmphibiousVehicle is driving on the road and sailing on water.";
    }

    void move() const override {
        std::cout << "AmphibiousVehicle is driving on the road and sailing on water.\n";
    }
};


// helper to clean raw pointers
void cleanup(std::vector<Vehicle*>& vs) {
    for (auto* p : vs) delete p;
    vs.clear();
}


int main()
{
    std::cout << "Welcome Vehicles!\n\n";

    std::vector<Vehicle*> vehicles;
    vehicles.push_back(new Car());
    vehicles.push_back(new Boat());
    vehicles.push_back(new Plane());
    vehicles.push_back(new AmphibiousVehicle());

    // Print "<type>: <behavior>"
    for (const auto* v : vehicles) {
        std::cout << v->type() << ": ";
        v->move(); // prints
    }

    // Counter of created vehicles
    std::cout << "\nCreated vehicles (total): " << Vehicle::s_count << "\n";

    // Print dynamic type names (RTTI)
    std::cout << "\n[RTTI]\n";
    for (const auto* v : vehicles) {
        std::cout << "typeid(*v).name(): " << typeid(*v).name() << "\n";
    }

    // Serialization "<type>;<behavior>" to a text file
    {
        std::ofstream out("vehicles.txt");
        if (out) {
            for (const auto* v : vehicles) {
                out << v->type() << ";" << v->behavior() << "\n";
            }
        }
        else {
            std::cerr << "Can't open file.\n";
        }
    }

    //Clean up raw pointers
    cleanup(vehicles);

    return 0;
}

