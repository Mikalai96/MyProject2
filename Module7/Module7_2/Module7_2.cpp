#include <iostream>
#include <memory> 
#include "Functions.h"

int main() 
{
    int n;
    std::cout << "Enter  size of array: "; // Устанавливаем размер массива
    std::cin >> n;
    std::shared_ptr<int[]> array (new int[n]); // Создаём умный указатель shared_ptr на массив из n элементов
   
    writeElement(array.get(), n);
   
    std::weak_ptr<int[]> weakArray = array; // Создаём weak_ptr для передачи в функцию суммы
    int sum = 0;
    sumElem(weakArray,n,sum);

    int maxValue {0}, minValue{0};
    MinMax(weakArray, n, maxValue, minValue);

    return 0;
}