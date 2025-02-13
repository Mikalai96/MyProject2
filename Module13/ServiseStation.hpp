#include "ServiceStation.h"

template <typename T>
ServiceStation<T>::ServiceStation(size_t limit) : limit(limit) {} // ����������� ��� ��������� ������
// ����� AddCar: ��������� ������ � ���
template <typename T>
void ServiceStation<T>::AddCar(const T& car) {
    if (carsInService.size() < limit) {
        carsInService.push_back(car);
        std::cout << "Car added to service station: " << car << std::endl;
    }
    else {
        std::cerr << "Error: Service station is full! Cannot add more cars." << std::endl;
    }
}
// ����� RepairAll: ����� ��� ������ � ���������� �� � �����
template <typename T>
void ServiceStation<T>::RepairAll() {
    if (carsInService.empty()) {
        std::cout << "No cars to repair." << std::endl;
        return;
    }

    for (auto& car : carsInService) {
        car.Repair();
        garage.AddToGarage(car);
    }

    carsInService.clear(); // ������� ������ ����� � �������
    std::cout << "All cars repaired and moved to the garage." << std::endl;
}

// ����� DisplayGarage: ������� ������ ����� � ������
template <typename T>
void ServiceStation<T>::DisplayGarage() const {
    garage.DisplayAll();
    for (int k = 1; k <= 35; k++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}
template <typename T>
void ServiceStation<T>::Garage::AddToGarage(const T& car) {
    repairedCars.push_back(car);
}

// ����� DisplayAll: ������� ������ ����� � ������
template <typename T>
void ServiceStation<T>::Garage::DisplayAll() const {
    if (repairedCars.empty()) {
        std::cout << "Garage is empty." << std::endl;
        return;
    }
    std::cout << "Cars in Garage:" << std::endl;
    for (const auto& car : repairedCars) {
        std::cout << car << std::endl;
    }
}


