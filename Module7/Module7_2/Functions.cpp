#include "Functions.h"

// Функция ввода пользователем данных для массива
void writeElement(int* array, int size)
{
    std::cout << "Enter the number\n";

    for (int i = 0; i < size; ++i)
    {
        std::cin >> array[i];
    }
}
// Функция для вычисления суммы всех элементов массива
void sumElem(const std::weak_ptr<int[]>& weakArray, int size, int& result) {
    if (auto sharedArray = weakArray.lock()) // Преобразуем weak_ptr в shared_ptr
    {
        result = 0;
        for (int i = 0; i < size; ++i) {
            result = result + sharedArray[i]; // Доступ к элементам массива через shared_ptr
        }
    }
    else // Если массив больше не доступен (shared_ptr был уничтожен)
    {
        std::cerr << "Array is not available! \n";
        result = 0; // Устанавливаем результат в 0
    }
    std::cout << "Sum: " << result << "\n";
}
// Функция для нахождения максимального и минимального элемента массива
void MinMax(const std::weak_ptr<int[]>& weakArray, int size, int& maxValue, int& minValue) {
    if (auto sharedArray = weakArray.lock()) { // Преобразуем weak_ptr в shared_ptr
        minValue = sharedArray[0]; // Инициализируем минимум первым элементом
        maxValue = sharedArray[0]; // Инициализируем максимум первым элементом

        for (int i = 1; i < size; ++i)
        {
            if (sharedArray[i] < minValue)
            {
                minValue = sharedArray[i];
            }
            if (sharedArray[i] > maxValue)
            {
                maxValue = sharedArray[i];
            }
        }
    }
    else
    {
        std::cerr << "Array is not available! \n";
        minValue = 0; // Устанавливаем значения по умолчанию
        maxValue = 0;
    }
    std::cout << "MinValue: " << minValue << " " << "MaxValue: " << maxValue << "\n";
}