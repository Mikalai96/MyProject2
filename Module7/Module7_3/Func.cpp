#include "Func.h"

void print(int numbr)
{
    std::cout << "Int" << numbr << std::endl;;
}
void print(float numbr)
{
    std::cout << "Int" << numbr << std::endl;;
}
void print(std::string word)
{
    std::cout << "String " << word << std::endl;;
}
void print(char* str)
{
    if (str)
    {
        std::cout << "Char array (C-string): " << str << std::endl;
    }
    else
    {
        std::cout << "Null pointer for char array" << std::endl;
    }
}

void print(int* arr, int size)
{
    if (arr)
    {
        std::cout << "Int array: ";
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Null pointer for int array" << std::endl;
    }
}

void print(const std::vector<int>& vec)
{
    std::cout << "Vector: ";
    for (const auto& elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void print(const std::shared_ptr<int>& ptr)
{
    if (ptr)
    {
        std::cout << "Shared pointer: " << *ptr << std::endl;
    }
    else
    {
        std::cout << "Null shared pointer" << std::endl;
    }
}

void print(const std::unique_ptr<double>& ptr)
{
    if (ptr)
    {
        std::cout << "Unique pointer: " << *ptr << std::endl;
    }
    else
    {
        std::cout << "Null unique pointer" << std::endl;
    }
}