#include "Cars.h"

Car::Car(const std::string& name) : name(name), isRepaired(false) {}
void Car::Repair() {
        isRepaired = true;
    }

std::ostream& operator<<(std::ostream& os, const Car& car) {
        os << "Car: " << car.name << ", Repaired: " << (car.isRepaired ? "Yes" : "No");
        return os;
}

PassengerCar::PassengerCar(const std::string& name) : Car(name) {}

CargoCar::CargoCar(const std::string& name) : Car(name) {}

