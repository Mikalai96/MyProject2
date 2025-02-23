#include <iostream>
#include "Calculate.h"
#include "Lambdas.h"


int main() {
    // Проверка
    calculate([&]() { division(10, 2); });  // Деление
    calculate([&]() { division(10, 0); });  // Ошибка  

    calculate([&]() { squareRoot(16); });   // Корень
    calculate([&]() { squareRoot(-4); });  // Ошибка 

    calculate([&]() { logarithm(10); });   // Логарифм
    calculate([&]() { logarithm(-1); });  // Ошибка 

    calculate([&]() { circleArea(5); });   // Площадь
    calculate([&]() { circleArea(-3); }); // Ошибка 

    return 0;
}