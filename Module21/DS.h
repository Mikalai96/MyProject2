#pragma once
#include <string>
#include <memory>

// ��������� ��������� ��������
class IDeliveryStrategy {
public:
    virtual ~IDeliveryStrategy() = default;
    virtual float calculateCost(float weight, float distance) const = 0;
    virtual std::string getName() const = 0;
};

// �������� ��������
class GroundDelivery : public IDeliveryStrategy {
private:
    const float RATE_PER_KM = 10.0f;
public:
    float calculateCost(float weight, float distance) const override;
    std::string getName() const override;
};

// ��������� ��������
class AirDelivery : public IDeliveryStrategy {
private:
    const float RATE_PER_KM = 20.0f;
    const float WEIGHT_MULTIPLIER = 5.0f;
public:
    float calculateCost(float weight, float distance) const override;
    std::string getName() const override;
};

// ��������-��������
class ExpressDelivery : public IDeliveryStrategy {
private:
    const float RATE_PER_KM = 30.0f;
    const float URGENCY_MULTIPLIER = 1.5f;
public:
    float calculateCost(float weight, float distance) const override;
    std::string getName() const override;
};

// �������� ��������
class DeliveryContext {
private:
    std::unique_ptr<IDeliveryStrategy> strategy;

public:
    void setStrategy(std::unique_ptr<IDeliveryStrategy> newStrategy);
    float calculateDeliveryCost(float weight, float distance) const;
};