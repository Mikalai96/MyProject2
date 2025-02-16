#include "Source.h"
// Переменные для хранения результатов
 int sumResult = 0;
 int maxResult = 0;
 int minResult = 0;

// Мьютекс для синхронизации доступа к результатам
 std::mutex resultMutex;

// Функция для вывода массива по 20 элементов в строке
void printArray(const std::vector<int>& data) {
    std::cout << "Array: " << std::endl;
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i] << " ";
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }
}

// Функция для вычисления суммы элементов массива
void calculateSum(const std::vector<int>& data) {
    int localSum = 0;
    for (int num : data) {
        localSum += num;
    }
    // Синхронизация записи результата
    std::lock_guard<std::mutex> lock(resultMutex);
    sumResult = localSum;
}

// Функция для нахождения максимального элемента массива
void findMax(const std::vector<int>& data) {
    int localMax = *std::max_element(data.begin(), data.end());
    // Синхронизация записи результата
    std::lock_guard<std::mutex> lock(resultMutex);
    maxResult = localMax;
}

// Функция для нахождения минимального элемента массива
void findMin(const std::vector<int>& data) {
    int localMin = *std::min_element(data.begin(), data.end());
    // Синхронизация записи результата
    std::lock_guard<std::mutex> lock(resultMutex);
    minResult = localMin;
}