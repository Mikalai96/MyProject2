#include "Order.h"

// Реализация функции преобразования статуса в строку
std::string status_to_string(OrderStatus status) {
    switch (status) {
    case OrderStatus::New: return "new";
    case OrderStatus::Processing: return "processing";
    case OrderStatus::Shipped: return "shipped";
    }
    return "unknown";
}

// Реализация конструктора
Order::Order(int id, double amount, OrderStatus status)
    : id(id), amount(amount), status(status), order_date(std::chrono::system_clock::now()) {}

// Реализация конструктора копирования
Order::Order(const Order& other)
    : id(other.id), amount(other.amount), status(other.status), order_date(other.order_date) {
    std::cout << "Copy Order ID: " << other.id << '\n';
}

// Реализация конструктора перемещения
Order::Order(Order&& other) noexcept
    : id(other.id), amount(other.amount), status(other.status), order_date(other.order_date) {
    std::cout << "Move Order ID: " << other.id << '\n';
    other.id = 0;
    other.amount = 0.0;
    other.status = OrderStatus::New;
    other.order_date = std::chrono::system_clock::time_point();
}

// Реализация оператора перемещения
Order& Order::operator=(Order&& other) noexcept {
    if (this != &other) {
        std::cout << "Move assignment operator called for Order ID: " << other.id << '\n';
        id = other.id;
        amount = other.amount;
        status = other.status;
        order_date = other.order_date;

        other.id = 0;
        other.amount = 0.0;
        other.status = OrderStatus::New;
        other.order_date = std::chrono::system_clock::time_point();
    }
    return *this;
}

// Реализация геттеров
int Order::get_id() const {
    return id;
}

double Order::get_amount() const {
    return amount;
}

OrderStatus Order::get_status() const {
    return status;
}

std::chrono::system_clock::time_point Order::get_order_date() const {
    return order_date;
}

// Реализация сеттера
void Order::set_status(OrderStatus new_status) {
    status = new_status;
}