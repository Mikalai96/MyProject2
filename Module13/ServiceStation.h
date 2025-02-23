#pragma once
#include <iostream>
#include <vector>
#include "Cars.h"


template <typename T>
class ServiceStation {

public:
    ServiceStation(size_t limit); // Конструктор для установки лимита
    // Метод AddCar: добавляет машину в СТО
    void AddCar(const T& car);
    // Метод RepairAll: чинит все машины и перемещает их в гараж
    void RepairAll();

    // Метод DisplayGarage: выводит список машин в гараже
    void DisplayGarage() const;

private:
    std::vector<T> carsInService; // Список машин в сервисе
    size_t limit; // Лимит на количество машин

    // Вложенный шаблонный класс Garage
    class Garage {
    private:
        std::vector<T> repairedCars;

    public:
        Garage() = default;
        void AddToGarage(const T& car);

        void DisplayAll() const;
    };
    Garage garage;// Объект гаража
};
#include "ServiseStation.hpp"
