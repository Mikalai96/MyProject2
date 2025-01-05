#include "Functions.h"

// ������� ����� ������������� ������ ��� �������
void writeElement(int* array, int size)
{
    std::cout << "Enter the number\n";

    for (int i = 0; i < size; ++i)
    {
        std::cin >> array[i];
    }
}
// ������� ��� ���������� ����� ���� ��������� �������
void sumElem(const std::weak_ptr<int[]>& weakArray, int size, int& result) {
    if (auto sharedArray = weakArray.lock()) // ����������� weak_ptr � shared_ptr
    {
        result = 0;
        for (int i = 0; i < size; ++i) {
            result = result + sharedArray[i]; // ������ � ��������� ������� ����� shared_ptr
        }
    }
    else // ���� ������ ������ �� �������� (shared_ptr ��� ���������)
    {
        std::cerr << "Array is not available! \n";
        result = 0; // ������������� ��������� � 0
    }
    std::cout << "Sum: " << result << "\n";
}
// ������� ��� ���������� ������������� � ������������ �������� �������
void MinMax(const std::weak_ptr<int[]>& weakArray, int size, int& maxValue, int& minValue) {
    if (auto sharedArray = weakArray.lock()) { // ����������� weak_ptr � shared_ptr
        minValue = sharedArray[0]; // �������������� ������� ������ ���������
        maxValue = sharedArray[0]; // �������������� �������� ������ ���������

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
        minValue = 0; // ������������� �������� �� ���������
        maxValue = 0;
    }
    std::cout << "MinValue: " << minValue << " " << "MaxValue: " << maxValue << "\n";
}