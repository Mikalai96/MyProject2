#include <iostream>
#include <vector>
#include <memory>
#include "Func.h"


int main()
{
    print(42); // Int
    print(3.14f); // Float
    print(std::string("Hello, World!")); // String

    
    char str[] = "Example";
    print(str);// Массив символов
        
    int arr[] = { 1, 2, 3, 4, 5 };
    print(arr, 5);// Массив целых чисел
        
    std::vector<int> vec = { 10, 20, 30 };
    print(vec);// Вектор

    // Умные указатели
    auto sharedPtr = std::make_shared<int>(100);
    auto uniquePtr = std::make_unique<double>(3.14159);

    print(sharedPtr); // Shared pointer
    print(uniquePtr); // Unique pointer

	return 0;
}

