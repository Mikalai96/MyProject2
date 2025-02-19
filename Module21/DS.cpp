#include "DS.h"
#include <iostream>

// ���������� GroundDelivery
float GroundDelivery::calculateCost(float weight, float distance) const {
    return RATE_PER_KM * distance + (weight * 2);
}

std::string GroundDelivery::getName() const {
    return "�������� ��������";
}

// ���������� AirDelivery
float AirDelivery::calculateCost(float weight, float distance) const {
    return (RATE_PER_KM * distance) + (weight * WEIGHT_MULTIPLIER);
}

std::string AirDelivery::getName() const {
    return "��������� ��������";
}

// ���������� ExpressDelivery
float ExpressDelivery::calculateCost(float weight, float distance) const {
    return (RATE_PER_KM * distance + weight * 3) * URGENCY_MULTIPLIER;
}

std::string ExpressDelivery::getName() const {
    return "��������-��������";
}

// ���������� DeliveryContext
void DeliveryContext::setStrategy(std::unique_ptr<IDeliveryStrategy> newStrategy) {
    strategy = std::move(newStrategy);
}

float DeliveryContext::calculateDeliveryCost(float weight, float distance) const {
    if (strategy) {
        std::cout << "������������ ���������: " << strategy->getName() << std::endl;
        return strategy->calculateCost(weight, distance);
    }
    return 0.0f;
}