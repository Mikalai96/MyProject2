#include "DS.h"
#include <cstdlib>
#include <iostream>


int main() {
    setlocale(LC_ALL, "Russian");

    DeliveryContext deliveryContext;
    float weight = 1.0f;  // вес в кг
    float distance = 1000.0f;  // расстояние в км

    std::cout << "Расчет стоимости доставки для груза:" << std::endl;
    std::cout << "Вес: " << weight << " кг" << std::endl;
    std::cout << "Расстояние: " << distance << " км" << std::endl;
    std::cout << "------------------------" << std::endl;

    // Тестирование разных стратегий
    deliveryContext.setStrategy(std::make_unique<GroundDelivery>());
    std::cout << "Стоимость: " << deliveryContext.calculateDeliveryCost(weight, distance) << " руб." << std::endl;
    std::cout << "------------------------" << std::endl;

    deliveryContext.setStrategy(std::make_unique<AirDelivery>());
    std::cout << "Стоимость: " << deliveryContext.calculateDeliveryCost(weight, distance) << " руб." << std::endl;
    std::cout << "------------------------" << std::endl;

    deliveryContext.setStrategy(std::make_unique<ExpressDelivery>());
    std::cout << "Стоимость: " << deliveryContext.calculateDeliveryCost(weight, distance) << " руб." << std::endl;

    return 0;
}
