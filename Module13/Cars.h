#pragma once
#include <iostream>
#include <string>
class Car {
public:
    Car(const std::string& name);
    virtual ~Car() = default;

    void Repair();

    friend std::ostream& operator<<(std::ostream& os, const Car& car);
private:
    std::string name;
    bool isRepaired;
};
class PassengerCar : public Car {
    PassengerCar(const std::string& name);
};
class CargoCar : public Car {
    CargoCar(const std::string& name);
};