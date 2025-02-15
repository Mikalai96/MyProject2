#pragma once
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <functional>
// ���������������� ���������� ��� ���������
class InvalidLogArgument : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid argument for logarithm: argument must be positive.";
    }
};

// ���������������� ���������� ��� �������
class InvalidRadiusArgument : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid radius: radius must be non-negative.";
    }
};
void calculate(const std::function<void()>& operation);

