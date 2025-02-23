#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <thread>

enum class OrderStatus {
    New,
    Processing,
    Shipped
};
std::string status_to_string(OrderStatus status);
class Order {
private:
    int id;
    double amount;
    OrderStatus status;
    std::chrono::system_clock::time_point order_date;

public:
    // Конструктор
    Order(int id, double amount, OrderStatus status);

    // Конструктор копирования
    Order(const Order& other);

    // Конструктор перемещения
    Order(Order&& other) noexcept;

    // Оператор перемещения
    Order& operator=(Order&& other) noexcept;

    // Геттеры
    int get_id() const;
    double get_amount() const;
    OrderStatus get_status() const;
    std::chrono::system_clock::time_point get_order_date() const;

    // Сеттеры
    void set_status(OrderStatus new_status);
};