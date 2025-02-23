#pragma once
#include <iostream>
#include <vector>
#include "Cars.h"


template <typename T>
class ServiceStation {

public:
    ServiceStation(size_t limit); // ����������� ��� ��������� ������
    // ����� AddCar: ��������� ������ � ���
    void AddCar(const T& car);
    // ����� RepairAll: ����� ��� ������ � ���������� �� � �����
    void RepairAll();

    // ����� DisplayGarage: ������� ������ ����� � ������
    void DisplayGarage() const;

private:
    std::vector<T> carsInService; // ������ ����� � �������
    size_t limit; // ����� �� ���������� �����

    // ��������� ��������� ����� Garage
    class Garage {
    private:
        std::vector<T> repairedCars;

    public:
        Garage() = default;
        void AddToGarage(const T& car);

        void DisplayAll() const;
    };
    Garage garage;// ������ ������
};
#include "ServiseStation.hpp"
