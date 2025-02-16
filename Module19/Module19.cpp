#include "Source.h"

int main() {
    // Генерация массива 
    std::vector<int> data(100);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
       for (int& num : data) {
        num = std::rand() % 100 + 1;
    }
    printArray(data); //Вывод массива
    
    // Создание потоков
    std::thread sumThread(calculateSum, std::ref(data));
    std::thread maxThread(findMax, std::ref(data));
    std::thread minThread(findMin, std::ref(data));

    // Ожидание завершения потоков
    sumThread.join();
    maxThread.join();
    minThread.join();

    // Вывод результатов
    std::cout << "Sum: " << sumResult << std::endl;
    std::cout << "Max: " << maxResult << std::endl;
    std::cout << "Min: " << minResult << std::endl;

    return 0;
}