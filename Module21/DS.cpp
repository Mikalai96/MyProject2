#include "DS.h"
#include <iostream>

// Реализация GroundDelivery
float GroundDelivery::calculateCost(float weight, float distance) const {
    return RATE_PER_KM * distance + (weight * 2);
}

std::string GroundDelivery::getName() const {
    return "Наземная доставка";
}

// Реализация AirDelivery
float AirDelivery::calculateCost(float weight, float distance) const {
    return (RATE_PER_KM * distance) + (weight * WEIGHT_MULTIPLIER);
}

std::string AirDelivery::getName() const {
    return "Воздушная доставка";
}

// Реализация ExpressDelivery
float ExpressDelivery::calculateCost(float weight, float distance) const {
    return (RATE_PER_KM * distance + weight * 3) * URGENCY_MULTIPLIER;
}

std::string ExpressDelivery::getName() const {
    return "Экспресс-доставка";
}

// Реализация DeliveryContext
void DeliveryContext::setStrategy(std::unique_ptr<IDeliveryStrategy> newStrategy) {
    strategy = std::move(newStrategy);
}

float DeliveryContext::calculateDeliveryCost(float weight, float distance) const {
    if (strategy) {
        std::cout << "Используется стратегия: " << strategy->getName() << std::endl;
        return strategy->calculateCost(weight, distance);
    }
    return 0.0f;
}