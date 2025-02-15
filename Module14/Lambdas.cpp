#include "Lambdas.h"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include "Calculate.h"

// Лямбда для деления
std::function<void(double, double)> division = [](double a, double b) {
    if (b == 0) throw std::invalid_argument("Division by zero.");
    std::cout << "Result of division: " << a / b << std::endl;
    };

// Лямбда для извлечения квадратного корня
std::function<void(double)> squareRoot = [](double x) {
    if (x < 0) throw std::domain_error("Square root of negative number.");
    std::cout << "Square root: " << sqrt(x) << std::endl;
    };

// Лямбда для вычисления логарифма
std::function<void(double)> logarithm = [](double x) {
    if (x <= 0) throw InvalidLogArgument();
    std::cout << "Logarithm: " << log(x) << std::endl;
    };

// Лямбда для вычисления площади круга
std::function<void(double)> circleArea = [](double radius) {
    if (radius < 0) throw InvalidRadiusArgument();
    const double pi = 3.14;
    std::cout << "Circle area: " << pi * radius * radius << std::endl;
    };