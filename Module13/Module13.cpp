#include <iostream>
#include <string>
#include <vector>
#include "ServiceStation.h"
#include "Cars.h"




//template <typename T>
//class ServiceStation {
//
//public:
//    ServiceStation(size_t limit) : limit(limit) {} // Конструктор для установки лимита
//    // Метод AddCar: добавляет машину в СТО
//    void AddCar(const T& car) {
//        if (carsInService.size() < limit) {
//            carsInService.push_back(car);
//            std::cout << "Car added to service station: " << car << std::endl;
//        }
//        else {
//            std::cerr << "Error: Service station is full! Cannot add more cars." << std::endl;
//        }
//    };
//    // Метод RepairAll: чинит все машины и перемещает их в гараж
//    void RepairAll() {
//        if (carsInService.empty()) {
//            std::cout << "No cars to repair." << std::endl;
//            return;
//        }
//
//        for (auto& car : carsInService) {
//            car.Repair();
//            garage.AddToGarage(car);
//        }
//
//        carsInService.clear(); // Очищаем список машин в сервисе
//        std::cout << "All cars repaired and moved to the garage." << std::endl;
//    }
//
//    // Метод DisplayGarage: выводит список машин в гараже
//    void DisplayGarage() const {
//        garage.DisplayAll();
//        for (int k = 1; k <= 35; k++) {
//            std::cout << "-";
//        }
//        std::cout << std::endl;
//    }
//
//private:
//    std::vector<T> carsInService; // Список машин в сервисе
//    size_t limit; // Лимит на количество машин
//
//    // Вложенный шаблонный класс Garage
//    class Garage {
//    private:
//        std::vector<T> repairedCars;
//
//    public:
//        Garage() = default;
//        void AddToGarage(const T& car) {
//            repairedCars.push_back(car);
//        }
//
//        void DisplayAll() const {
//            if (repairedCars.empty()) {
//                std::cout << "Garage is empty." << std::endl;
//                return;
//            }
//            std::cout << "Cars in Garage:" << std::endl;
//            for (const auto& car : repairedCars) {
//                std::cout << car << std::endl;
//            }
//        }
//    };
//    Garage garage;// Объект гаража
//};
//class Car {
//public:
//    Car(const std::string& name) : name(name), isRepaired(false) {}
//    virtual ~Car() = default;
//
//    void Repair() {
//        isRepaired = true;
//    }
//
//    friend std::ostream& operator<<(std::ostream& os, const Car& car) {
//        os << "Car: " << car.name << ", Repaired: " << (car.isRepaired ? "Yes" : "No");
//        return os;
//    }
//private:
//    std::string name;
//    bool isRepaired;
//};
//class PassengerCar : public Car {
//    PassengerCar(const std::string& name) : Car(name) {}
//};
//class CargoCar : public Car {
//    CargoCar(const std::string& name) : Car(name) {}
//};




int main()
{
    // Создаем сервисную станцию для легковых машин с лимитом 5 машин
    ServiceStation<Car> stationPassengerCar(5);    
    // Добавляем машины в СТО
    stationPassengerCar.AddCar(Car("Toyota"));
    stationPassengerCar.AddCar(Car("Honda"));
    stationPassengerCar.AddCar(Car("Ford"));
    stationPassengerCar.AddCar(Car("Opel"));
    stationPassengerCar.AddCar(Car("Lada"));
    // Пробуем добавить машину сверх лимита
    stationPassengerCar.AddCar(Car("Mazda")); // Выдаст ошибку
    // Чиним все машины и перемещаем их в гараж
    stationPassengerCar.RepairAll();
    // Выводим содержимое гаража
    stationPassengerCar.DisplayGarage();
  
    // Создаем сервисную станцию для грузовых машин с лимитом 5 машин
    ServiceStation<Car> stationCargoCar(5);
    stationCargoCar.AddCar(Car("VW T2"));
    stationCargoCar.AddCar(Car("VW T3"));
    stationCargoCar.AddCar(Car("VW T4"));
    stationCargoCar.AddCar(Car("VW T5"));
    stationCargoCar.AddCar(Car("VW T6"));
    // Пробуем добавить машину сверх лимита
    stationCargoCar.AddCar(Car("Ford Transit")); // Выдаст ошибку
    // Чиним все машины и перемещаем их в гараж
    stationCargoCar.RepairAll();
    // Выводим содержимое гаража
    stationCargoCar.DisplayGarage();
    return 0;
}

