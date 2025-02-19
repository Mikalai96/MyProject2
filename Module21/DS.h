#pragma once
#include <string>
#include <memory>

// Интерфейс стратегии доставки
class IDeliveryStrategy {
public:
    virtual ~IDeliveryStrategy() = default;
    virtual float calculateCost(float weight, float distance) const = 0;
    virtual std::string getName() const = 0;
};

// Наземная доставка
class GroundDelivery : public IDeliveryStrategy {
private:
    const float RATE_PER_KM = 10.0f;
public:
    float calculateCost(float weight, float distance) const override;
    std::string getName() const override;
};

// Воздушная доставка
class AirDelivery : public IDeliveryStrategy {
private:
    const float RATE_PER_KM = 20.0f;
    const float WEIGHT_MULTIPLIER = 5.0f;
public:
    float calculateCost(float weight, float distance) const override;
    std::string getName() const override;
};

// Экспресс-доставка
class ExpressDelivery : public IDeliveryStrategy {
private:
    const float RATE_PER_KM = 30.0f;
    const float URGENCY_MULTIPLIER = 1.5f;
public:
    float calculateCost(float weight, float distance) const override;
    std::string getName() const override;
};

// Контекст доставки
class DeliveryContext {
private:
    std::unique_ptr<IDeliveryStrategy> strategy;

public:
    void setStrategy(std::unique_ptr<IDeliveryStrategy> newStrategy);
    float calculateDeliveryCost(float weight, float distance) const;
};