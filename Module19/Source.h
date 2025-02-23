#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <random>
#include <algorithm>

extern int sumResult;
extern int maxResult;
extern int minResult;

// Мьютекс для синхронизации доступа к результатам
extern std::mutex resultMutex;

// Функция для вывода массива по 20 элементов в строке
void printArray(const std::vector<int>& data);

// Функция для вычисления суммы элементов массива
void calculateSum(const std::vector<int>& data);

// Функция для нахождения максимального элемента массива
void findMax(const std::vector<int>& data);

// Функция для нахождения минимального элемента массива
void findMin(const std::vector<int>& data);