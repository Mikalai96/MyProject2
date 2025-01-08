#include <iostream>
#include <memory> 

// Функция ввода пользователем данных для массива
void writeElement(int* array, int size);

// Функция для вычисления суммы всех элементов массива
void sumElem(const std::weak_ptr<int[]>& weakArray, int size, int& result);

// Функция для нахождения максимального и минимального элемента массива
void MinMax(const std::weak_ptr<int[]>& weakArray, int size, int& maxValue, int& minValue);